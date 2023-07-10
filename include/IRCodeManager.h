#ifndef IR_CODE_MANAGER_H
#define IR_CODE_MANAGER_H

#include "StorageManager.h"

class IRCodeManager {
public:
    IRCodeManager(unsigned int storageManager);

    StorageManager* storageManager;
};

#endif