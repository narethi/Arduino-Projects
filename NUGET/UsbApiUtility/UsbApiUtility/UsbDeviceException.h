#pragma once
#include "UsbDeviceErrorCodes.h"

class UsbDeviceException
{
private:
	UsbDeviceErrorCode _error = UsbDeviceErrorCode::UnknownError;
public:
	UsbDeviceException(UsbDeviceErrorCode error);
	UsbDeviceErrorCode ReadError();
};

