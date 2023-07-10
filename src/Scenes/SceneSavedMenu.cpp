#include "Scenes/SceneSavedMenu.h"
#include "Scenes/SceneMainMenu.h"
#include "Scenes/ScenePresetMenu.h"
#include "SceneManager.h"
#include "Title.h"
#include "Button.h"

void SceneSavedMenu::init() {
    Title* title = new Title(parentManager, "storage");
    title->setY(10);
    addElement(title);

    if (((SceneManager*)parentManager)->storageManager->sdCardPresent) {
        Button* presets = new Button(parentManager, "presets");
        presets->setY(30);
        if (btnIndex == 0) presets->selected = true;
        addElement(presets);

        Button* browse = new Button(parentManager, "browse");
        browse->setY(52);
        if (btnIndex == 1) browse->selected = true;
        addElement(browse);

        Button* save = new Button(parentManager, "save");
        save->setY(74);
        if (btnIndex == 2) save->selected = true;
        addElement(save);

        Title* tooltip = new Title(parentManager, btnIndex == 0 ? "view preset layouts" : btnIndex == 1 ? "browse saved codes" : "save a code");
        tooltip->setY(113);
        addElement(tooltip);
    } else {
        Title* noSD = new Title(parentManager, "no sd card inserted");
        noSD->screenCentre = true;
        addElement(noSD);
    }
}

bool SceneSavedMenu::left() {
    ((SceneManager*)parentManager)->setNextScene(new SceneMainMenu(parentManager));
    ((SceneMainMenu*)((SceneManager*)parentManager)->nextScene)->btnIndex = 1;
    ((SceneManager*)parentManager)->toNextScene();
    return true;
}

bool SceneSavedMenu::right() {
    if (((SceneManager*)parentManager)->storageManager->sdCardPresent) {
        switch(btnIndex) {
            case 0:
                // presets
                ((SceneManager*)parentManager)->setNextScene(new ScenePresetMenu(parentManager));
                ((SceneManager*)parentManager)->toNextScene();
                break;
            case 1:
                // browse
                break;
            case 2:
                //save
                break;
            default:
                // ?????
                return false;
        }
        return true;
    } else {
        return false;
    }
}

bool SceneSavedMenu::up() {
    if (((SceneManager*)parentManager)->storageManager->sdCardPresent) {
        if (btnIndex > 0) btnIndex--;
        else return false;
        for (int i = 0; i < 3; i++) ((Button*)elements[i + 1])->selected = false;
        ((Button*)elements[btnIndex + 1])->selected = true;

        switch(btnIndex) {
            case 0:
                ((Title*)elements[4])->text = "view preset layouts";
                break;
            case 1:
                ((Title*)elements[4])->text = "browse saved codes";
                break;
            case 2:
                ((Title*)elements[4])->text = "save a code";
                break;
            default:
                ((Title*)elements[4])->text = "bruh impossible option";
        }
        return true;
    } else {
        return false;
    }
}

bool SceneSavedMenu::down() {
    if (((SceneManager*)parentManager)->storageManager->sdCardPresent) {
        if (btnIndex < 2) btnIndex++;
        else return false;
        for (int i = 0; i < 3; i++) ((Button*)elements[i + 1])->selected = false;
        ((Button*)elements[btnIndex + 1])->selected = true;

        switch(btnIndex) {
            case 0:
                ((Title*)elements[4])->text = "view preset layouts";
                break;
            case 1:
                ((Title*)elements[4])->text = "browse saved codes";
                break;
            case 2:
                ((Title*)elements[4])->text = "save a code";
                break;
            default:
                ((Title*)elements[4])->text = "bruh impossible option";
        }
        return true;
    } else {
        return false;
    }
}