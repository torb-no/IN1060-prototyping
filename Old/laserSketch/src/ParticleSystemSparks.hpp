//
//  ParticleSystemSparks.hpp
//  laserSketch
//
//  Created by Torbjørn Vik Lunde on 19/03/2018.
//

#ifndef ParticleSystemSparks_hpp
#define ParticleSystemSparks_hpp

#include <stdio.h>
#include <vector>
#include "ofMain.h"
#include "ParticleSpark.hpp"

class ParticleSystemSparks {
    vector<ParticleSpark> particles;
    
public:
    ParticleSystemSparks();
    void emit(float x, float y, int amount);
    void update();
    void draw();
};

#endif /* ParticleSystemSparks_hpp */
