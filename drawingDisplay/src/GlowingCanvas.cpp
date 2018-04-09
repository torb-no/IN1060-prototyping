//
//  GlowingCanvas.cpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 02/04/2018.
//

#include "GlowingCanvas.hpp"

GlowingCanvas::GlowingCanvas() {
    glowCanvas.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    clear();
}

void GlowingCanvas::clear() {
    glowCanvas.begin();
    ofClear(0);
    glowCanvas.end();
}

void GlowingCanvas::update(ofVec2f prevPos, ofVec2f pos) {
    // Draw magic/galaxy -esque on the canvas
    
    // Draw in proportion to the movement
    int moveStrength = (int) ofDist(prevPos.x, prevPos.y, pos.x, pos.y) * 2;
    
    glowCanvas.begin();
    
    // Glow cloud / nebulae
    ofSetColor(0, 0, 150, 15);
    for (int i=0; i<moveStrength*5; i++) {
        float x = gen.getNormal(20, pos.x);
        float y = gen.getNormal(20, pos.y);
        float size = ofRandom(5, 10);
        ofDrawEllipse(x, y, size, size);
    }
    
    // Glowing sparks / stars
    ofSetColor(50, 150, 255, 50);
    for (int i=0; i<moveStrength*2; i++) {
        float x = gen.getNormal(5, pos.x);
        float y = gen.getNormal(5, pos.y);
        float size = ofRandom(1, 3);
        ofDrawEllipse(x, y, size, size);
    }
    
    glowCanvas.end();
}

void GlowingCanvas::draw() {
    ofSetColor(255,255,255,255);
    
    glowCanvas.draw(0, 0);
}
