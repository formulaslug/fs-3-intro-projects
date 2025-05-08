#include "mbed.h"
int main() {
    printf("program ran\n");
    CAN* canBus;
    canBus = new CAN (PA_11, PA_12, 500000);
    while (true) {
        CANMessage msg;
        if (canBus->read(msg)) {
            printf("%x: %d%d%d%d%d%d\n", msg.id, msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5]);
        } else {
            printf("fail\n");
        }
    ThisThread::sleep_for(100ms);
    }
}
