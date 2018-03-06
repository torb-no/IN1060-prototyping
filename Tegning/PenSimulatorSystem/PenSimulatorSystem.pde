import processing.serial.*;
import java.util.ArrayList;

Serial serial;
PenSimulator ps = new PenSimulator();

int xMove, yMove;

void setup() {
  //size(500, 500);
  fullScreen();
  setupSerial();
  ps.penBegin();
}

void draw() {
  readSerialData();
  ps.penMove(xMove, yMove);
  ps.draw();
}

void readSerialData() {
  if (serial.available() > 0) {
    String buffer = serial.readString();
    String lines[] = buffer.split("\n");
    if (lines.length <= 0) return;
    String l = lines[lines.length-1];
    
    // Do checks to make sure we have complete msg
    if (l.length() == 0) return;
    if (l.indexOf("x") <= -1) return;
    int endIndex = l.indexOf(";");
    if (endIndex <= -1) return;
    
    //println(l);
    int yIndex = l.indexOf("y");
    
    xMove = Integer.parseInt(l.substring(1, yIndex));
    yMove = Integer.parseInt(l.substring(yIndex+1, endIndex));
  }
}

void setupSerial() {
  // Attempts to add all Arduinos
  for (String s : Serial.list()) {
    // Assumes Arduino has "usbmodem" in their name
    if (s.indexOf("usbmodem") != -1) {
      try {
        serial = new Serial(this, s, 9600);
        break;
      } 
      catch (RuntimeException e) {
        // Ignore Exceptions pertaining to busy ports
        if (e.getMessage().indexOf("Port busy") == -1) {
          throw e;
        }
      }
    }
  }
}