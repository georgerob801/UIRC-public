#include "StorageManager.h"

StorageManager::StorageManager(unsigned int chipSelect) {
    this->chipSelect = chipSelect;
}

unsigned int StorageManager::init() {
    if (!SD.begin(this->chipSelect)) return -1;
    return 0;
}

boolean StorageManager::exists(String filePath) {
    return SD.exists(filePath);
}

String StorageManager::readFile(String filePath) {
    File file = SD.open(filePath, FILE_READ);
    if (file) {
        String content = "";
        while (file.available()) {
            content += file.readString();
        }
        file.close();
        return content;
    } else {
        return "death";
    }
}

boolean StorageManager::writeFile(String filePath, String newContent) {
    // delete file if it already exists (essentially clearing it)
    if (SD.exists(filePath)) if (!SD.remove(filePath)) return false;
    
    File file = SD.open(filePath, FILE_WRITE);
    if (file) {
        file.print(newContent);
        file.close();
        return true;
    } else {
        return false;
    }
}

boolean StorageManager::appendFile(String filePath, String appendContent) {
    File file = SD.open(filePath, FILE_WRITE);
    if (file) {
        file.print(appendContent);
        file.close();
        return true;
    } else {
        return false;
    }
}