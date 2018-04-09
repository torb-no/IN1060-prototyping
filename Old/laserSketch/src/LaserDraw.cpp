//
//  LaserDraw.cpp
//  laserSketch
//
//  Created by Torbjørn Vik Lunde on 19/03/2018.
//

#include "LaserDraw.hpp"
#include "ofMain.h"

LaserDraw::LaserDraw() {
    prevPos.x = ofGetWidth() / 2;
    prevPos.y = ofGetHeight() / 2;
    
    currPos.x = ofGetWidth() / 2;
    currPos.y = ofGetHeight() / 2;
    
    outerLight.load("outerLight.png");
    innerLight.load("innerLight.png");
    
    canvasColor.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    canvasMask.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    
    clear();
}

void LaserDraw::setPos(float x, float y) {
    prevPos.x = currPos.x;
    prevPos.y = currPos.y;
    
    currPos.x = x;
    currPos.y = y;
}

void LaserDraw::clear() {
    canvasMask.begin();
        ofClear(0);
        ofClearAlpha();
    canvasMask.end();
}

void LaserDraw::update() {
    moveDist = ofDist(prevPos.x, prevPos.y, currPos.x, currPos.y);
    
    // DRAW ON CANVAS
    ofSetLineWidth(1);
    canvasColor.begin();
        ofSetColor(255, 0, 0);
        ofDrawLine(prevPos, currPos);
        ofSetColor(255, 255, 255, 3);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    canvasColor.end();
    canvasMask.begin();
        ofSetColor(255);
        ofDrawLine(prevPos, currPos);
    canvasMask.end();
    canvasColor.getTexture().setAlphaMask(canvasMask.getTexture());
    
    
    // EMIT PARTICLES
    if (moveDist > 1) {
        float chanceOfParticle = moveDist / 750;
        for (float f=0; f<=1; f+=0.1) {
            float lx = ofLerp(prevPos.x, currPos.x, f);
            float ly = ofLerp(prevPos.y, currPos.y, f);
            
            if (chanceOfParticle > ofRandom(1)) {
                ps.emit(lx, ly, 1);
            }
        }
    }
    else {
        if (0.075 > ofRandom(1)) {
            ps.emit(currPos.x, currPos.y, 1);
        }
    }
    
    ps.update();
}

void LaserDraw::draw() {
    ofClear(0);
    ofSetColor(255);
    canvasColor.draw(0, 0);
    
    // LIGHTING EFFECTS
    float shinyness = moveDist * 2 + 75;
    float shimmer = ofRandom(50);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(255, 255, 255, shinyness + shimmer);
    outerLight.draw(currPos);
    innerLight.draw(currPos);
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    // RETAINED LIGHT EFFECT
    ofSetColor(255, 245, 121);
    ofSetLineWidth(2);
    ofDrawLine(prevPos, currPos);
    
    // POINT LIGHT
    ofSetColor(255);
    ofDrawLine(currPos, currPos);
    
    // DISPLAY PARTICLES
    ps.draw();
}
