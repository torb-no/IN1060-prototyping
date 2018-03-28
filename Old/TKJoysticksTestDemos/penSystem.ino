/* Informal interface for pen system: *
 *  void penBegin(): does whatever need to get going
 *  void penMove(int x, int y): do a relative movement
*/

// SCREEN SIMULATION IMPLEMENTATION
// This implementation sends signals to a screen
// based plotter simulator

void penBegin() {
  Serial.begin(9600);
}

// Do pen movements.
// Change this for physical movement when ready
void penMove(int x, int y) {
  Serial.print("x");
  Serial.print(x);
  Serial.print("y");
  Serial.print(y);
  Serial.println(";");
  delay(10);
}
