#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>
#include "UIElement.h"

class Button : public UIElement {
public:
    Button(unsigned int parentManager, String text);
    void render(Adafruit_ST7735* screen);
    bool screenCentre = false;
    String text;
    bool selected = false;
};

#endif