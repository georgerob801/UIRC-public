#include "IRCodeManager.h"

IRCodeManager::IRCodeManager(unsigned int storageManager) {
    this->storageManager = (StorageManager*)storageManager;
}