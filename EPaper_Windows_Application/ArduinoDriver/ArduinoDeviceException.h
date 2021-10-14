#pragma once

#include <exception>
#include "SerialErrorCodes.h"

class ArduinoDeviceException : std::exception
{
private:
	SerialErrorCodes _error = SerialErrorCodes::UnknownError;
public:
	ArduinoDeviceException(SerialErrorCodes error);
	SerialErrorCodes ReadError();
};


