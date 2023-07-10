#ifndef TITLE_H
#define TITLE_H

#include <Arduino.h>
#include "UIElement.h"

class Title : public UIElement {
public:
    Title(unsigned int parentManager, String text);
    void render(Adafruit_ST7735* screen);
    bool screenCentre = false;
    String text;
    unsigned char size = 0;
};

#endif