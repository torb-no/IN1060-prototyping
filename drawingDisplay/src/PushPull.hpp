//
//  PushPull.hpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 01/04/2018.
//

#ifndef PushPull_hpp
#define PushPull_hpp

#include <stdio.h>

struct PushPull {
    
    // Structure represents how much is "pushed" from a side
    
    float fromTop;
    float fromRight;
    float fromBottom;
    float fromLeft;
    
    PushPull() :
        fromTop(0),
        fromRight(0),
        fromBottom(0),
        fromLeft(0)
    {};
    
    PushPull(float fromTop, float fromRight, float fromBottom, float fromLeft) :
        fromTop(fromTop),
        fromRight(fromRight),
        fromBottom(fromBottom),
        fromLeft(fromLeft)
    {};
    
    void operator*=(const float multiplier) {
        fromTop *= multiplier;
        fromRight *= multiplier;
        fromBottom *= multiplier;
        fromLeft *= multiplier;
    };
};

#endif /* PushPull_hpp */
