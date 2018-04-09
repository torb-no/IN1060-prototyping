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
{
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    innerLight.load("innerCyanLight.png");
    outerLight.load("outerBlueLight.png");
    shineYouCrazyDiamond.load("shineYouCrazyDiamond.png");
}

void Painter::update() {
    prevPos = pos;
    pos.x += movement.fromLeft;
    pos.x += movement.fromRight;
    pos.y += movement.fromTop;
    pos.y += movement.fromBottom;
    
    // Make the pointer come out on the other side if it gets to the edge
    if (pos.x > ofGetWidth()) {
        prevPos.x = 0;
        pos.x = 0;
    }
    else if (pos.x < 0) {
        prevPos.x = ofGetWidth();
        pos.x = ofGetWidth();
    }
    if (pos.y > ofGetHeight()) {
        prevPos.y = 0;
        pos.y = 0;
    } 
    else if (pos.y < 0) {
        prevPos.y = ofGetHeight();
        pos.y = ofGetHeight();
    }
    
    // Update the canvas
    canvas.update(prevPos, pos);
    
    // Updage push particle sytems
    ppsTopToDown.update();
    ppsRightToLeft.update();
    ppsBottomToUp.update();
    ppsLeftToRight.update();
}

void Painter::draw() {
    ofClear(0);
    
    canvas.draw();
    
    ppsTopToDown.draw();
    ppsRightToLeft.draw();
    ppsBottomToUp.draw();
    ppsLeftToRight.draw();
    
    drawPositionPoint();
    
    // EDGE BOXES, FOR DEBUG PURPOSES
    //    ofDrawRectangle(0, 0, ofGetWidth(), movement.fromTop*8);
    //    ofDrawRectangle(ofGetWidth() + movement.fromRight*8, 0, -movement.fromRight*8, ofGetHeight());
    //    ofDrawRectangle(0, ofGetHeight() + movement.fromBottom*8, ofGetWidth(), -movement.fromBottom*8);
    //    ofDrawRectangle(0, 0, movement.fromLeft*8, ofGetHeight());
    
    // DEBUG POINTER POINT
    //    ofSetColor(150, 150, 255, 255);
    //    ofDrawEllipse(pos, 10, 10);
}

void Painter::setMovement(PushPull _movement) {
    movement = _movement;
    movement *= 1.5;
    ppsTopToDown.setPush(movement.fromTop);
    ppsRightToLeft.setPush(movement.fromRight);
    ppsBottomToUp.setPush(movement.fromBottom);
    ppsLeftToRight.setPush(movement.fromLeft);
}

void Painter::clear() {
    canvas.clear();
}

void Painter::drawPositionPoint() {
    // Draw shiny star to indicate position
    int moveStrength = (int) ofDist(prevPos.x, prevPos.y, pos.x, pos.y) * 3;
    if (moveStrength > 5) moveStrength = 5;
    
    ofSetColor(255, 255, 255, ofRandom(80, 120) + moveStrength * 10);
    outerLight.draw(pos.x-outerLight.getWidth()/2, pos.y-outerLight.getHeight()/2);
    
    ofSetColor(255, 255, 255, ofRandom(90,100) + moveStrength * 10);
    innerLight.draw(pos.x-innerLight.getWidth()/2, pos.y-innerLight.getHeight()/2);
    
    ofSetColor(255, 255, 255, ofRandom(40,60) + moveStrength * 5);
    shineYouCrazyDiamond.draw(pos.x-(shineYouCrazyDiamond.getWidth()/2), pos.y-(shineYouCrazyDiamond.getHeight()/2));
}








