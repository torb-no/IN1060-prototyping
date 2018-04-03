#include <Ultrasonic.h>

// Code for Arduino UNO + Grove Board + 4 (or more?) Ultrasonic Sensors

// VIKTIG!
// IKKE PLUG INN/UT ULTRALYD-SENSORER
// MENS ARDUINO-EN ER PAA!
// DE KAN BLI ODELAGT!

Ultrasonic ultraTop(3); // D3
Ultrasonic ultraBot(7); // D7
Ultrasonic ultraLeft(8); // D8
Ultrasonic ultraRight(6); // D6

#define ULTRA_LIMIT_LEN 35
#define CMD_MAX_VAL 250

#define CMD_TOP 251
#define CMD_RIGHT 252
#define CMD_BOTTOM 253
#define CMD_LEFT 254
#define CMD_END -255
            
void setup() {
  Serial.begin(9600);
}

// State machine based format
// Any value defined in CMD_ is sets a mode or is a command
// All others are assumed to be arguments in current mode/command

void loop() {
  Serial.write(CMD_TOP);
  writeDistance(ultraTop.MeasureInCentimeters());

  Serial.write(CMD_RIGHT);
  writeDistance(ultraRight.MeasureInCentimeters());

  Serial.write(CMD_BOTTOM);
  writeDistance(ultraBot.MeasureInCentimeters());

  Serial.write(CMD_LEFT);
  writeDistance(ultraLeft.MeasureInCentimeters());

//  Serial.write(CMD_END); // Do we need this?
//  delay(50);
}

void writeDistance(long distance) {
  unsigned char distByte = ULTRA_LIMIT_LEN - min(distance, ULTRA_LIMIT_LEN);
  Serial.write(distByte);
}


