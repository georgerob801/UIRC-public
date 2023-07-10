#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

#include <Arduino.h>
#include "UIElement.h"

class ListElement : public UIElement {
public:
    ListElement(unsigned int manager) : UIElement(manager) {}
    String text;
    unsigned char type = 0;
    virtual void onSelect() {

    }
};

#endif