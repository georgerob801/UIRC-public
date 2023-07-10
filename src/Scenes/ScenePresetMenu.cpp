#include "Scenes/ScenePresetMenu.h"
#include "Scenes/SceneSavedMenu.h"
#include "Scenes/SceneSendReceive.h"
#include "Title.h"
#include "List.h"
#include "ListElementPresets.h"

void ScenePresetMenu::init() {

    List* itemList = new List(parentManager);
    itemList->color = Util::RGB(255, 0, 0);


    String presetList = ((SceneManager*)parentManager)->storageManager->readFile("presets.txt");
    if (presetList == "death") {
        ListElementPresets* item = new ListElementPresets(parentManager, "death", "");
        itemList->addElement(item);
    } else {
        String* lines = new String[((String)presetList.charAt(0)).toInt()];
        int lastEnter = presetList.indexOf("\n");
        int nextEnter = presetList.indexOf("\n", lastEnter + 1);

        for (int i = 0; i < ((String)presetList.charAt(0)).toInt(); i++) {
            lines[i] = presetList.substring(lastEnter + 1, nextEnter);
            lastEnter = presetList.indexOf("\n", lastEnter + 1);
            nextEnter = presetList.indexOf("\n", lastEnter + 1);
        }

        for (int i = 0; i < ((String)presetList.charAt(0)).toInt(); i++) {
            if (lines[i].charAt(0) == '-') {
                // title
                ListElementPresets* item = new ListElementPresets(parentManager, lines[i].substring(1, lines[i].length()), "");
                item->type = 1;
                itemList->addElement(item);
            } else {
                // normal item
                ListElementPresets* item = new ListElementPresets(parentManager, lines[i].substring(0, lines[i].indexOf("#")), lines[i].substring(lines[i].indexOf("#") + 1, lines[i].length() - 1));
                itemList->addElement(item);
            }
        }
    }

    itemList->startCheck();
    
    addElement(itemList);
}

bool ScenePresetMenu::left() {
    ((SceneManager*)parentManager)->setNextScene(new SceneSavedMenu(parentManager));
    ((SceneManager*)parentManager)->toNextScene();
    return true;
}

bool ScenePresetMenu::right() {
    ((List*)elements[0])->runSelected();
    ((SceneManager*)parentManager)->setNextScene(new SceneSendReceive(parentManager));
    ((SceneManager*)parentManager)->toNextScene();
    // ((Title*)((SceneManager*)parentManager)->nextScene->elements[1])->text = "loaded preset";
    return true;
}

bool ScenePresetMenu::up() {
    return ((List*)elements[0])->up();
}

bool ScenePresetMenu::down() {
    return ((List*)elements[0])->down();
}