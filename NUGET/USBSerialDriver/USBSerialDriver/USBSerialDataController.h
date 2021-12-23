#pragma once

using namespace System;

class USBDriver;

namespace USBSerialDriver
{
	public ref class USBSerialDataController
	{
		private: 
			USBDriver * _driver;
		public:
			USBSerialDataController(System::String ^ deviceName);
			USBSerialDataController(const char * deviceName);
			~USBSerialDataController();
			void CheckDeviceState();
			void SendData(System::String^ data);
			void ReadData();
	};
}


