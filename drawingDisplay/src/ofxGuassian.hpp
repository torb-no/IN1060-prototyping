//
//  ofxGaussian.hpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 02/04/2018.
//

#ifndef ofxGuassian_hpp
#define ofxGuassian_hpp

#include <iostream>
#include "ofMain.h"

class ofxGuassian {
    
public:
    float nextGaussian();
    float getNormal(float standard, float mean);
    
private:
    bool haveNextNextGaussian = false;
    float nextNextGaussian;
    
};

#endif /* ofxGaussian_hpp */
