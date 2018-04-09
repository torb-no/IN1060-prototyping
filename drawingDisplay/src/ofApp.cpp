#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    for (auto & s : serial.getDeviceList()) {
        cout << s.getDeviceName() << endl;
        // Assume that the first we find that starts with
        // tty.usbmodem we find is the Arduino
        if (s.getDeviceName().find("tty.usbmodem") == 0) {
            serial.setup(s.getDeviceID(), 9600);
            break;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    setMovementBasedOnUltrasonic();
    
    painter.update();
}

void ofApp::setMovementBasedOnUltrasonic() {
    unsigned char mode = CMD_NONE;
    bool dataReceived = false;
    
    while (serial.available() > 0) {
        dataReceived = true;
        unsigned char cmdOrVal = serial.readByte();
        
        switch (cmdOrVal) {
            case CMD_TOP:
                mode = CMD_TOP;
                push.fromTop = 0;
                break;
            case CMD_RIGHT:
                mode = CMD_RIGHT;
                push.fromRight = 0;
                break;
            case CMD_BOTTOM:
                mode = CMD_BOTTOM;
                push.fromBottom = 0;
                break;
            case CMD_LEFT:
                mode = CMD_LEFT;
                push.fromLeft = 0;
                break;
            case CMD_NONE:
                // do nothing
                break;
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
    
    if (dataReceived) {
        painter.setMovement(push);
    }
    
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
    
    if (key == ' ') {
        painter.clear();
    }
}

//--------------------------------------------------------------
void ofApp::setMovementBasedOnKeys() {
    painter.setMovement({
         ((float)ofGetKeyPressed('s')*0.25f + (float)ofGetKeyPressed(OF_KEY_DOWN) *1.75f  ),
        -((float)ofGetKeyPressed('a')*0.25f + (float)ofGetKeyPressed(OF_KEY_LEFT) *1.75f  ),
        -((float)ofGetKeyPressed('w')*0.25f + (float)ofGetKeyPressed(OF_KEY_UP)   *1.75f  ),
         ((float)ofGetKeyPressed('d')*0.25f + (float)ofGetKeyPressed(OF_KEY_RIGHT)*1.75f  )
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
