#pragma once

#include "UsbDeviceErrors.h"

namespace UsbApiUtility
{
	public enum class UsbDeviceConnectionState
	{
		UnknownConnectionState,
		Connected = 0,
		Disconnected,
		InvalidDeviceParams
	};

	UsbDeviceConnectionState ReadConnectionStateFromDeviceState(UsbDeviceError error);
}