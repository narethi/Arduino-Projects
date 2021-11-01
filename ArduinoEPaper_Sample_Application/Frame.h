#ifndef _FRAME_H_
#define _FRAME_H_

#include "GxEPD2_BW.h"
#include "DisplayMode.h"

class Frame
{
private:
  	const int HEIGHT = 200;
  	const int WIDTH = 200;
    DisplayMode _PreviousDisplayMode = DisplayMode::BlockMode;
  	void SetFrameColor(int16_t color);
  	GxEPD2_BW<GxEPD2_154_D67, 200> *  _Display;
    DisplayMode _DisplayMode = DisplayMode::BlockMode;
    void DrawText(String text);
    void StepBuffer();
    void DrawBlockBuffer();
    void DrawCheckerField();
    void Flash();
    void Reset();
    void DrawStaticField();
    void InitDisplay();
public: 
   Frame();
   void Render();
   void ReadSerialCommand(String text);
};

#endif
