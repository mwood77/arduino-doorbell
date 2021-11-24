// // Radiohead Amplitude shift keying library
// #include <RH_ASK.h>
// // Serial peripheral interface
// #include <SPI.h>

// RH_ASK rf_driver;

// uint16_t data;

// void setup() {
// 	// rf_driver.init();
// 	Serial.begin(9600);

// 	if (!rf_driver.init()) {
// 		Serial.print("rf_driver failed in initialize");
// 	} else {
// 		Serial.print("device ready to receive");
// 	}

// }

// void loop() {
// 	// uint8_t buffer[100]; //dunno how big - clean it
// 	uint8_t dataLength = sizeof(data);
// 	// uint8_t bufferLength = sizeof(buffer);

// 	// if (rf_driver.recv(buffer, &bufferLength)) {
// 	if ( rf_driver.recv((uint8_t*)&data, &dataLength) && dataLength == sizeof(data)) {
// 		uint16_t message = data;
// 		Serial.print("message received: ");
// 		Serial.println(data);
// 	} else {
// 		Serial.println(rf_driver.recv((uint8_t*)&data, &dataLength) && dataLength == sizeof(data));
// 	}
	

// }




#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    
    Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );

    mySwitch.resetAvailable();
  }
}