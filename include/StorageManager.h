#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include <SPI.h>
#include <SD.h>

class StorageManager {
public:
    StorageManager(unsigned int chipSelect);
    int chipSelect;

    unsigned int init();

    bool sdCardPresent = true;

    String readFile(String filePath);
    boolean writeFile(String filePath, String newContent);
    boolean appendFile(String filePath, String appendContent);
    boolean exists(String filePath);
};

#endif