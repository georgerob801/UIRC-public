#include "SceneManager.h"

SceneManager::SceneManager(Adafruit_ST7735* screen, unsigned int _up, unsigned int _down, unsigned int _left, unsigned int _right, IRManager* _irManager) {
    tft = screen;
    up = _up;
    down = _down;
    left = _left;
    right = _right;
    irManager = _irManager;
}

void SceneManager::init() {
    // avoid if cannot access file
    if (!this->storageManager->sdCardPresent) return;
    
    // delay otherwise things break
    delay(1000);

    // load 8 slots
    for (int i = 0; i < 8; i++) {
        String process = this->storageManager->readFile((String)"default/" + (i + 1) + (String)".txt");
        this->irManager->fromString(process, i + 1);
    }
}

void SceneManager::setNextScene(Scene* scene) {
    delete nextScene;
    nextScene = scene;
}

void SceneManager::toNextScene() {
    delete currentScene;
    currentScene = nextScene->clone();
    currentScene->init();
}

void SceneManager::render() {
    currentScene->render(tft);
}

void SceneManager::loadSetFromFilePath(String filePath) {
    String data = storageManager->readFile((String)"storage/presets/" + filePath);
    if (data == "death") return;

    int lastEnter = data.indexOf("\n");
    int nextEnter = data.indexOf("\n", lastEnter + 1);

    for (int i = 0; i < 8; i++) {
        irManager->fromString(data.substring(lastEnter + 1, nextEnter), i + 1);
        storageManager->writeFile((String)"default/" + (i + 1) + (String)".txt", irManager->toString(i + 1));
        lastEnter = data.indexOf("\n", lastEnter + 1);
        nextEnter = data.indexOf("\n", lastEnter + 1);
    }
}