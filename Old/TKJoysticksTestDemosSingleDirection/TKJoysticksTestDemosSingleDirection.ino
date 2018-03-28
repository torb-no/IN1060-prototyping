#include <TinkerKit.h>

#define DEAD_START 540
#define DEAD_END 670
#define CENTER_POINT 610

TKJoystick j1(I0, I1);
TKJoystick j2(I4, I5);

int x, y;

void setup() {
  penBegin();
}

void loop() {
  x = j1.readX();
  y = j2.readY();
  
  penMove(joyToPenVal(x), joyToPenVal(y) * -1);
}

int joyToPenVal(int v) {
  if (DEAD_START < v && v < DEAD_END) {
    return 0;
  }
  else {
    return v - CENTER_POINT;
  }
  
}

