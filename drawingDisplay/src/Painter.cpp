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
}

void Painter::update() {
    prevPos = pos;
    pos.x += movement.fromLeft;
    pos.x += movement.fromRight;
    pos.y += movement.fromTop;
    pos.y += movement.fromBottom;
    
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
    

    
//    pushGradient.draw();
    
    // EDGE BOXES, FOR DEBUG PURPOSES
//    ofDrawRectangle(0, 0, ofGetWidth(), movement.fromTop*8);
//    ofDrawRectangle(ofGetWidth() + movement.fromRight*8, 0, -movement.fromRight*8, ofGetHeight());
//    ofDrawRectangle(0, ofGetHeight() + movement.fromBottom*8, ofGetWidth(), -movement.fromBottom*8);
//    ofDrawRectangle(0, 0, movement.fromLeft*8, ofGetHeight());
    
//    constexpr float gradientLength = 75;
//    drawPushGradient(0, 0, ofGetWidth(), gradientLength, topToDown, 255, 0, movement.fromTop);
//    drawPushGradient(ofGetWidth()-gradientLength, 0, gradientLength, ofGetHeight(), leftToRight, 0, 255, -movement.fromRight);
//    drawPushGradient(0, ofGetHeight()-gradientLength, ofGetWidth(), gradientLength, topToDown, 0, 255, -movement.fromBottom);
//    drawPushGradient(0, 0, gradientLength, ofGetHeight(), leftToRight, 255, 0, movement.fromLeft);
    
//    drawPushGradient(0, 0, gradientWidth, ofGetHeight(), xAxis, 0, 255, movement.fromLeft);
//    drawPushGradient(ofGetWidth()-gradientWidth, 0, gradientWidth, ofGetHeight(), xAxis, 0, 255, -movement.fromRight);
    
    ppsTopToDown.draw();
    ppsRightToLeft.draw();
    ppsBottomToUp.draw();
    ppsLeftToRight.draw();
    
    // DEBUG POINTER POINT
    ofSetColor(150, 150, 255, 255);
    ofDrawEllipse(pos, 10, 10);
}

void Painter::drawPushGradient(float xPos, float yPos, float w, float h, gradientDirection direction, int startOpacity, int endOpacity, float strength) {
    ofColor start, end;
    float strengthScaled = ofMap(strength, 0, 2, 0, 1);
    if (strengthScaled > 1) strengthScaled = 1;
    start.set(150, 150, 255, startOpacity * strengthScaled);
    end.set(150, 150, 255, endOpacity * strengthScaled);
    
    float xEnd = xPos + w;
    float yEnd = yPos + h;
    
    if (direction == leftToRight) {
        int steps = xEnd - xPos;
        for (float i=0; i<=steps; i++) {
            ofSetColor(start.getLerped(end, i/steps));
            ofDrawLine(xPos+i, yPos, xPos+i, yEnd);
        }
    }
    else if (direction == topToDown) {
        int steps = yEnd - yPos;
        for (float i=0; i<=steps; i++) {
            ofSetColor(start.getLerped(end, i/steps));
            ofDrawLine(xPos, yPos+i, xEnd, yPos+i);
        }
    }
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

