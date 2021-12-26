#include "pch.h"
#include "UsbDeviceException.h"

UsbDeviceException::UsbDeviceException(UsbDeviceErrorCode error)
{
	_error = error;
}

UsbDeviceErrorCode UsbDeviceException::ReadError()
{
	return _error;
}