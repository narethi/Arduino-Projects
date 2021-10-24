#include "pch.h"
#include "ManagedArduinoDeviceException.h"


using namespace ArduinoExceptions;
using namespace Arduino::Shared;


Enums::SerialErrorCodes^ ConvertErrorCodes(SerialErrorCode code)
{
	switch (code)
	{
	case SerialErrorCode::FailedToFindDevice:
			return Enums::SerialErrorCodes::FailedToFindDevice;
		case SerialErrorCode::FailedToGetDeviceState:
			return Enums::SerialErrorCodes::FailedToGetDeviceState;
		case SerialErrorCode::FailedToSetDeviceState:
			return Enums::SerialErrorCodes::FailedToSetDeviceState;
		case SerialErrorCode::FailedToSetTimeout:
			return Enums::SerialErrorCodes::FailedToSetTimeout;
		case SerialErrorCode::FailedToWriteBuffer:
			return Enums::SerialErrorCodes::FailedToWriteBuffer;
		case SerialErrorCode::FailedToReadBuffer:
			return Enums::SerialErrorCodes::FailedToReadBuffer;
		default:
			return Enums::SerialErrorCodes::UnknownError;
	}
}

DeviceException::DeviceException(SerialErrorCode error)
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