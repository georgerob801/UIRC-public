#ifndef SCENE_START_H
#define SCENE_START_H

#include "SceneManager.h"
#include "Title.h"
#include "Util.h"

#include "Scenes/SceneMainMenu.h"

class SceneStart : public Scene {
public:
    SceneStart(unsigned int parentManager) : Scene(parentManager) {
        textSize = 4;
        fgColor = Util::RGB(255, 0, 0);
        bgColor = Util::RGB(0, 0, 0);
    }

    Scene* clone() {
        return new SceneStart(*this);
    }

    void init();
};

#endif