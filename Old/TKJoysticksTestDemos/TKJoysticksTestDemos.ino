#include <TinkerKit.h>

#define DEAD_START 540
#define DEAD_END 670
#define CENTER_POINT 610

TKJoystick j1(I0, I1);
TKJoystick j2(I4, I5);

int x1 = 0;
int y1 = 0;
int x2 = 0;
int y2 = 0;
int x, y;

void setup() {
  penBegin();
}

void loop() {
  x1 = j1.readX();
  y1 = j1.readY();

  x2 = j2.readX();
  y2 = j2.readY();

  x = (x1 + x2) / 2;
  y = (y1 + y2) / 2;
  
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

