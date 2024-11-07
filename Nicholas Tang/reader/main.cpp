#include "mbed.h"

// main() runs in its own thread in the OS

#define FLASHING_RATE_MS 200ms

#define TEMPERATURE_LENGTH 4
#define THRESHOLD_TEMPERATURE 40
#define FLAG_ID 0x28

CAN* canBus;
CircularBuffer<CANMessage, 32> canqueue;
CANMessage msg;

DigitalOut led(LED1);

Thread thread;

volatile bool warning = false; // changes to true when sensor detects high temp
int16_t temperatures[TEMPERATURE_LENGTH];

void canRX();
void flashLED();
void updateWarning();

int main()
{
	canBus = new CAN(D10, D2, 500000);
	canBus->attach(canRX);

	thread.start(flashLED);

	while (true) {
		if (canqueue.empty()) {
			continue;
		}

		canqueue.pop(msg);

		if (msg.id != FLAG_ID) {
			continue;
		}

		//translate the byte array into ints
		for (int i = 0; i < TEMPERATURE_LENGTH; i++) {
			temperatures[i] = msg.data[2 * i];
			temperatures[i] = temperatures[i] << 8;
			temperatures[i] += msg.data[2 * i + 1];
		}

		//sets warning to true if any sensor reads 40+ celsius
		updateWarning();

		//Thread::sleep_for(10ms);
	}
}

void canRX() {
	CANMessage msg;

	if (canBus->read(msg)) {
		canqueue.push(msg);
	}
}

void flashLED() {
	while (true) {
		while (warning) {
			led = !led;
			ThisThread::sleep_for(FLASHING_RATE_MS);
		}
	}
}

void updateWarning() {
	for (int16_t temperature : temperatures) {
		if (temperature > THRESHOLD_TEMPERATURE) {
			warning = true;
			return;
		}
	}

	warning = false;
	return;
}

