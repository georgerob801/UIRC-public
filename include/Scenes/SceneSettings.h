#ifndef SCENE_SETTINGS_H
#define SCENE_SETTINGS_H

#include "SceneManager.h"
#include "Util.h"

class SceneSettings : public Scene {
public:
    SceneSettings(unsigned int parentManager) : Scene(parentManager) {
        textSize = 1;
        fgColor = Util::RGB(255, 0, 0);
        bgColor = Util::RGB(0, 0, 0);
    }

    Scene* clone() {
        return new SceneSettings(*this);
    }

    void init();
    bool left();
    // bool right();
    // bool up();
    // bool down();

    unsigned char btnIndex = 0;
    int selectedIndex = -1;
};

#endif