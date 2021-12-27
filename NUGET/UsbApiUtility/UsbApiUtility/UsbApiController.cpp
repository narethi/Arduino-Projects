#include "pch.h"
#include "UsbApiController.h"
#include "UsbDevice.h"
#include "InteropTools.h"
#include "UsbDeviceException.h"
#include "UsbApiException.h"

using namespace InteropTools;

namespace UsbApiUtility
{
	//TODO: Add in the managed exceptions, and have these functions use and propagate the new exceptions
	UsbApiController::UsbApiController(System::String^ deviceName)
	{
		try
		{
			_device = new UsbDevice(Interop::MarshalString(deviceName).c_str());
		}
		catch (UsbDeviceException e)
		{
			throw gcnew UsbApiException(e.ReadError());
		}
		
	}

	UsbApiController::UsbApiController(const char* deviceName)
	{
		try
		{
			_device = new UsbDevice(deviceName);
		}
		catch (UsbDeviceException e)
		{
			throw gcnew UsbApiException(e.ReadError());
		}
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
		auto messageString = Interop::MarshalString(data).c_str();
		auto messageLength = strlen(messageString);
		try
		{
			_device->WriteDataToDevice(messageString, messageLength);
		}
		catch (UsbDeviceException e)
		{
			throw gcnew UsbApiException(e.ReadError());
		}
	}

	void UsbApiController::ReadData()
	{

	}
}