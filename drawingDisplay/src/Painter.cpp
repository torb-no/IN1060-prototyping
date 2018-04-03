//
//  Painter.cpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 29/03/2018.
//

#include "Painter.hpp"

Painter::Painter() :
    movement(0, 0, 0, 0),
    prevPos(ofGetWidth() / 2, ofGetHeight() / 2),
    pos(ofGetWidth() / 2, ofGetHeight() / 2),
    ppsTopToDown(0, ofGetWidth(), -5, -5, 0, PPS_BASE_SPEED),
    ppsRightToLeft(ofGetWidth()-5, ofGetWidth()-5, 0, ofGetHeight(), -PPS_BASE_SPEED, 0),
    ppsBottomToUp(0, ofGetWidth(), ofGetHeight()+5, ofGetHeight()+5, 0, -PPS_BASE_SPEED),
    ppsLeftToRight(-5, -5, 0, ofGetHeight(), PPS_BASE_SPEED, 0)
{ }

void Painter::update() {
    prevPos = pos;
    pos.x += movement.fromLeft;
    pos.x += movement.fromRight;
    pos.y += movement.fromTop;
    pos.y += movement.fromBottom;
    
    canvas.update(prevPos, pos);
    
    ppsTopToDown.update();
    ppsRightToLeft.update();
    ppsBottomToUp.update();
    ppsLeftToRight.update();
}

void Painter::draw() {
    ofClear(0);
//    ofClear(255, 0, 0);
    
    canvas.draw();
    
    ofSetColor(255, 255, 255, 255);
    ofDrawEllipse(pos, 3, 3);
    
    // EDGE BOXES, FOR DEBUG PURPOSES
//    ofDrawRectangle(0, 0, ofGetWidth(), movement.fromTop*8);
//    ofDrawRectangle(ofGetWidth() + movement.fromRight*8, 0, -movement.fromRight*8, ofGetHeight());
//    ofDrawRectangle(0, ofGetHeight() + movement.fromBottom*8, ofGetWidth(), -movement.fromBottom*8);
//    ofDrawRectangle(0, 0, movement.fromLeft*8, ofGetHeight());
    
    ppsTopToDown.draw();
    ppsRightToLeft.draw();
    ppsBottomToUp.draw();
    ppsLeftToRight.draw();
}

void Painter::setMovement(PushPull _movement) {
    movement = _movement;
    ppsTopToDown.setPush(movement.fromTop);
    ppsRightToLeft.setPush(movement.fromRight);
    ppsBottomToUp.setPush(movement.fromBottom);
    ppsLeftToRight.setPush(movement.fromLeft);
}





