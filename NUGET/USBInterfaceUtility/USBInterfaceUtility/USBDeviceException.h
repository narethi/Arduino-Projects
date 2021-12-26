#pragma once
#include "USBDeviceErrorCodes.h"

class USBDeviceException
{
private:
	USBDeviceErrorCode _error = USBDeviceErrorCode::UnknownError;
public:
	USBDeviceException(USBDeviceErrorCode error);
	USBDeviceErrorCode ReadError();
};

