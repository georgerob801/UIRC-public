#ifndef LIST_H
#define LIST_H

#include "ListElement.h"

class List : public UIElement {
public:
    List(unsigned int parentManager) : UIElement(parentManager) {}
    ~List();
    
    void render(Adafruit_ST7735* screen);

    ListElement* elements[64];
    unsigned char numElements = 0;
    unsigned char selectedIndex = 0;
    unsigned int color;
    unsigned int displayOffset = 0;

    void addElement(ListElement* element);
    void runSelected();

    void startCheck();
    bool up();
    bool down();
};

#endif