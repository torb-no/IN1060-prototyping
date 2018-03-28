#include <Ultrasonic.h>

// VIKTIG!
// IKKE PLUG INN/UT ULTRALYD-SENSORER
// MENS ARDUINO-EN ER PAA!
// DE KAN BLI ODELAGT!

#define ULTRA_LIMIT_LEN 35

Ultrasonic ultraTop(3); // D3
Ultrasonic ultraBot(7); // D7
Ultrasonic ultraLeft(8); // D8
Ultrasonic ultraRight(6); // D6
            
int x, y;

void setup() {
  penBegin();
}

void loop() {
  y = ultraToPenVal(ultraTop.MeasureInCentimeters(), 
                    ultraBot.MeasureInCentimeters());
  x = ultraToPenVal(ultraLeft.MeasureInCentimeters(),
                    ultraRight.MeasureInCentimeters());
  penMove(x, y);
}

int ultraToPenVal(long backwardsVal, long forwardsVal) {
  int d1 = ULTRA_LIMIT_LEN - min(backwardsVal, ULTRA_LIMIT_LEN);
  int d2 = ULTRA_LIMIT_LEN - min(forwardsVal, ULTRA_LIMIT_LEN);

  return (d2 - d1) * 15;
}

