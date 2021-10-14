#include <GxEPD2.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_7C.h>
#include <GxEPD2_BW.h>
#include <GxEPD2_EPD.h>
#include <GxEPD2_GFX.h>

#include "Frame.h"

// GxEPD2_MinimumExample.ino by Jean-Marc Zingg

// purpose is e.g. to determine minimum code and ram use by this library

// see GxEPD2_wiring_examples.h of GxEPD2_Example for wiring suggestions and examples
// if you use a different wiring, you need to adapt the constructor parameters!

// uncomment next line to use class GFX of library GFX_Root instead of Adafruit_GFX, to use less code and ram
//#include <GFX.h>

#include <GxEPD2_BW.h> // including both doesn't use more code or ram
#include <GxEPD2_3C.h> // including both doesn't use more code or ram

// select the display class and display driver class in the following file (new style):
#include "GxEPD2_display_selection_new_style.h"

// alternately you can copy the constructor from GxEPD2_display_selection.h or GxEPD2_display_selection_added.h of GxEPD2_Example to here
// e.g. for Wemos D1 mini:
//GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(GxEPD2_154_D67(/*CS=D8*/ SS, /*DC=D3*/ 0, /*RST=D4*/ 2, /*BUSY=D2*/ 4)); // GDEH0154D67

//CS=53 green, /*DC=*/ 8 blue, /*RST=*/ 9 purple, /*BUSY=*/ 7 grey, sdi=51 orange ,clk=52 yellow
//GxEPD2_BW<GxEPD2_154_D67, 200> display(GxEPD2_154_D67(/*CS=*/ SS, /*DC=*/ 8, /*RST=*/ 9, /*BUSY=*/ 7)); // GDEH0154D67

void setup()
{
  Serial.begin(9600);
  Frame test;
  //test = new Frame();
  while(true)
  {
    if(Serial.available() > 0)
    {
      String serialData = "";
      while(Serial.available() > 0)
      {
        serialData += String((char)Serial.read()); 
      }
      test.ReadSerialCommand(serialData);
    }
    test.Render();
  }
  /*display.init();
  // comment out next line to have no or minimal Adafruit_GFX code
  display.setTextColor(GxEPD_BLACK);
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    for(int i = 0; i <  50;  i++)
    {
      for(int j = 50; j <  100; j++)
      {
        display.drawPixel(i,j,0);
      }
    }

    display.drawPixel(10,75,1);
    display.drawPixel(10,76,50);
    display.drawPixel(10,77,100);
    display.drawPixel(10,78,150);
    
    // comment out next line to have no or minimal Adafruit_GFX code
    display.print("Hello World!");
  }
  while (display.nextPage());*/
}

void loop() 
{

};
