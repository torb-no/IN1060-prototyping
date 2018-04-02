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

class Painter {
    ofVec2f pos;
    PushPull movement;
    PushParticleSystem ppsTopToDown;
    PushParticleSystem ppsRightToLeft;
    PushParticleSystem ppsBottomToUp;
    PushParticleSystem ppsLeftToRight;
public:
    Painter();
    void update();
    void draw();
    void setMovement(PushPull _movement);
    void setMovement(float top, float right, float bottom, float left);
};

#endif /* Painter_hpp */
