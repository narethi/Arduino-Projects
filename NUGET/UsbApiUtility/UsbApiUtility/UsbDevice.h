#pragma once

#include "pch.h"

class UsbDevice
{
private:
	//This is a handle to the device document, this is a void pointer as the HANDLE library is a winnt object and is not aviable to be used in CLR projects
	//Setting this as a void pointer allows the handle to be stored as a member of this class so that multiple Drivers can be included
	//In a single application, the naive approach was to include the HANDLE object as a global in the USBDriver.cpp file, but that limits
	//the number of devices that can be viewed by the application using this library
	void* _deviceHandle;
	const char* _deviceName;
	bool InitializeHandle();
public:
	DRIVER_API UsbDevice(const char* deviceName);
	DRIVER_API ~UsbDevice();
	DRIVER_API void CheckDeviceCommState();
	DRIVER_API void WriteDataToDevice(const char* data, size_t dataSize);
	DRIVER_API bool ReadDataFromSerialBuffer(const char*& data, size_t& retrievedData);
};