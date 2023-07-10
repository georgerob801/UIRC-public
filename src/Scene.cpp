#include "Scene.h"
#include "Util.h"
#include "SceneManager.h"
#include "Title.h"

Scene::Scene(unsigned int _parentManager) {
    parentManager = _parentManager;
}

void Scene::render(Adafruit_ST7735* tft) {
    tft->fillScreen(bgColor);
    for (unsigned char i = 0; i < elementAmnt; i++) {
        elements[i]->render(tft);
    }
}

void Scene::addElement(UIElement* element) {
    elements[elementAmnt] = element;
    elementAmnt++;
}

void Scene::manageInput(bool* processed) {
    if (digitalRead(((SceneManager*)parentManager)->up) == 0) *processed = up();
    else if (digitalRead(((SceneManager*)parentManager)->down) == 0) *processed = down();
    else if (digitalRead(((SceneManager*)parentManager)->left) == 0) *processed = left();
    else if (digitalRead(((SceneManager*)parentManager)->right) == 0) *processed = right();
}