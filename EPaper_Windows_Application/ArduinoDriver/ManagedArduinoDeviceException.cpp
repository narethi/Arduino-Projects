#include "pch.h"
#include "ManagedArduinoDeviceException.h"


using namespace ArduinoExceptions;
using namespace Arduino::Shared;


Enums::SerialErrorCodes^ ConvertErrorCodes(SerialErrorCodes code)
{
	switch (code)
	{
	case SerialErrorCodes::FailedToFindDevice:
			return Enums::SerialErrorCodes::FailedToFindDevice;
		case SerialErrorCodes::FailedToGetDeviceState:
			return Enums::SerialErrorCodes::FailedToGetDeviceState;
		case SerialErrorCodes::FailedToSetDeviceState:
			return Enums::SerialErrorCodes::FailedToSetDeviceState;
		case SerialErrorCodes::FailedToSetTimeout:
			return Enums::SerialErrorCodes::FailedToSetTimeout;
		case SerialErrorCodes::FailedToWriteBuffer:
			return Enums::SerialErrorCodes::FailedToWriteBuffer;
		case SerialErrorCodes::FailedToReadBuffer:
			return Enums::SerialErrorCodes::FailedToReadBuffer;
		default:
			return Enums::SerialErrorCodes::UnknownError;
	}
}

DeviceException::DeviceException(SerialErrorCodes error)
{
	_error = ConvertErrorCodes(error);
}

DeviceException::DeviceException(Enums::SerialErrorCodes^ error)
{
	_error = error;
}

Enums::SerialErrorCodes^ DeviceException::ReadError()
{
	return _error;
}