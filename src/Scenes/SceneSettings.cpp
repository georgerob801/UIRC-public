#include "Scenes/SceneSettings.h"
#include "Scenes/SceneMainMenu.h"
#include "Title.h"
#include "Button.h"

void SceneSettings::init() {
    Title* title = new Title(parentManager, "settings");
    title->setY(10);
    addElement(title);

    if (!((SceneManager*)parentManager)->storageManager->sdCardPresent) {
        // no sd card inserted
        Title* message = new Title(parentManager, "no sd card inserted");
        message->screenCentre = true;
        addElement(message);
    } else {
        // sd card inserted, function as normal
        Button* carrierFreqBtn = new Button(parentManager, "Carrier freq: " + (String)((SceneManager*)parentManager)->irManager->irFreq + "kHz");
        carrierFreqBtn->setY(30);
        carrierFreqBtn->selected = true;
        addElement(carrierFreqBtn);

        Title* tooltip = new Title(parentManager, "");
        tooltip->setY(74);
        addElement(tooltip);
    }
}

bool SceneSettings::left() {
    if (selectedIndex == -1) {
        // previous scene
        ((SceneManager*)parentManager)->setNextScene(new SceneMainMenu(parentManager));
        ((SceneMainMenu*)((SceneManager*)parentManager)->nextScene)->btnIndex = 2;
        ((SceneManager*)parentManager)->toNextScene();
        return true;
    } else {
        // deselect currently selected thing
        selectedIndex = -1;
        ((Title*)elements[2])->text = "";
    }
    return true;
} 