#include "IRManager.h"
#include "SceneManager.h"

void IRManager::setIRFreq(unsigned int newFreq) {
    irFreq = newFreq;
}

String IRManager::toString(unsigned int slot) {
    String output = "";
    unsigned int length;
    uint16_t* data;
    switch(slot) {
        case 1:
            length = length1;
            data = data1;
            break;
        case 2:
            length = length2;
            data = data2;
            break;
        case 3:
            length = length3;
            data = data3;
            break;
        case 4:
            length = length4;
            data = data4;
            break;
        case 5:
            length = length5;
            data = data5;
            break;
        case 6:
            length = length6;
            data = data6;
            break;
        case 7:
            length = length7;
            data = data7;
            break;
        case 8:
            length = length8;
            data = data8;
            break;
        default:
            length = 0;
            break;
    }

    if (!data) return "";

    output += length;

    for (int i = 0; i < length; i++) {
        output += ",";
        output += data[i];
    }
    output += ",";

    return output;
}

bool IRManager::fromString(String string, unsigned int slot) {
    int lastComma = string.indexOf(",");
    if (lastComma == -1) return false;
    int length = string.substring(0, lastComma).toInt();
    int nextComma = string.indexOf(",", lastComma + 1);

    uint16_t* buffer = new uint16_t[length];

    for (unsigned int i = 0; nextComma != -1; i++) {
        buffer[i] = (uint16_t)string.substring(lastComma + 1, nextComma).toInt();
        lastComma = string.indexOf(",", lastComma + 1);
        nextComma = string.indexOf(",", lastComma + 1);
    }

    switch(slot) {
        case 1:
            setData1(buffer, length);
            break;
        case 2:
            setData2(buffer, length);
            break;
        case 3:
            setData3(buffer, length);
            break;
        case 4:
            setData4(buffer, length);
            break;
        case 5:
            setData5(buffer, length);
            break;
        case 6:
            setData6(buffer, length);
            break;
        case 7:
            setData7(buffer, length);
            break;
        case 8:
            setData8(buffer, length);
            break;
        default:
            return false;
    }

    return true;
}

void IRManager::setData1(uint16_t* data, unsigned int length) {
    delete[] data1;
    length1 = length;
    data1 = new uint16_t[length];
    memcpy(data1, data, sizeof(uint16_t*) * length);
}

void IRManager::setData2(uint16_t* data, unsigned int length) {
    delete[] data2;
    length2 = length;
    data2 = new uint16_t[length];
    memcpy(data2, data, sizeof(uint16_t*) * length);
}

void IRManager::setData3(uint16_t* data, unsigned int length) {
    delete[] data3;
    length3 = length;
    data3 = new uint16_t[length];
    memcpy(data3, data, sizeof(uint16_t*) * length);
}

void IRManager::setData4(uint16_t* data, unsigned int length) {
    delete[] data4;
    length4 = length;
    data4 = new uint16_t[length];
    memcpy(data4, data, sizeof(uint16_t*) * length);
}

void IRManager::setData5(uint16_t* data, unsigned int length) {
    delete[] data5;
    length5 = length;
    data5 = new uint16_t[length];
    memcpy(data5, data, sizeof(uint16_t*) * length);
}

void IRManager::setData6(uint16_t* data, unsigned int length) {
    delete[] data6;
    length6 = length;
    data6 = new uint16_t[length];
    memcpy(data6, data, sizeof(uint16_t*) * length);
}

void IRManager::setData7(uint16_t* data, unsigned int length) {
    delete[] data7;
    length7 = length;
    data7 = new uint16_t[length];
    memcpy(data7, data, sizeof(uint16_t*) * length);
}

void IRManager::setData8(uint16_t* data, unsigned int length) {
    delete[] data8;
    length8 = length;
    data8 = new uint16_t[length];
    memcpy(data8, data, sizeof(uint16_t*) * length);
}

void IRManager::send1() {
    sender->send(data1, length1, irFreq);
}
void IRManager::send2() {
    sender->send(data2, length2, irFreq);
}
void IRManager::send3() {
    sender->send(data3, length3, irFreq);
}
void IRManager::send4() {
    sender->send(data4, length4, irFreq);
}
void IRManager::send5() {
    sender->send(data5, length5, irFreq);
}
void IRManager::send6() {
    sender->send(data6, length6, irFreq);
}
void IRManager::send7() {
    sender->send(data7, length7, irFreq);
}
void IRManager::send8() {
    sender->send(data8, length8, irFreq);
}