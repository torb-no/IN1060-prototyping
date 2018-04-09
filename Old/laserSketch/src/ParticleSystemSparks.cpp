//
//  ParticleSystemSparks.cpp
//  laserSketch
//
//  Created by Torbjørn Vik Lunde on 19/03/2018.
//

#include "ParticleSystemSparks.hpp"

ParticleSystemSparks::ParticleSystemSparks() {
    particles.assign(110, ParticleSpark());
}

void ParticleSystemSparks::emit(float x, float y, int amount) {
    int added = 0;
    for (auto & p : particles) {
        if (p.energy <= 0) {
            p.reset(x, y);
            added++;
        }
        if (added >= amount) break;
    }
}

void ParticleSystemSparks::update() {
    for (auto & p : particles) {
        if (p.energy > 0) p.update();
    }
}

void ParticleSystemSparks::draw() {
    for (auto & p : particles) {
        if (p.energy > 0) p.draw();
    }
}
