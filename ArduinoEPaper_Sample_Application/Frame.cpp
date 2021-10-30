#ifndef _FRAME_M_
#define _FRAME_M_

#include "Frame.h"
#include <Fonts/FreeMonoBold9pt7b.h>
#include "DisplayMode.h"

String displayText = "Rendering Strings";
int _CurrentX = 0;
int _CurrentY = 0;
int _CurrentColor = 0;
bool _TextWriteReady = false;
bool verticalBlockMode = false;
int staticPixelSize = 1;
bool checkerStartWhite = false;
//This is out here as for some reason when I make this as a local inside the for loops
//In the draw checkers it crashes the application and prevents it from starting up
bool startLineWhite = false;

Frame::Frame()
{
  InitDisplay();
}

void Frame::InitDisplay()
{
   delete _Display;
   _Display = new GxEPD2_BW<GxEPD2_154_D67, 200>(GxEPD2_154_D67(/*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEH0154D67
   _Display->init();
   _Display->setPartialWindow(0, 0, _Display->width(), _Display->height());
   _Display->setFont(&FreeMonoBold9pt7b);
   _Display->setTextColor(GxEPD_BLACK);
   _Display->firstPage();
   _Display->fillScreen(GxEPD_WHITE);
   _Display->nextPage();
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
      if(verticalBlockMode)
      {
        _Display->drawPixel(y, x, _CurrentColor);
      }
      else
      {
        _Display->drawPixel(x, y, _CurrentColor);
      }
		}
	}
	_Display->nextPage();
}

void Frame::Reset()
{
  _CurrentX = 0;
  _CurrentY = 0;
  _CurrentColor = 0;
}

void Frame::Flash()
{
  InitDisplay();
}

void Frame::ReadSerialCommand(String text)
{
	Flash();
	if(static_cast<DisplayMode>(text[0]) == DisplayMode::BlockMode)
	{
		DrawText("Blocks Mode");
		_DisplayMode = DisplayMode::BlockMode;
    verticalBlockMode = static_cast<bool>(text[1]);
		Reset();
	}
	else if(static_cast<DisplayMode>(text[0]) == DisplayMode::TextMode)
	{
		DrawText("Text Mode");
		_TextWriteReady = true;
		displayText = text.substring(1);
		_DisplayMode = DisplayMode::TextMode;
	}
	else if(static_cast<DisplayMode>(text[0]) == DisplayMode::StaticMode)
	{
		DrawText("Static Mode");
    staticPixelSize = text[1];// *static_cast<int*>(static_cast<void*>(&test));
		_DisplayMode = DisplayMode::StaticMode;
	}
  else if(static_cast<DisplayMode>(text[0]) == DisplayMode::CheckerMode)
  {
    DrawText("Checker Mode");
    staticPixelSize = text[1];// *static_cast<int*>(static_cast<void*>(&test));
    _DisplayMode = DisplayMode::CheckerMode;
  }
}

void Frame::DrawStaticField()
{
	_Display->fillScreen(GxEPD_WHITE);
	for(auto x = 0; x < WIDTH; x+= staticPixelSize)
	{
		for(auto y = 0; y < HEIGHT; y+= staticPixelSize)
		{
      auto color = random(100)%2;
      for(auto xPixelSize = 0; xPixelSize <= staticPixelSize - 1; xPixelSize++)
      {
        for(auto yPixelSize = 0; yPixelSize <= staticPixelSize - 1; yPixelSize++)
        {
          _Display->drawPixel(x+xPixelSize,y+yPixelSize, color);
        }
      }
		}
	}
	_Display->nextPage();
}

void Frame::DrawCheckerField()
{
  _Display->fillScreen(GxEPD_WHITE);
  auto drawWhite = checkerStartWhite;
  startLineWhite = drawWhite;
  for(auto x = 0; x < WIDTH; x+= staticPixelSize)
  {
    for(auto y = 0; y < HEIGHT; y+= staticPixelSize)
    {
      for(auto xPixelSize = 0; xPixelSize <= staticPixelSize - 1; xPixelSize++)
      {
        for(auto yPixelSize = 0; yPixelSize <= staticPixelSize - 1; yPixelSize++)
        {
            _Display->drawPixel(x+xPixelSize, y+yPixelSize, startLineWhite ? 1 : 0);
        }
      }
      
      startLineWhite = !startLineWhite;
    }
    
    drawWhite = !drawWhite;
    startLineWhite = drawWhite;
  }
  
  checkerStartWhite = !checkerStartWhite;
  _Display->nextPage();
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
    case DisplayMode::CheckerMode:
      DrawCheckerField();
      break;
		default:
			break;
	}
}

void Frame::DrawText(String text)
{
		int16_t tbx, tby; uint16_t tbw, tbh;
		_Display->getTextBounds(text, 0, 0, &tbx, &tby, &tbw, &tbh);
		// center the bounding box by transposition of the origin:
		uint16_t x = ((_Display->width() - tbw) / 2) - tbx;
		uint16_t y = ((_Display->height() - tbh) / 2) - tby;
		_Display->fillScreen(GxEPD_WHITE);
		_Display->setCursor(x, y);
		_Display->print(text);
		_Display->nextPage();
}

#endif
