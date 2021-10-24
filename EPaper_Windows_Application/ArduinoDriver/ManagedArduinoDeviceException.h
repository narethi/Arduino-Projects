#pragma once

#include "SerialErrorCodes.h"

using namespace System;
using namespace Arduino;

namespace ArduinoExceptions
{
	public ref class DeviceException : Exception
	{
	private:
		Shared::Enums::SerialErrorCodes^ _error;
	public:
		DeviceException(SerialErrorCode error);
		DeviceException(Shared::Enums::SerialErrorCodes^ error);
		Shared::Enums::SerialErrorCodes^ ReadError();
	};
}
