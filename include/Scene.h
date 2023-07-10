#ifndef SCENE_H
#define SCENE_H

#include "UIElement.h"

class Scene {
public:
    Scene(unsigned int parentManager);

    virtual void render(Adafruit_ST7735* tft);
    void addElement(UIElement* element);
    void manageInput(bool* processed);

    int bgColor;
    int fgColor;
    int textSize = 1;
    unsigned int parentManager;

    unsigned char elementAmnt = 0;
    UIElement* elements[8];

    virtual Scene* clone() {
        return new Scene(*this);
    }

    virtual void init() {
        Serial.println("Init called from the wrong place.");
    }

    virtual void destroy() {
        for (int i = 0; i < elementAmnt; i++) delete elements[i];
        delete[] elements;
    }

    virtual bool up() {
        return false;
    }
    virtual bool down() {
        return false;
    }
    virtual bool left() {
        return false;
    }
    virtual bool right() {
        return false;
    }
};

#endif