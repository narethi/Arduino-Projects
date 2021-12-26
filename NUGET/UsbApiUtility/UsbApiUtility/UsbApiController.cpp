#include "pch.h"
#include "UsbApiController.h"
#include "UsbDevice.h"
#include "InteropTools.h"

using namespace InteropTools;

namespace UsbApiUtility
{
	//TODO: Add in the managed exceptions, and have these functions use and propagate the new exceptions
	UsbApiController::UsbApiController(System::String^ deviceName)
	{
		_device = new UsbDevice(Interop::MarshalString(deviceName).c_str());
	}

	UsbApiController::UsbApiController(const char* deviceName)
	{
		_device = new UsbDevice(deviceName);
	}

	UsbApiController::~UsbApiController()
	{
		delete _device;
	}

	void UsbApiController::CheckDeviceState()
	{

	}

	void UsbApiController::SendData(System::String^ data)
	{

	}

	void UsbApiController::ReadData()
	{

	}
}