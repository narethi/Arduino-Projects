#pragma once

#include "PortParityCodes.h"

struct PortSettings
{
	int BaudRate;
	PortParityCode Parity;
	char DataBits;
	char StopBits;
};