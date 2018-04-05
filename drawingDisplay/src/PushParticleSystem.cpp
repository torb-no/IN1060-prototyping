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
    
    particles.assign(250, Particle());
}

void PushParticleSystem::draw() {
    for (auto & p : particles) {
        if (p.energy > 0) {
            // TODO: Opacity and size based on energy
            // TODO: Replace with special effect image
            
            ofSetColor(0, 30, 255, p.energy);
            for (int i=0; i<3; i++) {
                float x = gen.getNormal(4, p.position.x);
                float y = gen.getNormal(4, p.position.y);
                ofDrawEllipse(x, y, 1, 1);
                ofDrawEllipse(x, y, 2, 2);
                ofDrawEllipse(x, y, 4, 4);
                ofDrawEllipse(x, y, 6, 6);
            }
            
            ofSetColor(200, 255, 255, p.energy);
            ofDrawEllipse(p.position, 2, 2);
            ofDrawEllipse(p.position, 4, 4);
            
        }
    }
}

void PushParticleSystem::setPush(float amount) {
//    speed = std::abs(amount) * 2;
//    if (speed < 0.25) speed = 0.25;
//    intensity = ofMap(speed, 0, 35, 0, 120);
    
    if (amount < 0) amount *= -1;
    int particlesToAdd = (int) (amount * 31);
    int added = 0;
    for (auto & p : particles) {
        if (added >= particlesToAdd) break;

        if (p.energy <= 0) {
            p.energy = ofRandom(100.0f, 255.0f);
            p.position.x = ofRandom(xStartMin, xStartMax);
            p.position.y = ofRandom(yStartMin, yStartMax);
            added++;
        }
    }
}

void PushParticleSystem::update() {
    for (auto & p : particles) {
        if (p.energy > 0) {
            p.position += baseVelocity;
            p.energy -= 5;
        }
    }
}
