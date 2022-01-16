#include "pch.h"
#include "UsbDeviceConnectionState.h"

namespace UsbApiUtility
{

	UsbDeviceConnectionState ReadConnectionStateFromDeviceState(UsbDeviceError error)
	{
		switch (error)
		{
		case UsbDeviceError::NoConnectedDevice:
		case UsbDeviceError::FailedToFindDevice:
			return UsbDeviceConnectionState::Disconnected;
		case UsbDeviceError::FailedToGetDeviceState:
			return UsbDeviceConnectionState::InvalidDeviceParams;
		case UsbDeviceError::FailedToSetDeviceState:
		case UsbDeviceError::FailedToSetTimeout:
		case UsbDeviceError::FailedToWriteBuffer:
		case UsbDeviceError::FailedToReadBuffer:
		case UsbDeviceError::FailedToFindPortSettings:
		case UsbDeviceError::InvalidPortInfoProvided:
		case UsbDeviceError::UnknownError:
		default:
			return UsbDeviceConnectionState::UnknownConnectionState;
		}
	}
}