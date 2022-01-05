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

	UsbDeviceConnectionState UsbApiController::CheckDeviceState()
	{
		try
		{
			_device->CheckDeviceCommState();
		}
		catch (UsbDeviceException e)
		{
			return ReadConnectionStateFromDeviceState(e.ReadError());
		}
		return UsbDeviceConnectionState::Connected;
	}

	void UsbApiController::SendData(List<Byte>^ data)
	{
		std::string dataString = "";
		for each (auto entry in data)
		{
			dataString += entry;
		}

		auto messageString = dataString.c_str();//Interop::MarshalString(data).c_str();
		auto messageLength = data->Count;
		try
		{
			_device->WriteDataToDevice(messageString, messageLength);
		}
		catch (UsbDeviceException e)
		{
			throw gcnew UsbApiException(e.ReadError());
		}
	}

	List<Byte>^ UsbApiController::ReadData()
	{
		try
		{
			const char* data;
			size_t dataSize;
			_device->ReadDataFromSerialBuffer(data, dataSize);
			auto retVal = gcnew List<Byte>();
			for (size_t i = 0; i < dataSize; i++)
			{
				retVal->Add(data[i]);
			}
			return retVal;
		}
		catch (UsbDeviceException e)
		{
			throw gcnew UsbApiException(e.ReadError());
		}
	}
}