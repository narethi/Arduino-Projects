#pragma once

using namespace System;

namespace Arduino
{
	public ref class Controller
	{
	public:
		Controller();
		~Controller();
		// TODO: Add your methods for this class here.
		void SetMode(System::String^ selectedMode);
	};
}
