/*
 * ARDUINO: LCD
 * D8:      RESET
 * D9:      A0
 * D10:     CS
 * D11:     SDA
 * D13:     SCK
 * 3.3v:    LED, IR LED + reciever VCC
 * GND:     GND
 * 5v:      TFT VCC
 * 
 * D12: upButton
 * D7: leftButton
 * D6: downButton
 * D5: reciever dat
 * D4: rightButton
 * 
 * D3: IR LED DAT
 * 
 * A0: controlPot
 * 
 * ORDER ON BREADBOARD: up, down, left, right
 */


/*
 * version 2 time
 * feather m0: screen
 * D11:        A0
 * D10:        CS
 * MOSI:       SDA
 * SCK:        SCK
 * 3V3:        LED
 * 3V3:        VCC
 * GND:        GND
 * RST:        RESET
 * 
 * feather m0: LED
 * GND:        GND
 * USB:        VCC
 * D9:         DAT
 * 
 * feather m0: recv
 * GND:        GND
 * 3V3:        VCC
 * D5:         DAT
 * 
 * A0: pot (3v3-gnd)
 */

#include <Arduino.h>

#include "IRManager.h"

#include "SceneManager.h"
#include "StorageManager.h"
#include "Util.h"

#include "Scenes/SceneStart.h"

#ifndef LED_BUILTIN 
#define LED_BUILTIN 13
#endif

#define TFT_CS 10
#define TFT_RST -1
#define TFT_DC 11

#define BTN_UP 6
#define BTN_DOWN 12
#define BTN_LEFT A1
#define BTN_RIGHT 13
#define POT_CRTL A0

#define BG_COLOR Util::RGB(255, 0, 0)
#define FG_COLOR ST77XX_WHITE

Adafruit_ST7735* tft = new Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

IRManager* irManager = new IRManager();

SceneManager manager(tft, BTN_UP, BTN_DOWN, BTN_LEFT, BTN_RIGHT, irManager);

StorageManager* storageManager = new StorageManager(4);

SceneStart* sceneStart = new SceneStart((unsigned int)&manager);

void setup() {
    Serial.begin(115200);
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_LEFT, INPUT_PULLUP);
    pinMode(BTN_RIGHT, INPUT_PULLUP);
    tft->initR(INITR_BLACKTAB);
    tft->setRotation(1);
    
    manager.storageManager = storageManager;
    manager.storageManager->init();

    // setup ir manager carrier frequency
    manager.irManager->setIRFreq(manager.storageManager->readFile("settings/cFreq.txt").toInt());
    
    if (manager.irManager->irFreq == 0) {
        manager.storageManager->sdCardPresent = false;
        manager.irManager->irFreq = 36;
    }

    manager.setNextScene(new SceneStart((unsigned int)&manager));
    manager.toNextScene();
    if (manager.storageManager->sdCardPresent) {
        manager.render();
        delay(1000);
        if (digitalRead(manager.down) == 0) {
            // reset slots
            ((Title*)manager.currentScene->elements[1])->text = "resetting...";
            for (int i = 0; i < 8; i++) {
                manager.storageManager->writeFile((String)"default/" + (i + 1) + (String)".txt", "");
            }
            ((Title*)manager.currentScene->elements[1])->text = "reset slots";
            manager.render();
        } else {
            ((Title*)manager.currentScene->elements[1])->text = "";
            manager.render();
        }
    } else {
        ((Title*)manager.currentScene->elements[1])->text = "";
        manager.render();
    }

    //Util::drawGrid(tft, 10);

    manager.init();

    manager.setNextScene(new SceneMainMenu((unsigned int)&manager));
    manager.toNextScene();
    manager.setupComplete = true;
}

void loop() {
    while (true) {
        manager.render();
        bool buttonProcessed = false;
        while (!buttonProcessed) {
            manager.currentScene->manageInput(&buttonProcessed);
        }
        delay(150);
    }
}