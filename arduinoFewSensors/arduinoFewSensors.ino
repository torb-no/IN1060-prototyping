#include <Ultrasonic.h>

// Code for Arduino UNO + Grove Board + 4 Grove Ultrasonic Distance Sensors

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
#define CMD_END 255

unsigned char mode;
            
void setup() {
  Serial.begin(9600);
  mode = CMD_TOP;
}

// State machine based format
// Any value defined in CMD_ is sets a mode or is a command
// All others are assumed to be arguments in current mode/command

void loop() {
  Serial.write(mode);
  switch (mode) {
    case CMD_TOP: 
      writeDistance(ultraTop.MeasureInCentimeters());
      mode = CMD_RIGHT;
      break;
    case CMD_RIGHT:
      writeDistance(ultraRight.MeasureInCentimeters();
      mode = CMD_BOTTOM;
      break;
    case CMD_BOTTOM:
      writeDistance(ultraBot.MeasureInCentimeters());
      mode = CMD_LEFT;
      break;
    case CMD_LEFT:
      writeDistance(ultraLeft.MeasureInCentimeters());
      mode = CMD_TOP;
      break;
  }
}

void writeDistance(long distance) {
  unsigned char distByte = ULTRA_LIMIT_LEN - min(distance, ULTRA_LIMIT_LEN);
  Serial.write(distByte);
}


