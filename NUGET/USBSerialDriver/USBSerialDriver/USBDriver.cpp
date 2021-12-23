#include "pch.h"
#include "USBDriver.h"
#include "USBDeviceException.h"

#include <iomanip>
#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>

#include <assert.h>
#include <iostream>

//This is an arbitrary value and in reality could be much larger or much smaller based on what is expected to be written to the buffer from an outside device
const int MAX_ARRAY_SIZE = 1024;

/// <summary>
/// This is a convience function to convert the void pointer handle to be a windows handle to the device document
/// </summary>
/// <param name="handle"></param>
/// <returns></returns>
HANDLE ReadHandle(void* handle)
{
	return *(static_cast<HANDLE*>(handle));
}

USBDriver::USBDriver(const char* deviceName)
{
	std::cout << "Starting driver initialization" << std::endl;
	_deviceName = deviceName;
	InitializeHandle();
	std::cout << "Completed driver initialization" << std::endl;
}

USBDriver::~USBDriver()
{
	CloseHandle(ReadHandle(_deviceHandle));
}

bool USBDriver::InitializeHandle()
{
	auto deviceName = std::string(_deviceName);
	auto deviceNameWideString = std::wstring(deviceName.begin(), deviceName.end()); //For some reason I have to construct the wide string first, I will correct this later
	OutputDebugString(L"\n");
	OutputDebugString(L"looking for device: ");
	OutputDebugString(deviceNameWideString.c_str());
	OutputDebugString(L"\n");
	auto tempDeviceHandle = CreateFile(deviceNameWideString.c_str(), GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (tempDeviceHandle == INVALID_HANDLE_VALUE)
	{
		OutputDebugString(L"\nFailed To Find Device \n");
		throw USBDeviceException(USBDeviceErrorCode::FailedToFindDevice);
	}

	DCB dcbSerialParams = { 0 };

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
	if (!GetCommState(tempDeviceHandle, &dcbSerialParams))
	{
		OutputDebugString(L"\nCould not get comm state of device \n");
		throw USBDeviceException(USBDeviceErrorCode::FailedToGetDeviceState);
	}

	dcbSerialParams.BaudRate = CBR_9600;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;

	if (!SetCommState(tempDeviceHandle, &dcbSerialParams))
	{
		OutputDebugString(L"\nCould not update the comm state of device \n");
		throw USBDeviceException(USBDeviceErrorCode::FailedToSetDeviceState);
	}

	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;

	if (!SetCommTimeouts(tempDeviceHandle, &timeouts))
	{
		OutputDebugString(L"\nCould not set comm timeout for the device \n");
		throw USBDeviceException(USBDeviceErrorCode::FailedToSetTimeout);
	}

	_deviceHandle = new HANDLE(tempDeviceHandle);

	return true;
}

void USBDriver::CheckDeviceCommState()
{
	auto deviceHandle = ReadHandle(_deviceHandle);
	if (deviceHandle == INVALID_HANDLE_VALUE)
	{
		throw USBDeviceException(USBDeviceErrorCode::FailedToFindDevice);
	}

	DCB dcbArduinoSerialParams = { 0 };
	dcbArduinoSerialParams.DCBlength = sizeof(dcbArduinoSerialParams);

	if (!GetCommState(deviceHandle, &dcbArduinoSerialParams))
	{
		throw USBDeviceException(USBDeviceErrorCode::FailedToGetDeviceState);
	}
}

void USBDriver::WriteDataToDevice(const char* data, size_t dataSize)
{
	DWORD dwWriteBuffer = 0;
	CheckDeviceCommState();
	auto deviceHandle = ReadHandle(_deviceHandle);
	if (!WriteFile(deviceHandle, data, dataSize, &dwWriteBuffer, NULL))
	{
		throw USBDeviceException(USBDeviceErrorCode::FailedToWriteBuffer);
	}
}

bool USBDriver::ReadDataFromSerialBuffer(const char*& data, size_t& retrievedData)
{
	OutputDebugString(L"Reading from the Serial Bus\n");
	char outputBuffer[MAX_ARRAY_SIZE];
	auto deviceHandle = ReadHandle(_deviceHandle);
	CheckDeviceCommState();
	for (auto i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		outputBuffer[i] = '\0';
	}

	DWORD dwBytesRead = 0;
	if (!ReadFile(deviceHandle, outputBuffer, MAX_ARRAY_SIZE, &dwBytesRead, NULL))
	{
		throw USBDeviceException(USBDeviceErrorCode::FailedToReadBuffer);
	}
	else if (dwBytesRead == 0)
	{
		//nothing read nothing to process
		return false;
	}

#if defined _DEBUG

	std::wostringstream oss;  // uses wchar_t characters (UNICODE) this is to be able to debug out

	for (int i = 0; i < dwBytesRead; i++)
	{
		oss << std::hex << (unsigned int)(outputBuffer[i]) << " ";
	}

	OutputDebugString(L"Data Recieved\n");
	OutputDebugString(oss.str().c_str());
	OutputDebugString(L"\n");

#endif

	data = outputBuffer;
	retrievedData = dwBytesRead;

	return true;
}