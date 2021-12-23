#include "pch.h"
#include "USBDeviceException.h"

USBDeviceException::USBDeviceException(USBDeviceErrorCode error)
{
	_error = error;
}

USBDeviceErrorCode USBDeviceException::ReadError()
{
	return _error;
}