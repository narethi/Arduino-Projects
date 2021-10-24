#include "pch.h"
#include "ArduinoDeviceException.h"


ArduinoDeviceException::ArduinoDeviceException(SerialErrorCode error)
{
	_error = error;
}

SerialErrorCode ArduinoDeviceException::ReadError()
{
	return _error;
}