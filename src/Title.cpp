#include "Title.h"
#include "SceneManager.h"

Title::Title(unsigned int parentManager, String _text) : UIElement(parentManager) {
    text = _text;
};

void Title::render(Adafruit_ST7735* screen) {
    screen->setTextColor(((SceneManager*)parentManager)->currentScene->fgColor);
    screen->setTextSize(size != (unsigned char)0 ? (unsigned int)size : ((SceneManager*)parentManager)->currentScene->textSize);
    uint16_t w, h;
    screen->getTextBounds(text, 0, 0, NULL, NULL, &w, &h);
    setX((screen->width() / 2) - (w / 2));
    if (screenCentre) {
        setY((screen->height() / 2) - (h / 2));
    }
    screen->setCursor((int)getX(), (int)getY());
    screen->println(text);
}