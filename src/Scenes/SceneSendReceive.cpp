#include "Scenes/SceneSendReceive.h"
#include "Scenes/SceneMainMenu.h"
#include "Title.h"

void SceneSendReceive::init() {
    Title* title = new Title(parentManager, "send/receive");
    title->setY(10);
    addElement(title);

    Title* tooltip = new Title(parentManager, "");
    tooltip->setY(113);
    addElement(tooltip);
}

void SceneSendReceive::render(Adafruit_ST7735* tft) {
    tft->fillScreen(bgColor);
    for (unsigned char i = 0; i < elementAmnt; i++) {
        elements[i]->render(tft);
    }

    int boxWidth = (tft->width() / 4) - 4;
    int boxY = ((tft->height() - boxWidth) / 2) - 20;
    for (int i = 0; i < 4; i++) {
        tft->drawRoundRect((tft->width() / 4) * i + 2, boxY, boxWidth, boxWidth, 7, fgColor);
        if (i == dataIndex) {
            tft->fillRoundRect((tft->width() / 4) * i + 4, boxY + 2, boxWidth - 4, boxWidth - 4, 5, fgColor);
        } 
    }
    boxY = boxY + boxWidth + 4;
    for (int i = 0; i < 4; i++) {
        tft->drawRoundRect((tft->width() / 4) * i + 2, boxY, boxWidth, boxWidth, 7, fgColor);
        if (i + 4 == dataIndex) {
            tft->fillRoundRect((tft->width() / 4) * i + 4, boxY + 2, boxWidth - 4, boxWidth - 4, 5, fgColor);
        } 
    }
}

bool SceneSendReceive::left() {
    if (dataIndex == 0) {
        ((SceneManager*)parentManager)->setNextScene(new SceneMainMenu(parentManager));
        ((SceneManager*)parentManager)->toNextScene();
        return true;
    } else {
        if (dataIndex > 0) dataIndex--;
        else return false;
        ((Title*)elements[1])->text = "";
        return true;
    }
}

bool SceneSendReceive::right() {
    if (dataIndex < 7) dataIndex++;
    else return false;
    ((Title*)elements[1])->text = "";
    return true;
}

bool SceneSendReceive::up() {
    // send current thing
    switch (dataIndex) {
        case 0:
            if (((SceneManager*)parentManager)->irManager->data1 == NULL) {
                ((Title*)elements[1])->text = "no code in slot 1";
                return true;
            }
            ((SceneManager*)parentManager)->irManager->send1();
            ((Title*)elements[1])->text = "sent code in slot 1";
            return true;
            break;
        case 1:
            if (((SceneManager*)parentManager)->irManager->data2 == NULL) {
                ((Title*)elements[1])->text = "no code in slot 2";
                return true;
            }
            ((SceneManager*)parentManager)->irManager->send2();
            ((Title*)elements[1])->text = "sent code in slot 2";
            return true;
            break;
        case 2:
            if (((SceneManager*)parentManager)->irManager->data3 == NULL) {
                ((Title*)elements[1])->text = "no code in slot 3";
                return true;
            }
            ((SceneManager*)parentManager)->irManager->send3();
            ((Title*)elements[1])->text = "sent code in slot 3";
            return true;
            break;
        case 3:
            if (((SceneManager*)parentManager)->irManager->data4 == NULL) {
                ((Title*)elements[1])->text = "no code in slot 4";
                return true;
            }
            ((SceneManager*)parentManager)->irManager->send4();
            ((Title*)elements[1])->text = "sent code in slot 4";
            return true;
            break;
        case 4:
            if (((SceneManager*)parentManager)->irManager->data5 == NULL) {
                ((Title*)elements[1])->text = "no code in slot 5";
                return true;
            }
            ((SceneManager*)parentManager)->irManager->send5();
            ((Title*)elements[1])->text = "sent code in slot 5";
            return true;
            break;
        case 5:
            if (((SceneManager*)parentManager)->irManager->data6 == NULL) {
                ((Title*)elements[1])->text = "no code in slot 6";
                return true;
            }
            ((SceneManager*)parentManager)->irManager->send6();
            ((Title*)elements[1])->text = "sent code in slot 6";
            return true;
            break;
        case 6:
            if (((SceneManager*)parentManager)->irManager->data7 == NULL) {
                ((Title*)elements[1])->text = "no code in slot 7";
                return true;
            }
            ((SceneManager*)parentManager)->irManager->send7();
            ((Title*)elements[1])->text = "sent code in slot 7";
            return true;
            break;
        case 7:
            if (((SceneManager*)parentManager)->irManager->data8 == NULL) {
                ((Title*)elements[1])->text = "no code in slot 8";
                return true;
            }
            ((SceneManager*)parentManager)->irManager->send8();
            ((Title*)elements[1])->text = "sent code in slot 8";
            return true;
            break;
        default:
            ((Title*)elements[1])->text = "aaaaaaaaaaaaaaaaaaaaaa";
            return true;
    }
    return false;
}

bool SceneSendReceive::down() {
    // receive something
    ((Title*)elements[1])->text = "waiting for signal";
    delay(200);
    ((SceneManager*)parentManager)->render();
    ((SceneManager*)parentManager)->irManager->receiver->enableIRIn();
    while (true) {
        if (((SceneManager*)parentManager)->irManager->receiver->getResults()) {
            // save
            ((Title*)elements[1])->text = "processing";
            ((SceneManager*)parentManager)->render();
            uint16_t* data = (uint16_t*)recvGlobal.recvBuffer;
            data[0] = NULL;
            for (bufIndex_t i = 1; i < recvGlobal.recvLength; i++) {
                data[i - 1] = data[i];
            }
            data[recvGlobal.recvLength - 1] = 1000;
            switch (dataIndex) {
                case 0:
                    ((SceneManager*)parentManager)->irManager->setData1(data, recvGlobal.recvLength);
                    break;
                case 1:
                    ((SceneManager*)parentManager)->irManager->setData2(data, recvGlobal.recvLength);
                    break;
                case 2:
                    ((SceneManager*)parentManager)->irManager->setData3(data, recvGlobal.recvLength);
                    break;
                case 3:
                    ((SceneManager*)parentManager)->irManager->setData4(data, recvGlobal.recvLength);
                    break;
                case 4:
                    ((SceneManager*)parentManager)->irManager->setData5(data, recvGlobal.recvLength);
                    break;
                case 5:
                    ((SceneManager*)parentManager)->irManager->setData6(data, recvGlobal.recvLength);
                    break;
                case 6:
                    ((SceneManager*)parentManager)->irManager->setData7(data, recvGlobal.recvLength);
                    break;
                case 7:
                    ((SceneManager*)parentManager)->irManager->setData8(data, recvGlobal.recvLength);
                    break;
            }
            ((SceneManager*)parentManager)->storageManager->writeFile((String)"default/" + (dataIndex + 1) + (String)".txt", ((SceneManager*)parentManager)->irManager->toString(dataIndex + 1));
            ((Title*)elements[1])->text = "received!";
            return true;
        } else {
            // cancel with button down
            if (digitalRead(((SceneManager*)parentManager)->down) == 0) {
                ((Title*)elements[1])->text = "receive cancelled";
                ((SceneManager*)parentManager)->irManager->receiver->disableIRIn();
                return true;
            }
        }
    }
}

