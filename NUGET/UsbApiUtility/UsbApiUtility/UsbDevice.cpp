#include "pch.h"
#include "UsbDevice.h"
#include "UsbDeviceException.h"

#include <iomanip>
#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>

#include <assert.h>
#include <iostream>

#include "WindowsDeviceHelper.h"

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

/// <summary>
/// This checks the COM device handle and then reads the device settings and returns them
/// </summary>
/// <param name="deviceHandle"></param>
/// <returns></returns>
DCB CheckDeviceCommStateAndReadParams(HANDLE deviceHandle)
{	
	if (deviceHandle == INVALID_HANDLE_VALUE)
	{
		OutputDebugString(L"\nFailed To Find Device \n");
		throw UsbDeviceException(UsbDeviceError::FailedToFindDevice);
	}

	DCB comPortSettings = { 0 };
	comPortSettings.DCBlength = sizeof(comPortSettings);

	if (!GetCommState(deviceHandle, &comPortSettings))
	{
		OutputDebugString(L"\nCould not get comm state of device \n");
		throw UsbDeviceException(UsbDeviceError::FailedToGetDeviceState);
	}

	return comPortSettings;
}

UsbDevice::UsbDevice(const char* deviceName)
{
	OutputDebugString(L"\nStarting device initialization \n");
	_deviceName = deviceName;
	InitializeHandle();
	OutputDebugString(L"\nCompleted device initialization \n");
}

UsbDevice::~UsbDevice()
{
	CloseHandle(ReadHandle(_deviceHandle));
}

bool UsbDevice::InitializeHandle()
{
	auto deviceName = std::string(_deviceName);
	auto deviceNameWideString = std::wstring(deviceName.begin(), deviceName.end()); //For some reason I have to construct the wide string first, I will correct this later
	OutputDebugString(L"\nlooking for device: ");
	OutputDebugString(deviceNameWideString.c_str());
	OutputDebugString(L"\n");
	auto tempDeviceHandle = CreateFile(deviceNameWideString.c_str(), GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	
	DCB portParams = CheckDeviceCommStateAndReadParams(tempDeviceHandle);

	//Read the port settings 
	auto portSettings = WindowsDeviceHelper::GetPortSettings(_deviceName);

	portParams.BaudRate = static_cast<DWORD>(portSettings.BaudRate);
	portParams.ByteSize = static_cast<BYTE>(portSettings.DataBits);
	portParams.StopBits = static_cast<BYTE>(portSettings.StopBits);
	portParams.Parity = static_cast<BYTE>(portSettings.Parity);

	if (!SetCommState(tempDeviceHandle, &portParams))
	{
		OutputDebugString(L"\nCould not update the comm state of device \n");
		throw UsbDeviceException(UsbDeviceError::FailedToSetDeviceState);
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
		throw UsbDeviceException(UsbDeviceError::FailedToSetTimeout);
	}

	_deviceHandle = new HANDLE(tempDeviceHandle);

	return true;
}

void UsbDevice::CheckDeviceCommState()
{
	CheckDeviceCommStateAndReadParams(ReadHandle(_deviceHandle));
}

void UsbDevice::WriteDataToDevice(const char* data, size_t dataSize)
{
	DWORD dwWriteBuffer = 0;
	CheckDeviceCommState();
	auto deviceHandle = ReadHandle(_deviceHandle);
	if (!WriteFile(deviceHandle, data, static_cast<DWORD>(dataSize), &dwWriteBuffer, NULL))
	{
		OutputDebugString(L"\nFailed to write to the USB Serial buffer \n");
		throw UsbDeviceException(UsbDeviceError::FailedToWriteBuffer);
	}
}

bool UsbDevice::ReadDataFromSerialBuffer(const char*& data, size_t& retrievedData)
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
		OutputDebugString(L"\nFailed to read from the USB Serial buffer \n");
		throw UsbDeviceException(UsbDeviceError::FailedToReadBuffer);
	}
	else if (dwBytesRead == 0)
	{
		//nothing read nothing to process
		return false;
	}

#if defined _DEBUG

	std::wostringstream oss;  // uses wchar_t characters (UNICODE) this is to be able to debug out

	for (DWORD i = 0; i < dwBytesRead; i++)
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