#include "List.h"
#include "Util.h"

List::~List() {

}

void List::addElement(ListElement* element) {
    elements[numElements] = element;
    numElements++;
}

void List::runSelected() {
    elements[selectedIndex]->onSelect();
}

void List::startCheck() {
    // ensure selection starts on option rather than title
    while (elements[selectedIndex]->type != 0 && selectedIndex < numElements) {
        selectedIndex++;
    }
    // set back to 0 if nothing other than titles
    if (selectedIndex == numElements) selectedIndex = 0;
}

void List::render(Adafruit_ST7735* screen) {
    displayOffset = ((unsigned int)floor(selectedIndex / 11.0f)) * 120;

    screen->setTextSize(1);
    for (int i = 0; i < numElements; i++) {
        switch(elements[i]->type) {
            case 0:
                screen->setTextColor(Util::RGB(255, 255, 255));
                break;
            case 1:
                screen->setTextColor(color);
                screen->drawFastHLine(0, (i * 11) + 10 - displayOffset, 160, color);
                break;
        }
        if (selectedIndex == i) {
            screen->setTextColor(Util::RGB(0, 0, 0));
            screen->fillRect(0, i * 11 - displayOffset, 160, 11, Util::RGB(255, 255, 255));
        }
        screen->setCursor(2, (i * 11) + 2 - displayOffset);
        screen->println(elements[i]->text);
    }
}

bool List::up() {
    if (selectedIndex == 0) return false;
    unsigned char startVal = selectedIndex;;
    selectedIndex--;
    while (selectedIndex > 0 && elements[selectedIndex]->type != 0) {
        selectedIndex--;
    }
    if (elements[selectedIndex]->type != 0) {
        selectedIndex = startVal;
        return false;
    }
    return true;
}

bool List::down() {
    if (selectedIndex == numElements - 1) return false;
    unsigned char startVal = selectedIndex;
    selectedIndex++;
    while (selectedIndex < numElements - 1 && elements[selectedIndex]->type != 0) {
        selectedIndex++;
    }
    if (elements[selectedIndex]->type != 0) {
        selectedIndex = startVal;
        return false;
    }
    return true;
}