#ifndef SCENE_SEND_RECEIVE_H
#define SCENE_SEND_RECEIVE_H

#include "Util.h"
#include "SceneManager.h"

class SceneSendReceive : public Scene {
public:
    SceneSendReceive(unsigned int parentManager) : Scene(parentManager) {
        textSize = 1;
        fgColor = Util::RGB(255, 0, 0);
        bgColor = Util::RGB(0, 0, 0);
    }

    Scene* clone() {
        return new SceneSendReceive(*this);
    }

    void init();
    bool left();
    bool right();
    bool up();
    bool down();
    void render(Adafruit_ST7735* tft);

    unsigned char dataIndex = 0;
};

#endif