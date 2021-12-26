#pragma once

using namespace System;

class USBInterface;

namespace USBInterfaceUtility
{
	public ref class USBInterfaceController
	{
		private: 
			USBInterface * _device;
		public:
			USBInterfaceController(System::String ^ deviceName);
			USBInterfaceController(const char * deviceName);
			~USBInterfaceController();
			void CheckDeviceState();
			void SendData(System::String^ data);
			void ReadData();
	};
}


