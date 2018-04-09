//
//  ParticleSpark.hpp
//  laserSketch
//
//  Created by Torbjørn Vik Lunde on 19/03/2018.
//

#ifndef ParticleSpark_hpp
#define ParticleSpark_hpp

#include <stdio.h>
#include "ofMain.h"

#define ENERGY_MAX 255
#define RANGE_VEL 0.7
#define RANGE_ACC 0.05

class ParticleSpark {
public:
    ofVec2f prevPos;
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    
    float energy;
    float energyFadeSpeed;
    
    ofColor color;
    
    void reset(float x, float y);
    void update();
    void draw();
};

#endif /* ParticleSpark_hpp */
