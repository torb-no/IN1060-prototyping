//
//  GlowingCanvas.cpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 02/04/2018.
//

#include "GlowingCanvas.hpp"

GlowingCanvas::GlowingCanvas() {
    glowCanvas.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    mainCanvas.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    clear();
}

void GlowingCanvas::clear() {
    glowCanvas.begin();
//    ofSetColor(0);
    ofClear(0);
    glowCanvas.end();
    
    mainCanvas.begin();
    ofClear(0);
//    ofSetColor(0);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
//    ofClearAlpha();
    mainCanvas.end();
}

void GlowingCanvas::update(ofVec2f prevPos, ofVec2f pos) {
    int moveStrength = (int) ofDist(prevPos.x, prevPos.y, pos.x, pos.y) * 2;
//    if (moveStrength < 1) moveStrength = 1;
    
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
    
    glowCanvas.begin();
    ofSetColor(0, 0, 150, 15);
    for (int i=0; i<moveStrength*5; i++) {
        float x = gen.getNormal(20, pos.x);
        float y = gen.getNormal(20, pos.y);
        float size = ofRandom(5, 10);
        ofDrawEllipse(x, y, size, size);
    }
    
    ofSetColor(50, 150, 255, 50);
    for (int i=0; i<moveStrength*2; i++) {
        float x = gen.getNormal(5, pos.x);
        float y = gen.getNormal(5, pos.y);
        float size = ofRandom(1, 3);
        ofDrawEllipse(x, y, size, size);
    }
    
    
    glowCanvas.end();
    
    mainCanvas.begin();
    
//    ofSetColor(255, 150);
//    for (int i=0; i<moveStrength; i++) {
//        float x = gen.getNormal(2, pos.x) * 1.05;
//        float y = gen.getNormal(2, pos.y) * 1.05;
//        ofDrawEllipse(x, y, 2, 2);
//    }
//
    
    // SIMPLE LINE
//    ofSetColor(255,255,255,255);
//    ofDrawLine(prevPos, pos);
    
    ofClearAlpha();
    mainCanvas.end();
}

void GlowingCanvas::draw() {
    ofSetColor(255,255,255,255);
    glowCanvas.draw(0, 0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    mainCanvas.draw(0, 0);
    
//    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
}
