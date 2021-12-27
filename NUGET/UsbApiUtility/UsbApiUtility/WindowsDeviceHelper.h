#pragma once

#include "PortSettings.h"

/// <summary>
/// This helper class is used to read the windows device properties to get the required hardware info
/// From a device name, this information can then be used to set the configured device properties
/// Automatically so that the library doesn't need to
/// </summary>
class WindowsDeviceHelper
{
	private:
		//Hide the default constructor
		WindowsDeviceHelper();
	public:
		static PortSettings GetPortSettings(const char* deviceName);
};