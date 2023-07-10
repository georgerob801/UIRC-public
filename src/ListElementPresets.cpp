#include "ListElementPresets.h"
#include "SceneManager.h"

// test
#include "Scenes/SceneMainMenu.h"

void ListElementPresets::onSelect() {
    ((SceneManager*)parentManager)->loadSetFromFilePath(fileToLoad);
}