#ifndef SCENE_PRESET_MENU_H
#define SCENE_PRESET_MENU_H

#include "SceneManager.h"
#include "Util.h"

class ScenePresetMenu : public Scene {
public:
    ScenePresetMenu(unsigned int parentManager) : Scene(parentManager) {
        textSize = 1;
        fgColor = Util::RGB(255, 0, 0);
        bgColor = Util::RGB(0, 0, 0);
    }

    Scene* clone() {
        return new ScenePresetMenu(*this);
    }

    void init();
    bool left();
    bool right();
    bool up();
    bool down();
};

#endif