#include "pch.h"

#include "ArduinoDriver.h"
#include "ArduinoController.h"
#include "ArduinoDeviceException.h"
#include "ManagedArduinoDeviceException.h"

using namespace ArduinoDriver;
using namespace ArduinoExceptions;

ArduinoController * controller;

Driver::Driver()
{
	try
	{
		controller = new ArduinoController();
	}
	catch(ArduinoDeviceException e)
	{
		throw gcnew DeviceException(e.ReadError());
	}
}

Driver::~Driver()
{
	delete controller;
}

void Driver::SetMode(System::String^ selectedMode)
{
	if (controller != nullptr)
	{
		if (selectedMode == "Text")
		{
			controller->SetDisplayToText("This is from my managed layer");
		}
		else if (selectedMode == "Blocks")
		{
			controller->SetDisplayToBlockMode();
		}
		else if (selectedMode == "Static")
		{
			controller->SetDisplayToStaticMode();
		}
	}
}