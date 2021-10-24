#pragma once

#include <exception>
#include "SerialErrorCodes.h"

class ArduinoDeviceException : std::exception
{
private:
	SerialErrorCode _error = SerialErrorCode::UnknownError;
public:
	ArduinoDeviceException(SerialErrorCode error);
	SerialErrorCode ReadError();
};


