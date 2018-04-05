//
//  GlowingCanvas.cpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 02/04/2018.
//

#include "GlowingCanvas.hpp"

GlowingCanvas::GlowingCanvas() {
//    glowCanvas.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    mainCanvas.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    clear();
}

void GlowingCanvas::clear() {
//    glowCanvas.begin();
//    ofClear(0);
//    glowCanvas.end();
    
    mainCanvas.begin();
    ofClear(0,0,0,0);
    mainCanvas.end();
}

void GlowingCanvas::update(ofVec2f prevPos, ofVec2f pos) {
    int moveStrength = (int) ofDist(prevPos.x, prevPos.y, pos.x, pos.y) * 5;
    if (moveStrength < 1) moveStrength = 1;
    
//    glowCanvas.begin();
//
//    // Normal distribution noise glow
////    const float variance = 5;
////    for (int i=0; i<moveStrength; i++) {
////        ofSetColor(5*i, 5*i, 255, 100);
////        float x = generator.getNormal(variance, pos.x);
////        float y = generator.getNormal(variance, pos.y);
////        ofDrawEllipse(x, y, 5, 5);
////    }
//
//    // Line glow
////    for (int i=12; i>1; i -= 2) {
////        ofSetColor(i*10, i*10, 255);
////        ofSetLineWidth(i);
////        ofDrawLine(prevPos, pos);
////    }
////    ofSetLineWidth(1);
//
//    // Fade out (not working right)
//    ofSetColor(0,0,0,10);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
//    ofClearAlpha();
//
//    glowCanvas.end();
    
    mainCanvas.begin();
    
    ofSetColor(255, 255, 255, 150);
    for (int i=0; i<2; i++) {
        float x = gen.getNormal(3, pos.x);
        float y = gen.getNormal(3, pos.y);
//        ofDrawRectangle(x, y, 1, 1);
        ofDrawEllipse(x, y, 2, 2);
    }
    
    
    // SIMPLE LINE
//    ofSetColor(255,255,255,255);
//    ofDrawLine(prevPos, pos);
    
    ofClearAlpha();
    mainCanvas.end();
}

void GlowingCanvas::draw() {
    ofSetColor(255,255,255,255);
//    glowCanvas.draw(0, 0);
    mainCanvas.draw(0, 0);
}
