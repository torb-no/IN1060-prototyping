#include <TinkerKit.h>

#define DEAD_START 540
#define DEAD_END 670
#define CENTER_POINT 610

TKJoystick j1(I0, I1);

int x1 = 0;
int y1 = 0;

void setup() {
  // put your setup code here, to run once:
  penBegin();
}

void loop() {
  // put your main code here, to run repeatedly:
  x1 = j1.readX();
  y1 = j1.readY();
  
  penMove(joyToPenVal(x1), joyToPenVal(y1) * -1);
}

int joyToPenVal(int v) {
  if (DEAD_START < v && v < DEAD_END) {
    return 0;
  }
  else {
    return v - CENTER_POINT;
  }
  
}

