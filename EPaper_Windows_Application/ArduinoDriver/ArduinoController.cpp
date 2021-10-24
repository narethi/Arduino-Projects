#include "pch.h"

#include "ArduinoDriver.h"
#include "ArduinoController.h"
#include "ArduinoDeviceException.h"
#include "ManagedArduinoDeviceException.h"

using namespace Arduino;
using namespace ArduinoExceptions;
using namespace Arduino::Shared::Enums;

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

void Controller::CheckDeviceState()
{
	try
	{
		arduino->CheckDeviceCommState();
	}
	catch (ArduinoDeviceException e)
	{
		throw gcnew DeviceException(e.ReadError());
	}
}

void Controller::SetMode(DisplayMode ^ selectedMode)
{
	try
	{
		if (arduino != nullptr)
		{
			//Passing the enum in from the C# layer to the managed CLI layer
			//Converts the enum to an "<error-type>" and needs to be converted
			//back to the correct enum type
			auto adjustedMode = static_cast<DisplayMode>(selectedMode);
			if (adjustedMode == DisplayMode::Text)
			{
				arduino->SetDisplayToText("This is from my managed layer");
			}
			else if (adjustedMode == DisplayMode::Blocks)
			{
				arduino->SetDisplayToBlockMode();
			}
			else if (adjustedMode == DisplayMode::Static)
			{
				arduino->SetDisplayToStaticMode();
			}
			else if (adjustedMode == DisplayMode::Checker)
			{
				arduino->SetDisplayToText("Checker Mode");
			}
			else if (adjustedMode == DisplayMode::Sleep)
			{
				arduino->SetDisplayToText("Sleep Mode");
			}
		}
	}
	catch (ArduinoDeviceException e)
	{
		throw gcnew DeviceException(e.ReadError());
	}
}