#ifndef SCENE_SAVED_MENU_H
#define SCENE_SAVED_MENU_H

#include "Scene.h"
#include "Util.h"

class SceneSavedMenu : public Scene {
public:
    SceneSavedMenu(unsigned int parentManager) : Scene(parentManager) {
        textSize = 1;
        fgColor = Util::RGB(255, 0, 0);
        bgColor = Util::RGB(0, 0, 0);
    }

    Scene* clone() {
        return new SceneSavedMenu(*this);
    }

    void init();
    bool left();
    bool right();
    bool down();
    bool up();

    unsigned int btnIndex = 0;
};

#endif