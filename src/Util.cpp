#include "Util.h"

int Util::RGB(unsigned char r, unsigned char g, unsigned char b) {
    return int(( ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3) ));
}

void Util::drawGrid(Adafruit_ST7735* tft, int interval) {
    Serial.println(freeMemory());
    for (int x = 0; x <= tft->width(); x += interval) {
        tft->drawFastVLine(x, 0, tft->height(), Util::RGB(255, 0, 0));
    }

    for (int y = 0; y <= tft->height(); y += interval) {
        tft->drawFastHLine(0, y, tft->width(), Util::RGB(255, 0, 0));
    }
}

#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char *__brkval;
#endif  // __arm__

int Util::freeMemory() {
    char top;
#ifdef __arm__
    return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
    return &top - __brkval;
#else  // __arm__
    return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif  // __arm__
}