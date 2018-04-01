//
//  PushPullVisualFeedback.hpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 31/03/2018.
//

#ifndef WindParticleSystem_hpp
#define WindParticleSystem_hpp

#include <stdio.h>
#include "ofMain.h"
#include <vector>

class PushPullVisualFeedback {
    struct Particle {
        ofVec2f position;
        ofVec2f velocity;
        ofVec2f acceleration;
        float energy;
        void update();
    };
public:
    enum Origin {
        top, right, bottom, left
    };
};

#endif /* WindParticleSystem_hpp */
