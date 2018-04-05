//
//  PushGradient.hpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 04/04/2018.
//

#ifndef PushGradient_hpp
#define PushGradient_hpp

#include <stdio.h>
#include "ofMain.h"
#include "PushPull.hpp"

class PushGradient {
public:
    PushGradient();
    void setPush(PushPull push);
    void draw();
private:
    const float gradLength = 100;
    ofImage topGradient;
    
    enum gradientDirection {
        leftToRight, topToDown
    };
    
    void drawPushGradient(int width, int height, ofImage & gradCanvas, gradientDirection direction, int startOpacity, int endOpacity);
};

#endif /* PushGradient_hpp */
