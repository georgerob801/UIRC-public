#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"
#include "IRManager.h"
#include "StorageManager.h"

class SceneManager {
public:
    SceneManager(Adafruit_ST7735* screen, unsigned int up, unsigned int down, unsigned int left, unsigned int right, IRManager* irManager);
    void setNextScene(Scene* scene);
    void toNextScene();
    void render();
    void init();
    void loadSetFromFilePath(String filePath);
    bool setupComplete = false;
    unsigned int up, down, left, right;
    Scene* currentScene;
    Scene* nextScene;
    IRManager* irManager;
    StorageManager* storageManager;
private:
    Adafruit_ST7735* tft;
};

#endif