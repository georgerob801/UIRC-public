#ifndef UTIL_H
#define UTIL_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>

namespace Util {
    int RGB(unsigned char r, unsigned char g, unsigned char b);
    void drawGrid(Adafruit_ST7735* tft, int interval);
    int freeMemory();
}

#endif