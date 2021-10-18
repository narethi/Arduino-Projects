#include "pch.h"

#include "ArduinoDriver.h"
#include "ArduinoController.h"
#include "ArduinoDeviceException.h"
#include "ManagedArduinoDeviceException.h"

using namespace Arduino;
using namespace ArduinoExceptions;

ArduinoDriver * arduino;

Controller::Controller()
{
	try
	{
		arduino = new ArduinoDriver();
	}
	catch(ArduinoDeviceException e)
	{
		throw gcnew DeviceException(e.ReadError());
	}
}

Controller::~Controller()
{
	delete arduino;
}

void Controller::SetMode(System::String^ selectedMode)
{
	try
	{
		if (arduino != nullptr)
		{
			if (selectedMode == "Text")
			{
				arduino->SetDisplayToText("This is from my managed layer");
			}
			else if (selectedMode == "Blocks")
			{
				arduino->SetDisplayToBlockMode();
			}
			else if (selectedMode == "Static")
			{
				arduino->SetDisplayToStaticMode();
			}
		}
	}
	catch (ArduinoDeviceException e)
	{
		throw gcnew DeviceException(e.ReadError());
	}
}