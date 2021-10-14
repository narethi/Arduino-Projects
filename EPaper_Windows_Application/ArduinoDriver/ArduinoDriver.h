#pragma once

using namespace System;

namespace ArduinoDriver 
{
	public ref class Driver
	{
	public:
		Driver();
		~Driver();
		// TODO: Add your methods for this class here.
		void SetMode(System::String^ selectedMode);
	};
}
