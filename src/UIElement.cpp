#include "UIElement.h"

UIElement::UIElement(unsigned int sceneManager) {
    parentManager = sceneManager;
}

UIElement::~UIElement() {
    
}

void UIElement::render(Adafruit_ST7735* tft) {
    Serial.println("Render called from the wrong place.");
}

unsigned short UIElement::getX() {
    return x;
}

unsigned short UIElement::getY() {
    return y;
}

void UIElement::setX(int newX) {
    x = newX;
}

void UIElement::setY(int newY) {
    y = newY;
}