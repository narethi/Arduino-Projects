#pragma once

#include "UsbDeviceConnectionState.h"

using namespace System;
using namespace System::Collections::Generic;

class UsbDevice;

namespace UsbApiUtility
{
	public ref class UsbApiController
	{
		private: 
			UsbDevice* _device;
		public:
			UsbApiController(System::String ^ deviceName);
			UsbApiController(const char * deviceName);
			~UsbApiController();
			UsbDeviceConnectionState CheckDeviceState();
			void SendData(List<Byte>^ data);
			List<Byte>^ ReadData();
	};
}


