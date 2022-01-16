#include "pch.h"
#include "UsbDeviceErrorCodes.h"

namespace UsbApiUtility
{
	UsbDeviceErrorCode ConvertToManagedCode(UsbDeviceError code)
	{
		switch (code)
		{
			case UsbDeviceError::FailedToFindDevice:
				return UsbDeviceErrorCode::FailedToFindDevice;
			case UsbDeviceError::FailedToGetDeviceState:
				return UsbDeviceErrorCode::FailedToGetDeviceState;
			case UsbDeviceError::FailedToSetDeviceState:
				return UsbDeviceErrorCode::FailedToSetDeviceState;
			case UsbDeviceError::FailedToSetTimeout:
				return UsbDeviceErrorCode::FailedToSetTimeout;
			case UsbDeviceError::FailedToWriteBuffer:
				return UsbDeviceErrorCode::FailedToWriteBuffer;
			case UsbDeviceError::FailedToReadBuffer:
				return UsbDeviceErrorCode::FailedToReadBuffer;
			case UsbDeviceError::FailedToFindPortSettings:
				return UsbDeviceErrorCode::FailedToFindPortSettings;
			case UsbDeviceError::InvalidPortInfoProvided:
				return UsbDeviceErrorCode::InvalidPortInfoProvided;
			case UsbDeviceError::NoConnectedDevice:
				return UsbDeviceErrorCode::NoConnectedDevice;
			case UsbDeviceError::UnknownError:
			default:
				return UsbDeviceErrorCode::UnknownError;
		}
	}

	UsbDeviceError ConvertToUnmanagedCode(UsbDeviceErrorCode code)
	{
		switch (code)
		{
			case UsbDeviceErrorCode::FailedToFindDevice:
				return UsbDeviceError::FailedToFindDevice;
			case UsbDeviceErrorCode::FailedToGetDeviceState:
				return UsbDeviceError::FailedToGetDeviceState;
			case UsbDeviceErrorCode::FailedToSetDeviceState:
				return UsbDeviceError::FailedToSetDeviceState;
			case UsbDeviceErrorCode::FailedToSetTimeout:
				return UsbDeviceError::FailedToSetTimeout;
			case UsbDeviceErrorCode::FailedToWriteBuffer:
				return UsbDeviceError::FailedToWriteBuffer;
			case UsbDeviceErrorCode::FailedToReadBuffer:
				return UsbDeviceError::FailedToReadBuffer;
			case UsbDeviceErrorCode::FailedToFindPortSettings:
				return UsbDeviceError::FailedToFindPortSettings;
			case UsbDeviceErrorCode::InvalidPortInfoProvided:
				return UsbDeviceError::InvalidPortInfoProvided;
			case UsbDeviceErrorCode::NoConnectedDevice:
				return UsbDeviceError::NoConnectedDevice;
			case UsbDeviceErrorCode::UnknownError:
			default:
				return UsbDeviceError::UnknownError;
		}
	}

}