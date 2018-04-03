#pragma once

#include "ofMain.h"
#include "Painter.hpp"
#include <iostream>

using std::cout;

#define CMD_TOP 251
#define CMD_RIGHT 252
#define CMD_BOTTOM 253
#define CMD_LEFT 254
#define CMD_NONE 255

#define DISTANCE_MULTIPLIER 0.25

class ofApp : public ofBaseApp {
    ofSerial serial;
    Painter painter;
public:
    void setup();
    void update();
    void draw();
    
    void setMovementBasedOnKeys();
    void setMovementBasedOnUltrasonic();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
};
