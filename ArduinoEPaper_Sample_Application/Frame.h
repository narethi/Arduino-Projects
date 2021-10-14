#ifndef _FRAME_H_
#define _FRAME_H_

#include "GxEPD2_BW.h"
#include "DisplayMode.h"

class Frame
{
private:
	const int HEIGHT = 200;
	const int WIDTH = 200;
	void SetFrameColor(int16_t color);
	GxEPD2_BW<GxEPD2_154_D67, 200> _Display = GxEPD2_BW<GxEPD2_154_D67, 200>(GxEPD2_154_D67(/*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEH0154D67
   DisplayMode _DisplayMode = DisplayMode::BlockMode;
   void DrawText(String text);
   void StepBuffer();
   void DrawBlockBuffer();
   void Flash();
   void Reset();
   void DrawStaticField();
public: 
   Frame();
   void Render();
   void ReadSerialCommand(String text);
};

#endif
