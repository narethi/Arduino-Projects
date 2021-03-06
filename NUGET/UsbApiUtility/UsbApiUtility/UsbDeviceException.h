#pragma once
#include "UsbDeviceErrors.h"

class UsbDeviceException
{
private:
	UsbDeviceError _error = UsbDeviceError::UnknownError;
public:
	UsbDeviceException(UsbDeviceError error);
	DRIVER_API UsbDeviceError ReadError();
};

