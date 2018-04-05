//
//  PushParticleSystem.hpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 01/04/2018.
//

#ifndef PushParticleSystem_hpp
#define PushParticleSystem_hpp

#include <stdio.h>
#include "ofMain.h"
#include <vector>
#include "PushPull.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>
#include "ofxEasing.h"

using namespace ofxeasing;

#define PPS_BASE_SPEED 3

class PushParticleSystem {
    struct Particle {
        ofVec2f position;
        int energy;
    };
    
    vector<Particle> particles;
    float xStartMin, xStartMax;
    float yStartMin, yStartMax;
    ofVec2f baseVelocity;
    float intensity;
    float speed;
public:
    PushParticleSystem(float _xStartMin, float _xStartMax, float _yStartMin, float _yStartMax, float xBaseVelocity, float yBaseVelocity);
    void draw();
    void setPush(float amount);
    void update();
};

#endif /* PushParticleSystem_hpp */
