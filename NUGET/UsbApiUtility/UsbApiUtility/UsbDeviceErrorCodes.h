#pragma once

#include "UsbDeviceErrors.h"

namespace UsbApiUtility
{
	/// <summary>
	/// For an enum to be available to C# projects a managed version in the 
	/// CLR code needs to be added
	/// </summary>
	public enum class UsbDeviceErrorCode
	{
		UnknownError = 0,
		FailedToFindDevice = 1,
		FailedToGetDeviceState = 2,
		FailedToSetDeviceState = 3,
		FailedToSetTimeout = 4,
		FailedToWriteBuffer = 5,
		FailedToReadBuffer = 6,
		FailedToFindPortSettings = 7,
		InvalidPortInfoProvided = 8
	};

	UsbDeviceErrorCode ConvertToManagedCode(UsbDeviceError code);
	UsbDeviceError ConvertToUnmanagedCode(UsbDeviceErrorCode code);
}