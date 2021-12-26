#pragma once

#include "PortParityCodes.h"

struct PortSettings
{
	int BaudRate;
	char DataBits;
	char StopBits;
	PortParityCode Parity;
};