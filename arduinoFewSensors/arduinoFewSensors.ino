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
            
void setup() {
  Serial.begin(9600);
}

// Serial communication format
// s T r1 rn R r1 rn B b1 bn L l1 lb \n

// Better format?
// D v1 , v2 ... , vn \n
// Where D is one of T, R, B, L (refering to top, right, bottom, left)
// and v1, v2, ... vn are sensor values on the same direction

void loop() {
  Serial.print("T");
  Serial.println(ultraTop.MeasureInCentimeters());
  
  Serial.print("R");
  Serial.println(ultraRight.MeasureInCentimeters());
  
  Serial.print("B");
  Serial.println(ultraBot.MeasureInCentimeters());
  
  Serial.print("L");
  Serial.println(ultraLeft.MeasureInCentimeters());

  // TODO: Ikke så bra teknikk, bruke annen timing greie
  // (ref. oblig om debounce)
  delay(50);
}
