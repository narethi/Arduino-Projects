#ifndef _FRAME_M_
#define _FRAME_M_

#include "Frame.h"
#include <Fonts/FreeMonoBold9pt7b.h>

String displayText = "Rendering Strings";
int _CurrentX = 0;
int _CurrentY = 0;
int _CurrentColor = 0;
bool _TextWriteReady = false;

Frame::Frame()
{
	_Display.init();
	_Display.setPartialWindow(0, 0, _Display.width(), _Display.height());
  	_Display.setFont(&FreeMonoBold9pt7b);
	_Display.setTextColor(GxEPD_BLACK);
	_Display.firstPage();
	_Display.fillScreen(GxEPD_WHITE);
	_Display.nextPage();
}

void Frame::StepBuffer()
{
	_CurrentX += 100;
	if (_CurrentX > WIDTH)
	{
		_CurrentY += 10;
		if (_CurrentY > HEIGHT)
		{
			_CurrentY = 0;
			if (_CurrentColor == 0)
			{
				_CurrentColor = 1;
			}
			else
			{
				_CurrentColor = 0;
			}
		}
		_CurrentX = 0;
	}
}

void Frame::DrawBlockBuffer()
{
	auto backgroundColor = _CurrentColor == 0 ? 1 : 0;
	if (_CurrentX == 0)
	{
		return;
	}

	for (auto x = _CurrentX - 100; x < _CurrentX; x++)
	{
		for (auto y = _CurrentY; y < _CurrentY + 10; y++)
		{
			_Display.drawPixel(x, y, _CurrentColor);
		}
	}
	_Display.nextPage();
}

void Frame::Reset()
{
  _CurrentX = 0;
  _CurrentY = 0;
  _CurrentColor = 0;
}

void Frame::Flash()
{
  _Display.fillScreen(GxEPD_BLACK);
  _Display.nextPage();
  _Display.fillScreen(GxEPD_WHITE);
  _Display.nextPage();
}

void Frame::ReadSerialCommand(String text)
{
	Flash();
	if(text[0] == 1)
	{
		DrawText("Blocks Mode");
		_DisplayMode = DisplayMode::BlockMode;
		Reset();
	}
	if(text[0] == 2)
	{
		DrawText("Text Mode");
		_TextWriteReady = true;
		displayText = text.substring(1);
		_DisplayMode = DisplayMode::TextMode;
	}
	if(text[0] == 3)
	{
		DrawText("Static Mode");
		_DisplayMode = DisplayMode::StaticMode;
	}
}

void Frame::DrawStaticField()
{
	_Display.fillScreen(GxEPD_WHITE);
	for(auto x = 0; x < WIDTH; x++)
	{
		for(auto y = 0; y < HEIGHT; y++)
		{
			_Display.drawPixel(x,y, random(100)%2);
		}
	}
	_Display.nextPage();
}

void Frame::Render()
{
	switch(_DisplayMode)
	{
		case DisplayMode::BlockMode:
			DrawBlockBuffer();
			StepBuffer();
			break;
		case DisplayMode::TextMode:
			DrawText(displayText);
			break;
		case DisplayMode::StaticMode:
		 	DrawStaticField();
			break;
		default:
			break;
	}
}

void Frame::DrawText(String text)
{
		int16_t tbx, tby; uint16_t tbw, tbh;
		_Display.getTextBounds(text, 0, 0, &tbx, &tby, &tbw, &tbh);
		// center the bounding box by transposition of the origin:
		uint16_t x = ((_Display.width() - tbw) / 2) - tbx;
		uint16_t y = ((_Display.height() - tbh) / 2) - tby;
		_Display.fillScreen(GxEPD_WHITE);
		_Display.setCursor(x, y);
		_Display.print(text);
		_Display.nextPage();
}

#endif
