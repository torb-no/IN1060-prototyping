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
    
    particles.assign(350, Particle());
    ballOfLight.load("ballOfLight.png");
}

void PushParticleSystem::draw() {
    // Display the particles
    for (auto & p : particles) {
        if (p.energy > 0) {
            ofSetColor(200, 200, 255, p.energy);
            ballOfLight.draw(p.position.x-ballOfLight.getWidth()/2, p.position.y-ballOfLight.getHeight()/2);
        }
    }
}

void PushParticleSystem::setPush(float amount) {
    // Add particles based on how much is pushed from that side
    if (amount < 0) amount *= -1;
    int particlesToAdd = (int) (amount * 2);
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
    // Update every particle in the particle system
    for (auto & p : particles) {
        if (p.energy > 0) {
            p.position += baseVelocity;
            p.energy -= 7;
        }
    }
}
