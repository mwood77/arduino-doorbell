#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int DURATION = 1100;
int RELAY_PIN = 7;

void setup() {
	Serial.begin(9600);
	mySwitch.enableReceive(0);  	// RF Receiver on interrupt 0 => pin #D2
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(7, OUTPUT);
	digitalWrite(7, HIGH);
}

void loop() {
	if (mySwitch.available() &&
		mySwitch.getReceivedBitlength() == 24) {
			tripRelay();
			mySwitch.resetAvailable();
	}
}

void busyLED(byte state) {	
	digitalWrite(LED_BUILTIN, state); 
}

void tripRelay() {
	busyLED(HIGH);
	digitalWrite(7, LOW);
	delay(DURATION);			// Doorbell is ringing
	digitalWrite(7, HIGH);
	delay(DURATION * 2);		// Cooldown
	busyLED(LOW);	
}
