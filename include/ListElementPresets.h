#ifndef LIST_ELEMENT_PRESETS_H
#define LIST_ELEMENT_PRESETS_H

#include "ListElement.h"

class ListElementPresets : public ListElement {
public:
    ListElementPresets(unsigned int manager, String display, String filePath) : ListElement(manager) {
        this->text = display;
        this->fileToLoad = filePath;
    }
    String fileToLoad;
    void onSelect();
};

#endif