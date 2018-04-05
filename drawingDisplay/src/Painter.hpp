//
//  Painter.hpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 29/03/2018.
//

#ifndef Painter_hpp
#define Painter_hpp

#include <stdio.h>
#include "ofMain.h"
#include "PushPull.hpp"
#include "PushParticleSystem.hpp"
#include "GlowingCanvas.hpp"

class Painter {
    ofVec2f pos;
    ofVec2f prevPos;
    PushPull movement;
    GlowingCanvas canvas;
    
    
    PushParticleSystem ppsTopToDown;
    PushParticleSystem ppsRightToLeft;
    PushParticleSystem ppsBottomToUp;
    PushParticleSystem ppsLeftToRight;
    
    enum gradientDirection {
        leftToRight, topToDown
    };
    
    void drawPushGradient(float x, float y, float w, float h, gradientDirection direction, int startOpacity, int endOpacity, float strength);
public:
    Painter();
    void update();
    void draw();
    void setMovement(PushPull _movement);
    void setMovement(float top, float right, float bottom, float left);
    void clear();
};

#endif /* Painter_hpp */
