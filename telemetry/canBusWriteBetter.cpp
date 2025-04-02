
#include "mbed.h"
#include <cstdio>
#include <cstdint>

// main() runs in its own thread in the OS

CAN* canBus;

DigitalOut SEL1(D3); //SELECTION 1
DigitalOut SEL2(D4); //SELECTION 2
DigitalOut SEL3(D5); //SELECTION 3
DigitalOut SEL4(D6); //SELECTION 4
AnalogIn IN(A2);
DigitalOut led1(D13);


struct telemetry {
    uint16_t steering;
    uint16_t rearBrakePressure;
    uint16_t frontBrakePressure;

    uint16_t wheelSpeedFR;
    uint16_t suspensionTravelFR;
    uint16_t strainFR;

    uint16_t wheelSpeedFL;
    uint16_t suspensionTravelFL;
    uint16_t strainFL;
    
    uint16_t wheelSpeedBR;
    uint16_t suspensionTravelBR;
    uint16_t strainBR;
    
    uint16_t wheelSpeedBL;
    uint16_t suspensionTravelBL;
    uint16_t strainBL;
};
telemetry tData;

EventQueue sendQueue(32 * EVENTS_EVENT_SIZE);
void initIO();

void send()
{
    CANMessage steerBrake;
    steerBrake.id = 0x1A4; // it sees this too!
    steerBrake.len = 6;
    steerBrake.data[0] = tData.steering;
    steerBrake.data[1] = tData.steering >> 8;
    steerBrake.data[2] = tData.rearBrakePressure;
    steerBrake.data[3] = tData.rearBrakePressure >> 8;
    steerBrake.data[4] = tData.frontBrakePressure;
    steerBrake.data[5] = tData.frontBrakePressure >> 8;
    canBus->write(steerBrake);

    CANMessage FR;
    FR.id = 0x224; // it sees this too!!
    FR.len = 6;
    FR.data[0] = tData.suspensionTravelFR;
    FR.data[1] = tData.suspensionTravelFR >> 8;
    FR.data[2] = tData.strainFR;
    FR.data[3] = tData.strainFR >> 8;
    FR.data[4] = tData.wheelSpeedFR;
    FR.data[5] = tData.wheelSpeedFR >> 8;
    canBus->write(FR);

    CANMessage FL; // it sees this!!!
    FL.id = 0x2A4;
    FL.len = 6;
    FL.data[0] = tData.suspensionTravelFL;
    FL.data[1] = tData.suspensionTravelFL >> 8;
    FL.data[2] = tData.strainFL;
    FL.data[3] = tData.strainFL >> 8;
    FL.data[4] = tData.wheelSpeedFL;
    FL.data[5] = tData.wheelSpeedFL >> 8;
    canBus->write(FL);

    CANMessage BR;
    BR.id = 0x324;
    BR.len = 6;
    BR.data[0] = tData.suspensionTravelBR;
    BR.data[1] = tData.suspensionTravelBR >> 8;
    BR.data[2] = tData.strainBR;
    BR.data[3] = tData.strainBR >> 8;
    BR.data[4] = tData.wheelSpeedBR;
    BR.data[5] = tData.wheelSpeedBR >> 8;
    canBus->write(BR);

    CANMessage BL;
    BL.id = 0x3A4;
    BL.len = 6;
    BL.data[0] = tData.suspensionTravelBL;
    BL.data[1] = tData.suspensionTravelBL >> 8;
    BL.data[2] = tData.strainBL;
    BL.data[3] = tData.strainBL >> 8;
    BL.data[4] = tData.wheelSpeedBL;
    BL.data[5] = tData.wheelSpeedBL >> 8;
    canBus->write(BL);
}
int main(int, char**)
{
    initIO();
    int send_id = sendQueue.call_every(10ms, &send);

    while (true) {

        //iterate through all sensors
        for (int i = 0; i < 15; i++) {
            printf("Inside program");
            SEL1.write( ((i >> 0) & 1) ); // 1
            SEL2.write( ((i >> 1) & 1) ); // 2
            SEL3.write( ((i >> 2) & 1) ); // 4
            SEL4.write( ((i >> 3) & 1) ); // 8

            ThisThread::sleep_for(1ms);

            switch(i) {
                case 0:
                    tData.steering = IN.read_u16();
                    break;
                case 1:
                    tData.rearBrakePressure = IN.read_u16();
                    break;
                case 2:
                    tData.frontBrakePressure = IN.read_u16();
                    break;
                case 3:
                    tData.wheelSpeedFR = IN.read_u16();
                    break;
                case 4:
                    tData.suspensionTravelFR = IN.read_u16();
                    break;
                case 5:
                    tData.strainFR = IN.read_u16();
                    break;
                case 6:
                    tData.wheelSpeedFL = IN.read_u16();
                    break;
                case 7:
                    tData.suspensionTravelFL = IN.read_u16();
                    break;
                case 8:
                    tData.strainFL = IN.read_u16();
                    break;
                case 9:
                    tData.wheelSpeedBR = IN.read_u16();
                    break;
                case 10:
                    tData.suspensionTravelBR = IN.read_u16();
                    break;
                case 11:
                    tData.strainBR = IN.read_u16();
                    break;
                case 12:
                    tData.wheelSpeedBL = IN.read_u16();
                    break;
                case 13:
                    tData.suspensionTravelBL = IN.read_u16();
                    break;
                case 14:
                    tData.strainBL = IN.read_u16();
                    break;
                default:
                    break;    
            }
            
            
        }
        sendQueue.dispatch_once();
            printf("CAN Message sent%u\n", send_id);

            ThisThread::sleep_for(1ms);
    }
}
void initIO() {
    canBus = new CAN(PA_11, PA_12, 500000); //Frequency either needs to be set for both sides or neither side
}
