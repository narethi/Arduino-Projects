#pragma once

#include "ArduinoSerialCommands.h"
#include <string>

class ArduinoDriver
{
private:
	bool Initialize();
	void RunCommand(ArduinoSerialCommand command, int argumentCount, ...);
	void WriteToSerialBus(std::string serialData);
	void ReadFromSerialBus();
public:
	ArduinoDriver();
	~ArduinoDriver();
	void SetDisplayToBlockMode(bool isVertical);
	void SetDisplayToStaticMode(int blockSize);
	void SetDisplayToCheckerMode(int blockSize);
	void SetDisplayToText(std::string text);
	void SetDisplayToSleepMode();
	void CheckDeviceCommState();
};

