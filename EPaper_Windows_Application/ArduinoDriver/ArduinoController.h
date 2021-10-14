#pragma once

#include "ArduinoSerialCommands.h"
#include <string>

class ArduinoController
{
private:
	bool Initialize();
	void RunCommand(ArduinoSerialCommand command, int argumentCount, ...);
	void WriteToSerialBus(std::string serialData);
	void ReadFromSerialBus();
public:
	ArduinoController();
	~ArduinoController();
	void SetDisplayToBlockMode();
	void SetDisplayToStaticMode();
	void SetDisplayToText(std::string text);
};

