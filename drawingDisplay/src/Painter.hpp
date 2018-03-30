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

struct PainterMovement {
    float top, right, bottom, left;
    // TODO: flip/reverse method
};

class Painter {
    ofVec2f pos;
    PainterMovement movement;
public:
    Painter();
    void update();
    void draw();
    void setMovement(PainterMovement _movement);
    void setMovement(float top, float right, float bottom, float left);
};

#endif /* Painter_hpp */
