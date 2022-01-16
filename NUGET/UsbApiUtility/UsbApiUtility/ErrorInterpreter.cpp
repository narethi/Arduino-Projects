#include "pch.h"
#include "ErrorInterpreter.h"

const char* ErrorInterpreter::ConvertErrorCodeToString(UsbDeviceError errorCode)
{
	switch (errorCode)
	{
		case UsbDeviceError::FailedToFindDevice:
			return "No Device with the requested name exists";
		case UsbDeviceError::FailedToGetDeviceState:
			return "Failed to read the COM Port information for the current device instance";
		case UsbDeviceError::FailedToSetDeviceState:
			return "Failed to update the COM Port settings for current device instance";
		case UsbDeviceError::FailedToSetTimeout:
			return "Failed to set the timeout for the COM Port";
		case UsbDeviceError::FailedToWriteBuffer:
			return "Failed to write data from the connected COM Port";
		case UsbDeviceError::FailedToReadBuffer:
			return "Failed to read data from the connected COM Port";
		case UsbDeviceError::FailedToFindPortSettings:
			return "Could not find any information on this COM Port in this machine's registry";
		case UsbDeviceError::InvalidPortInfoProvided:
			return "Requested COM Port was unable to be found";
		case UsbDeviceError::NoConnectedDevice:
			return "No COM Port is currently connected";
		case UsbDeviceError::DeviceStillConnected:
			return "Cannot connect to device, its already connected";
		case UsbDeviceError::UnknownError:
		default:
			return "Unknown Error";
	}
}