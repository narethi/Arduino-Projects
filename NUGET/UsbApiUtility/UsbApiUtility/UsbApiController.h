#pragma once

using namespace System;

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
			void CheckDeviceState();
			void SendData(System::String^ data);
			void ReadData();
	};
}


