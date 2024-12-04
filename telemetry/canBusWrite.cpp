
#include "mbed.h"
#include <cstdint>

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

struct tempMessage {
    uint16_t temps[4];

};

tempMessage msgs[4] = {
    {0x0023, 0x0025, 0x0026, 0x0020}, 
    {0x002A, 0x0021, 0x001E, 0x001F}, // 0x002A is the temperature reading > 40
    {0x0027, 0x001E, 0x0024, 0x0023}, // you can use ints/floats for temps dummy
    {0x001C, 0x001D, 0x001F, 0x0024} // ints w/scaling factors
};

int main()
{
    AnalogIn IN(A2);


    DigitalOut SEL1(D3); //SELECTION 1
    DigitalOut SEL2(D4); //SELECTION 2
    DigitalOut SEL3(D5); //SELECTION 3
    DigitalOut SEL4(D6); //SELECTION 4

    CAN* canBus;
    canBus = new CAN(D10, D2, 500000);

    float dataFloat;
    int dataInt;

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
                    dataFloat = IN.read();
                    break;
                case 1:
                    dataFloat = IN.read();
                    break;
                case 2:
                    dataFloat = IN.read();
                    break;
                case 3:
                    dataFloat = IN.read();
                    break;
                case 4:
                    dataFloat = IN.read();
                    break;
                case 5:
                    dataFloat = IN.read();
                    break;
                case 6:
                    dataFloat = IN.read();
                    break;
                case 7:
                    dataFloat = IN.read();
                    break;
                case 8:
                    dataFloat = IN.read();
                    break;
                case 9:
                    dataFloat = IN.read();
                    break;
                case 10:
                    dataFloat = IN.read();
                    break;
                case 11:
                    dataFloat = IN.read();
                    break;
                case 12:
                    dataFloat = IN.read();
                    break;
                case 13:
                    dataFloat = IN.read();
                    break;
                case 14:
                    dataFloat = IN.read();
                    break;
                default:
                    break;
                
            }
            char ArrayChars[2];
            
            /// tempChecker.id = 0x1a4; // this is a dummy ID; not really sure what the actual ID would be when writing
            for (int i = 0; i < 4; i++) {
                printf("Inside 1st for loop");
                for (int j = 0; j < 4; j++) {
                    printf("Inside 2nd for loop");
                    ArrayChars[0] = msgs[i].temps[j] >> 8;
                    ArrayChars[1] = msgs[i].temps[j];
                    canBus->write(CANMessage(0x1a4, ArrayChars, 2));
                }
                
            }

            ThisThread::sleep_for(25ms);
        }
    }
}

