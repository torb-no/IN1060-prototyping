#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    serial.setup("/dev/tty.usbmodemFD121", 9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    setMovementBasedOnUltrasonic();
    
    painter.update();
}

void ofApp::setMovementBasedOnUltrasonic() {
    PushPull push = {0,0,0,0};
    unsigned char mode = CMD_NONE;
    
    while (serial.available() > 0) {
        unsigned char cmdOrVal = serial.readByte();
        
        switch (cmdOrVal) {
            case CMD_TOP: mode = CMD_TOP; break;
            case CMD_RIGHT: mode = CMD_RIGHT; break;
            case CMD_BOTTOM: mode = CMD_BOTTOM; break;
            case CMD_LEFT: mode = CMD_LEFT; break;
            // Urecognized values are assumed to be values
            default: // VALUE!
                switch (mode) {
                    case CMD_TOP:
                        push.fromTop += cmdOrVal * DISTANCE_MULTIPLIER;
                        break;
                    case CMD_RIGHT:
                        push.fromRight -= cmdOrVal * DISTANCE_MULTIPLIER;
                        break;
                    case CMD_BOTTOM:
                        push.fromBottom -= cmdOrVal * DISTANCE_MULTIPLIER;
                        break;
                    case CMD_LEFT:
                        push.fromLeft += cmdOrVal * DISTANCE_MULTIPLIER;
                        break;
                    // ignore if unknown mode is not set
                }
                break;
        }
        
    
    }
    
    painter.setMovement(push);
}

//--------------------------------------------------------------
void ofApp::draw(){
    painter.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    setMovementBasedOnKeys();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    setMovementBasedOnKeys();
}

//--------------------------------------------------------------
void ofApp::setMovementBasedOnKeys() {
    painter.setMovement({
         ((float)ofGetKeyPressed('s') + (float)ofGetKeyPressed(OF_KEY_DOWN)),
        -((float)ofGetKeyPressed('a') + (float)ofGetKeyPressed(OF_KEY_LEFT)),
        -((float)ofGetKeyPressed('w') + (float)ofGetKeyPressed(OF_KEY_UP)),
         ((float)ofGetKeyPressed('d') + (float)ofGetKeyPressed(OF_KEY_RIGHT))
    });
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
