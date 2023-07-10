#ifndef SCENE_MAIN_MENU_H
#define SCENE_MAIN_MENU_H

#include "SceneManager.h"
#include "Util.h"

class SceneMainMenu : public Scene {
public:
    SceneMainMenu(unsigned int parentManager) : Scene(parentManager) {
        textSize = 1;
        fgColor = Util::RGB(255, 0, 0);
        bgColor = Util::RGB(0, 0, 0);
    }

    Scene* clone() {
        return new SceneMainMenu(*this);
    }

    void init();
    bool right();
    bool up();
    bool down();

    unsigned char btnIndex = 0;
};

#endif