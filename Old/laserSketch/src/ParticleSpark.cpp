//
//  ParticleSpark.cpp
//  laserSketch
//
//  Created by Torbjørn Vik Lunde on 19/03/2018.
//

#include "ParticleSpark.hpp"
#include "ofMain.h"

void ParticleSpark::reset(float x, float y) {
    prevPos.set(x, y);
    pos.set(x, y);
    
    vel.x = ofRandom(-RANGE_VEL, RANGE_VEL) * 2;
    vel.y = ofRandom(-RANGE_VEL*2, RANGE_VEL) * 2;
    acc.x = ofRandom(-RANGE_ACC, RANGE_ACC);
    acc.y = ofRandom(-RANGE_ACC*2, RANGE_ACC);
    
    energy = ofRandom(ENERGY_MAX-150, ENERGY_MAX);
    energyFadeSpeed = 5;
}

void ParticleSpark::update() {
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    
    acc.y += 0.025;
    vel += acc;
    vel.limit(2.5);
    pos += vel;
    
    energy -= energyFadeSpeed;
}

void ParticleSpark::draw() {
    ofSetLineWidth(2);
    color.setHsb(energy/6, 255, 255);
    ofSetColor(color);
    ofDrawLine(prevPos, pos);
}
