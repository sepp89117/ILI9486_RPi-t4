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
  tft.writeRect(32, 33, 256, 174, (uint16_t*)picture);
}

void loop(void) {
}
