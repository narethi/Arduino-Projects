#include "pch.h"
#include "WindowsDeviceHelper.h"
#include "USBDeviceException.h"

//A struct was made to carry the device info, just as a convience, so we don't need to include
//any of the windows stuff in the header meaning that this class can be used by CLI\C++ classes
//Windows.h doesn't work well with the managed heap
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <sstream>

/// <summary>
/// This will convert the port setting parity value to the correct enum value
/// NOTE this is kept out of the class, inorder to keep the Windows.h out inorder
/// to enable the use in the managed end of the library
/// </summary>
/// <param name="parityValue">This is the character stored in the registry value that represents parity</param>
/// <returns>The corresponding enum value to be stored in the Port Settings data</returns>
PortParityCode ReadParityFromChar(char parityValue)
{
	auto parityCharacter = std::toupper(parityValue);
	switch (parityCharacter)
	{
	case 'N':
		return PortParityCode::NoParity;
	case 'O':
		return PortParityCode::OddParity;
	case 'E':
		return PortParityCode::EvenParity;
	case 'M':
		return PortParityCode::MarkParity;
	case 'S':
		return PortParityCode::SpaceParity;
	default:
		return PortParityCode::UnknownParity;
	}
}

/// <summary>
/// This will convert the port setting values from the registry key to the Port Settings struct
/// NOTE this is kept out of the class, inorder to keep the Windows.h out inorder
/// to enable the use in the managed end of the library
/// </summary>
/// <param name="registryData">This is the string to be processed</param>
/// <param name="writtenBytes">Number of bytes that have been written to the registry data</param>
/// <returns>Filled out ports settings structure</returns>
PortSettings ProcessPortSettingsRegistryKey(PWCHAR registryData, DWORD writtenBytes)
{
	std::stringstream dataStream;

	for (DWORD i = 0; i < writtenBytes; i++)
	{
		dataStream << (char)registryData[i];
	}

	std::string dataToProcess = "";
	auto currentIndex = 0;

	auto data = PortSettings();

	while (getline(dataStream, dataToProcess, ','))
	{
		switch (currentIndex)
		{
		case 0:
			data.BaudRate = std::atoi(dataToProcess.c_str());
			break;
		case 1:
			data.Parity = ReadParityFromChar(dataToProcess[0]);
			break;
		case 2:
			data.DataBits = dataToProcess[0];
			break;
		case 3:
			switch (dataToProcess[0])
			{
			case '1':
				data.StopBits = ONESTOPBIT;
				break;
			case '2':
				data.StopBits = TWOSTOPBITS;
				break;
			default:
				//If the its not valid, set it to -1 to make the rest of the system throw an SEH exception
				data.StopBits = -1;
			}

			break;
		}
		currentIndex++;
	}

	return data;
}

/// <summary>
/// This reads the registry information that contain the information about the COM device
/// </summary>
/// <param name="deviceName"></param>
/// <returns></returns>
PortSettings WindowsDeviceHelper::GetPortSettings(const char* deviceName)
{
	HKEY portsRegistryKey;
	auto foundKey = RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Ports", 0, KEY_READ, &portsRegistryKey);
	if (foundKey == ERROR_SUCCESS)
	{
		//28 is the largest that an entry can be in the key given the parameters, use 32 incase a change is made in newer versions of windows
		DWORD readDataLen = 32;
		auto readBuffer = new WCHAR[readDataLen];

		auto deviceNameLength = strlen(deviceName) + 1;
		std::wstring tempDeviceName;
		mbstowcs(&tempDeviceName[0], deviceName, deviceNameLength);

		std::wstring adjustedDeviceName;
		adjustedDeviceName.append(tempDeviceName.c_str());
		adjustedDeviceName.append(L":");
		
		auto readValue = RegQueryValueEx(portsRegistryKey, adjustedDeviceName.c_str(), NULL, NULL, reinterpret_cast<BYTE*>(readBuffer), &readDataLen);
		if (readValue != ERROR_SUCCESS)
		{
			//There are some none error codes like ERROR_READ_MORE (234) but port settings can't be more more than 32 values 
			RegCloseKey(portsRegistryKey);
			delete[] readBuffer;
			throw USBDeviceException(USBDeviceErrorCode::FailedToFindPortSettings);
		}

		auto data = ProcessPortSettingsRegistryKey(readBuffer, readDataLen);

		RegCloseKey(portsRegistryKey);
		delete[] readBuffer;

		return data;
	}
	
	return PortSettings();
}