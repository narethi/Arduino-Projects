#pragma once

enum class SerialErrorCode
{
	UnknownError = 0,
	FailedToFindDevice = 1,
	FailedToGetDeviceState = 2,
	FailedToSetDeviceState = 3,
	FailedToSetTimeout = 4,
	FailedToWriteBuffer = 5,
	FailedToReadBuffer = 6
};