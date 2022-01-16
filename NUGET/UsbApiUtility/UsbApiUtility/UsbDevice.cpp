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
#include "ErrorInterpreter.h"

//This is an arbitrary value and in reality could be much larger or much smaller based on what is expected to be written to the buffer from an outside device
const int MAX_ARRAY_SIZE = 1024;

/// This is a region for functions that are local to this CPP file not exposed to the rest of the dll
#pragma region Local Functions

/// <summary>
/// This is a convience function to convert the void pointer handle to be a windows handle to the device document
/// </summary>
/// <param name="handle"></param>
/// <returns></returns>
HANDLE ReadHandle(void* handle)
{
	if (handle == nullptr)
	{
		throw UsbDeviceException(UsbDeviceError::NoConnectedDevice);
	}
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

/// <summary>
/// This is a convienence function used to more easily convert to UNICODE, primarily used for DEBUG outpur
/// </summary>
/// <param name="input">This is the string to be converted</param>
/// <returns>A valid wide string that can be used by UNICODE functions</returns>
const wchar_t* ConvertToWideChar(const char* input)
{
	std::wostringstream oss;  // uses wchar_t characters (UNICODE) this is to be able to debug out
	auto inputLength = strlen(input);
	for (DWORD i = 0; i < inputLength; i++)
	{
		oss << std::hex << (unsigned int)(input[i]) << " ";
	}

	return oss.str().c_str();
}

#pragma endregion

bool UsbDevice::ConnectDevice()
{
	if (!_deviceIsConnected)
	{
		return InitializeHandle();
	}
	throw UsbDeviceException(UsbDeviceError::DeviceStillConnected);
}

bool UsbDevice::ChangeDeviceName(const char* deviceName, bool connectNewDevice = true)
{
	try
	{
		DisconnectDevice();
		_deviceName = deviceName;
		if (connectNewDevice)
		{
			return InitializeHandle();
		}
		return true;
	}
	catch (UsbDeviceException e)
	{
		OutputDebugString(L"\nFailed to write to the USB Serial buffer\nError:");
		OutputDebugString(ConvertToWideChar(ErrorInterpreter::ConvertErrorCodeToString(e.ReadError())));
		return false;
	}
}

void UsbDevice::DisconnectDevice()
{
	if (_deviceIsConnected)
	{
		CloseHandle(ReadHandle(_deviceHandle));
		_deviceHandle = nullptr;
		_deviceIsConnected = false;
	}
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
	DisconnectDevice();
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
	_deviceIsConnected = true;
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

	if (!WriteFile(deviceHandle, data,static_cast<DWORD>(dataSize), &dwWriteBuffer, NULL))
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

	OutputDebugString(L"Data Recieved\n");
	OutputDebugString(ConvertToWideChar(outputBuffer));
	OutputDebugString(L"\n");

#endif

	data = outputBuffer;
	retrievedData = dwBytesRead;

	return true;
}