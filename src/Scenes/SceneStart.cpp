#include "Scenes/SceneStart.h"

void SceneStart::init() {
    Title* text = new Title(parentManager, "UIRC");
    text->screenCentre = true;
    addElement(text);
    
    Title* small = new Title(parentManager, "hold down to reset slots");
    small->setY(113);
    small->size = 1;
    addElement(small);
}