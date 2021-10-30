#include "pch.h"
#include "ArduinoDriver.h"

#include "SerialErrorCodes.h"
#include "ArduinoDeviceException.h"

#include <string>
#include <sstream>
#include <iomanip>
#include <Windows.h>

const int MAX_ARRAY_SIZE = 1024;
HANDLE ArduinoHandle;

ArduinoDriver::ArduinoDriver()
{
	Initialize();
}

ArduinoDriver::~ArduinoDriver()
{
	CloseHandle(ArduinoHandle);
}

bool ArduinoDriver::Initialize()
{
	ArduinoHandle = CreateFile(L"COM8", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (ArduinoHandle == INVALID_HANDLE_VALUE)
	{
		throw ArduinoDeviceException(SerialErrorCode::FailedToFindDevice);
	}

	DCB dcbArduinoSerialParams = { 0 };

	dcbArduinoSerialParams.DCBlength = sizeof(dcbArduinoSerialParams);
	if (!GetCommState(ArduinoHandle, &dcbArduinoSerialParams))
	{
		throw ArduinoDeviceException(SerialErrorCode::FailedToGetDeviceState);
	}

	dcbArduinoSerialParams.BaudRate = CBR_9600;
	dcbArduinoSerialParams.ByteSize = 8;
	dcbArduinoSerialParams.StopBits = ONESTOPBIT;
	dcbArduinoSerialParams.Parity = NOPARITY;

	if (!SetCommState(ArduinoHandle, &dcbArduinoSerialParams))
	{
		throw ArduinoDeviceException(SerialErrorCode::FailedToSetDeviceState);
	}

	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;

	if (!SetCommTimeouts(ArduinoHandle, &timeouts))
	{
		throw ArduinoDeviceException(SerialErrorCode::FailedToSetTimeout);
	}

	return true;
}

void ArduinoDriver::CheckDeviceCommState()
{
	if (ArduinoHandle == INVALID_HANDLE_VALUE)
	{
		throw ArduinoDeviceException(SerialErrorCode::FailedToFindDevice);
	}

	DCB dcbArduinoSerialParams = { 0 };

	dcbArduinoSerialParams.DCBlength = sizeof(dcbArduinoSerialParams);
	if (!GetCommState(ArduinoHandle, &dcbArduinoSerialParams))
	{
		throw ArduinoDeviceException(SerialErrorCode::FailedToGetDeviceState);
	}
}

void ArduinoDriver::SetDisplayToBlockMode(bool isVertical)
{
	std::string serializedData;
	serializedData += static_cast<char*>(static_cast<void*>(&isVertical));
	RunCommand(ArduinoSerialCommand::RunBlocks, 1, serializedData);
}

void ArduinoDriver::SetDisplayToStaticMode(int blockSize)
{
	std::string serializedBlockSize;
	serializedBlockSize += static_cast<char>(blockSize);
	RunCommand(ArduinoSerialCommand::RunStatic, 1, serializedBlockSize);
}

void ArduinoDriver::SetDisplayToCheckerMode(int blockSize)
{
	std::string serializedBlockSize;
	serializedBlockSize += static_cast<char>(blockSize);
	RunCommand(ArduinoSerialCommand::RunChecker, 1, serializedBlockSize);
}

void ArduinoDriver::SetDisplayToSleepMode()
{
	RunCommand(ArduinoSerialCommand::RunSleep, 0);
}

void ArduinoDriver::SetDisplayToText(std::string text)
{
	RunCommand(ArduinoSerialCommand::RunText, 1, text);
}

void ArduinoDriver::RunCommand(ArduinoSerialCommand command, int argumentCount, ...)
{
	//Read the command
	std::string data = "";
	data += static_cast<int>(command);
	if (argumentCount > 0)
	{
		va_list argumentList;
		va_start(argumentList, argumentCount);
		data += va_arg(argumentList, std::string);
	}

	//Determine how to process the VA based on the command parameter
	//Combine the command and the VA formatted for transmit
	//Write to serial bus
	WriteToSerialBus(data);
}

void ArduinoDriver::WriteToSerialBus(std::string serialData)
{
	DWORD dwWriteBuffer = 0;
	CheckDeviceCommState();
	if (!WriteFile(ArduinoHandle, serialData.c_str(), serialData.size(), &dwWriteBuffer, NULL))
	{
		throw ArduinoDeviceException(SerialErrorCode::FailedToWriteBuffer);
	}
}

void ArduinoDriver::ReadFromSerialBus()
{
	char szBuff[MAX_ARRAY_SIZE];
	DWORD dwBytesRead = 0;
	if (!ReadFile(ArduinoHandle, szBuff, MAX_ARRAY_SIZE, &dwBytesRead, NULL))
	{
		throw ArduinoDeviceException(SerialErrorCode::FailedToReadBuffer);
	}

	std::wostringstream oss;  // uses wchar_t characters (UNICODE)
	oss << "0x" << std::hex << std::setw(8) << std::right << std::setfill(L'0') << dwBytesRead;
	LPCWSTR pc = oss.str().c_str();
	OutputDebugString(pc);
	OutputDebugString(L"\n");
}