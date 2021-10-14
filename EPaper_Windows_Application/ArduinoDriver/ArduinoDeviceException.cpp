#include "pch.h"
#include "ArduinoDeviceException.h"


ArduinoDeviceException::ArduinoDeviceException(SerialErrorCodes error)
{
	_error = error;
}

SerialErrorCodes ArduinoDeviceException::ReadError()
{
	return _error;
}