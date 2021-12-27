#include "pch.h"
#include "UsbDeviceException.h"

UsbDeviceException::UsbDeviceException(UsbDeviceError error)
{
	_error = error;
}

UsbDeviceError UsbDeviceException::ReadError()
{
	return _error;
}