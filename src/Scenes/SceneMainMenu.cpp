#include "Scenes/SceneMainMenu.h"
#include "Scenes/SceneStart.h"
#include "Scenes/SceneSendReceive.h"
#include "Scenes/SceneSavedMenu.h"
#include "Scenes/SceneSettings.h"
#include "Title.h"
#include "Button.h"

void SceneMainMenu::init() {
    Title* title = new Title(parentManager, "options");
    title->setY(10);
    addElement(title);

    Button* sendRecieve = new Button(parentManager, "send/receive");
    sendRecieve->setY(30);
    if (btnIndex == 0) sendRecieve->selected = true;
    addElement(sendRecieve);

    Button* browse = new Button(parentManager, "storage");
    browse->setY(52);
    if (btnIndex == 1) browse->selected = true;
    addElement(browse);

    Button* settings = new Button(parentManager, "settings");
    settings->setY(74);
    if (btnIndex == 2) settings->selected = true;
    addElement(settings);

    Title* tooltip = new Title(parentManager, btnIndex == 0 ? "send/receive ir codes" : btnIndex == 1 ? "stored ir codes" : "pretty obvious");
    tooltip->setY(113);
    addElement(tooltip);
}

bool SceneMainMenu::right() {
    switch (btnIndex) {
        case 0:
            // send/receive
            ((SceneManager*)parentManager)->setNextScene(new SceneSendReceive(parentManager));
            ((SceneManager*)parentManager)->toNextScene();
            break;
        case 1:
            // storage
            ((SceneManager*)parentManager)->setNextScene(new SceneSavedMenu(parentManager));
            ((SceneManager*)parentManager)->toNextScene();
            break;
        case 2:
            // settings
            ((SceneManager*)parentManager)->setNextScene(new SceneSettings(parentManager));
            ((SceneManager*)parentManager)->toNextScene();
            break;
        default:
            // ??????
            return false;
    }
    return true;
}

bool SceneMainMenu::up() {
    if (btnIndex > 0) btnIndex--;
    else return false;
    for (int i = 0; i < 3; i++) {
        ((Button*)elements[i + 1])->selected = false;
    }
    ((Button*)elements[btnIndex + 1])->selected = true;

    switch (btnIndex) {
        case 0:
            ((Title*)elements[4])->text = "send/receive ir codes";
            break;
        case 1:
            ((Title*)elements[4])->text = "stored ir codes";
            break;
        case 2:
            ((Title*)elements[4])->text = "pretty obvious";
            break;
        default:
            ((Title*)elements[4])->text = "bruh impossible option";
    }

    return true;
}

bool SceneMainMenu::down() {
    if (btnIndex < 2) btnIndex++;
    else return false;
    for (int i = 0; i < 3; i++) {
        ((Button*)elements[i + 1])->selected = false;
    }
    ((Button*)elements[btnIndex + 1])->selected = true;

    switch (btnIndex) {
        case 0:
            ((Title*)elements[4])->text = "send/receive ir codes";
            break;
        case 1:
            ((Title*)elements[4])->text = "browse saved ir codes";
            break;
        case 2:
            ((Title*)elements[4])->text = "pretty obvious";
            break;
        default:
            ((Title*)elements[4])->text = "bruh impossible option";
    }

    return true;
}