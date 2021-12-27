#pragma once

#include "UsbDeviceErrorCodes.h"

using System::Exception;
using System::String;

namespace UsbApiUtility
{
	public ref class UsbApiException : Exception
	{
		private:
			UsbDeviceErrorCode _error;
		public:
			UsbApiException(UsbDeviceError error);
			UsbDeviceErrorCode ReadError();
	};
}


