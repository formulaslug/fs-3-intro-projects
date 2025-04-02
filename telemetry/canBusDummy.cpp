
#include "mbed.h"
#include <cstdint>



int main() {
    printf("main()\n");

    CAN* canBus;
    canBus = new CAN(PA_11, PA_12, 500000);
    // float dataFloat;
    // int dataInt;
    // dataInt = *(int *) &dataFloat;

    while (true) {
        printf("program ran");
        CANMessage testMSG;
        testMSG.id = 0x1a4;
        testMSG.data[0] = 'C';
        testMSG.data[1] = 'O';
        testMSG.data[2] = 'L';
        testMSG.data[3] = 'E';
        canBus->write(testMSG);
        ThisThread::sleep_for(20ms);
        
    }
}
