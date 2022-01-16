#pragma once

#include "pch.h"
#include "UsbDeviceErrors.h"

class ErrorInterpreter
{
public:
	static const char* ConvertErrorCodeToString(UsbDeviceError errorCode);
};

