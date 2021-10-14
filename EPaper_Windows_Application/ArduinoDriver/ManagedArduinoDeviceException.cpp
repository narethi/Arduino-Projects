#include "pch.h"
#include "ManagedArduinoDeviceException.h"

using namespace ArduinoExceptions;
using namespace Arduino::Shared;


Enums::SerialErrorCodes^ ConvertErrorCodes(SerialErrorCodes code)
{
	switch (code)
	{
		case FailedToFindDevice:
			return Enums::SerialErrorCodes::FailedToFindDevice;
		case FailedToGetDeviceState:
			return Enums::SerialErrorCodes::FailedToGetDeviceState;
		case FailedToSetDeviceState:
			return Enums::SerialErrorCodes::FailedToSetDeviceState;
		case FailedToSetTimeout:
			return Enums::SerialErrorCodes::FailedToSetTimeout;
		case FailedToWriteBuffer:
			return Enums::SerialErrorCodes::FailedToWriteBuffer;
		case FailedToReadBuffer:
			return Enums::SerialErrorCodes::FailedToReadBuffer;
		default:
			return Enums::SerialErrorCodes::UnknownError;
	}
}

DeviceException::DeviceException(SerialErrorCodes error)
{
	_error = ConvertErrorCodes(error);
}

Enums::SerialErrorCodes^ DeviceException::ReadError()
{
	return _error;
}