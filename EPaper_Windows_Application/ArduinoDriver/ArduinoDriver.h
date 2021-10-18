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
	void CheckDeviceCommState();
public:
	ArduinoDriver();
	~ArduinoDriver();
	void SetDisplayToBlockMode();
	void SetDisplayToStaticMode();
	void SetDisplayToText(std::string text);
};

