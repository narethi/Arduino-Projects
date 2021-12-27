#include "pch.h"
#include "UsbApiException.h"

namespace UsbApiUtility
{
	UsbApiException::UsbApiException(UsbDeviceError error)
	{
		_error = ConvertToManagedCode(error);
	}

	UsbDeviceErrorCode UsbApiException::ReadError()
	{
		return _error;
	}
}