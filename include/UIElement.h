#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>

class UIElement {
public:
    UIElement(unsigned int manager);
    virtual ~UIElement();
    virtual void render(Adafruit_ST7735* tft);
    unsigned short getX();
    unsigned short getY();
    void setX(int x);
    void setY(int y);
    int x = 0;
    int y = 0;
    unsigned int parentManager;
};

#endif