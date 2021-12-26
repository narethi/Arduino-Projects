#include "pch.h"
#include "USBInterfaceController.h"
#include "USBInterface.h"
#include "InteropTools.h"

using namespace InteropTools;

namespace USBInterfaceUtility
{
	//TODO: Add in the managed exceptions, and have these functions use and propagate the new exceptions
	USBInterfaceController::USBInterfaceController(System::String^ deviceName)
	{
		_device = new USBInterface(Interop::MarshalString(deviceName).c_str());
	}

	USBInterfaceController::USBInterfaceController(const char* deviceName)
	{
		_device = new USBInterface(deviceName);
	}

	USBInterfaceController::~USBInterfaceController()
	{
		delete _device;
	}

	void USBInterfaceController::CheckDeviceState()
	{

	}

	void USBInterfaceController::SendData(System::String^ data)
	{

	}

	void USBInterfaceController::ReadData()
	{

	}
}