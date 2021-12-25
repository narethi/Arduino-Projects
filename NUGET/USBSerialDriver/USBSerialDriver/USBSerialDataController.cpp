#include "pch.h"
#include "USBSerialDataController.h"
#include "USBDriver.h"
#include "InteropTools.h"

using namespace InteropTools;

namespace USBSerialDriver
{
	//TODO: Add in the managed exceptions, and have these functions use and propagate the new exceptions
	USBSerialDataController::USBSerialDataController(System::String^ deviceName)
	{
		_driver = new USBDriver(Interop::MarshalString(deviceName).c_str());
	}

	USBSerialDataController::USBSerialDataController(const char* deviceName)
	{
		_driver = new USBDriver(deviceName);
	}

	USBSerialDataController::~USBSerialDataController()
	{
		delete _driver;
	}


	void USBSerialDataController::CheckDeviceState()
	{

	}

	void USBSerialDataController::SendData(System::String^ data)
	{

	}

	void USBSerialDataController::ReadData()
	{

	}
}