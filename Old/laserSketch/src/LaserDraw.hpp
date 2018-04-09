//
//  LaserDraw.hpp
//  laserSketch
//
//  Created by Torbjørn Vik Lunde on 19/03/2018.
//

#ifndef LaserDraw_hpp
#define LaserDraw_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ParticleSystemSparks.hpp"

class LaserDraw {
public:
    LaserDraw();
    void setPos(float x, float y);
    void clear();
    void update();
    void draw();
    
private:
    ofVec2f prevPos;
    ofVec2f currPos;
    
    ofFbo canvasColor;
    ofFbo canvasMask;
    
    ParticleSystemSparks ps;
    
    ofImage innerLight;
    ofImage outerLight;
    
    float moveDist = 0;
};

#endif /* LaserDraw_hpp */
