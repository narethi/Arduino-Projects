#pragma once

using namespace System;
using namespace Arduino::Shared::Enums;

namespace Arduino
{
	public ref class Controller
	{
	public:
		Controller();
		~Controller();
		void SetMode(DisplayMode ^ selectedMode, ...array<Object^> ^args);
		void CheckDeviceState();
	};
}
