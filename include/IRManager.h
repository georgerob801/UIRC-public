#ifndef IR_MANAGER_H
#define IR_MANAGER_H

#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>

#include <IRLibRecv.h> 

#define IR_RECV 5

class IRManager {
public:
    IRsendRaw* sender = new IRsendRaw();
    IRrecv* receiver = new IRrecv(IR_RECV);
    uint16_t* data1;
    uint16_t* data2;
    uint16_t* data3;
    uint16_t* data4;
    uint16_t* data5;
    uint16_t* data6;
    uint16_t* data7;
    uint16_t* data8;

    unsigned int irFreq = 36;
    void setIRFreq(unsigned int newFreq);

    String toString(unsigned int slot);
    bool fromString(String string, unsigned int slot);

    void loadSetFromFilePath(String filePath);

    unsigned int length1;
    unsigned int length2;
    unsigned int length3;
    unsigned int length4;
    unsigned int length5;
    unsigned int length6;
    unsigned int length7;
    unsigned int length8;

    void setData1(uint16_t* data, unsigned int length);
    void setData2(uint16_t* data, unsigned int length);
    void setData3(uint16_t* data, unsigned int length);
    void setData4(uint16_t* data, unsigned int length);
    void setData5(uint16_t* data, unsigned int length);
    void setData6(uint16_t* data, unsigned int length);
    void setData7(uint16_t* data, unsigned int length);
    void setData8(uint16_t* data, unsigned int length);

    void send1();
    void send2();
    void send3();
    void send4();
    void send5();
    void send6();
    void send7();
    void send8();
};

#endif