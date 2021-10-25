#include "pch.h"

#include "ArduinoDriver.h"
#include "ArduinoController.h"
#include "ArduinoDeviceException.h"
#include "ManagedArduinoDeviceException.h"

using namespace Arduino;
using namespace ArduinoExceptions;
using namespace Arduino::Shared::Enums;

ArduinoDriver * arduino;

/// <summary>
/// This is lifted from the microsoft documentation for how to marshal strings (I can never remember how to make ANSI strings)
/// https://docs.microsoft.com/en-us/cpp/dotnet/how-to-convert-system-string-to-standard-string?view=msvc-160
/// </summary>
/// <param name="s"></param>
/// <param name="os"></param>
void MarshalString(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

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

void Controller::SetMode(DisplayMode ^ selectedMode, ...array<Object^>^ args)
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
				std::string outputData = "";
				if (args->Length > 0)
				{
					MarshalString(static_cast<System::String^>(args[0]), outputData);
				}
				arduino->SetDisplayToText(outputData);
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