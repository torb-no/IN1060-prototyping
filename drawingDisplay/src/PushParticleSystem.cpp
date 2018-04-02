//
//  PushParticleSystem.cpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 01/04/2018.
//

#include "PushParticleSystem.hpp"

PushParticleSystem::PushParticleSystem(float _xStartMin, float _xStartMax, float _yStartMin, float _yStartMax, float xBaseVelocity, float yBaseVelocity) {
    xStartMin = _xStartMin;
    xStartMax = _xStartMax;
    yStartMin = _yStartMin;
    yStartMax = _yStartMax;
    baseVelocity.x = xBaseVelocity;
    baseVelocity.y = yBaseVelocity;
    
    particles.assign(500, Particle());
    
    ofEnableAlphaBlending();
}

void PushParticleSystem::draw() {
    for (auto & p : particles) {
        if (p.energy > 0) {
            // TODO: Opacity and size based on energy
            // TODO: Replace with special effect image
            ofSetColor(255, 255, 255, p.energy * 20);
            ofDrawEllipse(p.position, 3, 3);
        }
    }
}

void PushParticleSystem::setPush(float amount) {
    // TODO: Set speed!
    speed = (int) std::abs(amount) * 2;
    if (speed < 1) speed = 1;
    
    int particlesToAdd = (int) std::abs(amount) * 7;
    int added = 0;
    for (auto & p : particles) {
        if (added >= particlesToAdd) break;
        
        if (p.energy <= 0) {
            p.energy = ofRandom(10.0f, 35.0f);
            p.position.x = ofRandom(xStartMin, xStartMax);
            p.position.y = ofRandom(yStartMin, yStartMax);
            added++;
        }
    }
}

void PushParticleSystem::update() {
    for (auto & p : particles) {
        if (p.energy > 0) {
            p.position += (baseVelocity * speed);
            p.energy -= 1.0f * speed;
        }
    }
}
