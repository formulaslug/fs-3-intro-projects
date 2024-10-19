#include "mbed.h"

// main() runs in its own thread in the OS

struct telemetry {
    double steering;
    double rearBrakePressure;
    double frontBrakePressure;

    double wheelSpeedFR;
    double suspensionTravelFR;
    double strainFR;

    double wheelSpeedFL;
    double suspensionTravelFL;
    double strainFL;
    
    double wheelSpeedBR;
    double suspensionTravelBR;
    double strainBR;
    
    double wheelSpeedBL;
    double suspensionTravelBL;
    double strainBL;
};
	

int main() {
    AnalogIn IN(A2);


    DigitalOut SEL1(D3); //SELECTION 1
    DigitalOut SEL2(D4); //SELECTION 2
    DigitalOut SEL3(D5); //SELECTION 3
    DigitalOut SEL4(D6); //SELECTION 4

    CAN* canBus;
    canBus = new CAN(D10, D2, 500000);

    float dataFloat;
    int dataInt;
    struct telemetry data;

    while (true) {

        //iterate through all sensors
        for (int i = 0; i < 15; i++) {
            SEL1.write( ((i >> 0) & 1) ); // 1
            SEL2.write( ((i >> 1) & 1) ); // 2
            SEL3.write( ((i >> 2) & 1) ); // 4
            SEL4.write( ((i >> 3) & 1) ); // 8


            switch(i) {
                case 0:
                    dataFloat = IN.read();
                    data.steering = dataFloat;
                    break;
                case 1:
                    dataFloat = IN.read();
                    data.rearBrakePressure = dataFloat;
                    break;
                case 2:
                    dataFloat = IN.read();
                    data.frontBrakePressure = dataFloat;
                    break;
                case 3:
                    dataFloat = IN.read();
                    data.wheelSpeedFR = dataFloat;
                    break;
                case 4:
                    dataFloat = IN.read();
                    data.suspensionTravelFR = dataFloat;
                    break;
                case 5:
                    dataFloat = IN.read();
                    data.strainFR = dataFloat;
                    break;
                case 6:
                    dataFloat = IN.read();
                    data.wheelSpeedFL = dataFloat;
                    break;
                case 7:
                    dataFloat = IN.read();
                    data.suspensionTravelFL = dataFloat;
                    break;
                case 8:
                    dataFloat = IN.read();
                    data.strainFL = dataFloat;
                    break;
                case 9:
                    dataFloat = IN.read();
                    data.wheelSpeedBR = dataFloat;
                    break;
                case 10:
                    dataFloat = IN.read();
                    data.suspensionTravelBR = dataFloat;
                    break;
                case 11:
                    dataFloat = IN.read();
                    data.strainBR = dataFloat;
                    break;
                case 12:
                    dataFloat = IN.read();
                    data.wheelSpeedBL = dataFloat;
                    break;
                case 13:
                    dataFloat = IN.read();
                    data.suspensionTravelBL = dataFloat;
                    break;
                case 14:
                    data.strainBL = dataFloat;
                    break;
                default:
                    break;
            }

            dataInt = *(int *) &dataFloat;
            
            CANMessage testMSG;
            testMSG.id = 0x1a4;

            testMSG.data[0] = dataInt;
            testMSG.data[1] = dataInt >> 8;
            testMSG.data[2] = dataInt >> 16;
            testMSG.data[3] = dataInt >> 24;

            canBus->write(testMSG);
        }
    }
}

