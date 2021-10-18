#pragma once

using namespace System;

namespace Arduino
{
	public ref class Controller
	{
	public:
		Controller();
		~Controller();
		void SetMode(System::String^ selectedMode);
		void CheckDeviceState();
	};
}
