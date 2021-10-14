#pragma once

#include "SerialErrorCodes.h"

using namespace System;
using namespace Arduino::Shared;

namespace ArduinoExceptions
{
	public ref class DeviceException : Exception
	{
	private:
		Enums::SerialErrorCodes^ _error;
	public:
		DeviceException(SerialErrorCodes error);
		Enums::SerialErrorCodes^ ReadError();
	};
}
