#include "SPI.h"
#include "ILI9486_t3n.h"

// Converted to code with:
// http://www.rinkydinkelectronics.com/t_imageconverter565.php
//
#include "picture.c" //the picture

//TFT config
#define TFT_DC       9
#define TFT_CS      10
#define TFT_RST      8
#define TFT_MOSI    11
#define TFT_SCLK    13
#define TFT_MISO    12

ILI9486_t3n tft = ILI9486_t3n(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_MISO);

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9486_BLACK);
  
  //useFrameBuffer by KurtE reduces the amount of data transferred
  //The data is first written to a buffer and only transferred with updateScreen()
  //Only a rectangle in the size that contains the changes is written.
  tft.useFrameBuffer(1); //
}

void loop(void) {
  //fade in smooth
  for (int i = 0; i < 255; i += 5) {
    //drawPicBrightness() allows you to draw a picture with an indication of the brightness. 
    //The brightness can be specified from 0 to 255 and corresponds to 0 to 100%, where 0 is black.
    
    //drawPicBrightness(int x, int y, int w, int h, const uint16_t* pic, int brightness);
    tft.drawPicBrightness(480 / 2 - 256 / 2, 320 / 2 - 174 / 2, 256, 174, (uint16_t*)picture, i);

    //Start transferring the changed rectangle
    tft.updateScreen();
  }

  delay(800);

  //fade out fast
  for (int i = 255; i > 0; i -= 15) {
    //drawPicBrightness(int x, int y, int w, int h, const uint16_t* pic, int brightness);
    tft.drawPicBrightness(480 / 2 - 256 / 2, 320 / 2 - 174 / 2, 256, 174, (uint16_t*)picture, i);
    
    //Start transferring the changed rectangle
    tft.updateScreen();
  }

  delay(800);
}
