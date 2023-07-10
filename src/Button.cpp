#include "Button.h"
#include "Util.h"
#include "SceneManager.h"

Button::Button(unsigned int parentManager, String _text) : UIElement(parentManager) {
    text = _text;
}

void Button::render(Adafruit_ST7735* screen) {
    if (selected) screen->setTextColor(((SceneManager*)parentManager)->currentScene->bgColor);
    else screen->setTextColor(((SceneManager*)parentManager)->currentScene->fgColor);
    screen->setTextSize(((SceneManager*)parentManager)->currentScene->textSize);
    uint16_t w, h;
    screen->getTextBounds(text, 0, 0, NULL, NULL, &w, &h);
    setX((screen->width() / 2) - (w / 2));
    if (screenCentre) {
        setY((screen->height() / 2) - (h / 2));
    }
    if (selected) screen->fillRoundRect(20, getY() - 5, screen->width() - 40, h + 10, 3, ((SceneManager*)parentManager)->currentScene->fgColor);
    else screen->drawRoundRect(20, getY() - 5, screen->width() - 40, h + 10, 3, ((SceneManager*)parentManager)->currentScene->fgColor);
    screen->setCursor((int)getX(), (int)getY());
    screen->println(text);
}