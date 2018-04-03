//
//  GlowingCanvas.hpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 02/04/2018.
//

#ifndef GlowingCanvas_hpp
#define GlowingCanvas_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxGuassian.hpp"

class GlowingCanvas {
    ofFbo glowCanvas;
    ofFbo mainCanvas;
    ofxGuassian generator;
public:
    GlowingCanvas();
    void update(ofVec2f prevPos, ofVec2f pos);
    void draw();
    void clear();
};

#endif /* GlowingCanvas_hpp */
