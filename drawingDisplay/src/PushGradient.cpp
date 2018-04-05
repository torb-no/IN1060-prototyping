//
//  PushGradient.cpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 04/04/2018.
//

#include "PushGradient.hpp"

PushGradient::PushGradient() {
    ofColor start, end;
//    float strengthScaled = ofMap(strength, 0, 1.5, 0, 255);
    start.set(150, 150, 255, 255);
    end.set(150, 150, 255, 0);
    
    drawPushGradient(ofGetWidth(), gradLength, topGradient, topToDown, 0, 255);
    
}

void PushGradient::setPush(PushPull push) {
    
}

void PushGradient::draw() {
    ofSetColor(255, 255, 255, 255);
    topGradient.draw(0,0);
}

void PushGradient::drawPushGradient(int width, int height, ofImage & gradCanvas, gradientDirection direction, int startOpacity, int endOpacity) {
//    gradCanvas.allocate(width, height, OF_IMAGE_COLOR_ALPHA);
//
//    ofPixels & p = gradCanvas.getPixels();
//    ofColor start, end;
//    start.set(150, 150, 255, 150);
//    end.set(150, 150, 255, 255);
//
//    switch (direction) {
//        case topToDown:
//            for (int y=0; y<=height; y++) {
//                ofColor lineCol = start.getLerped(end, ofMap(y, 0, height, 0, 255));
////                ofSetColor(start.getLerped(end, ofMap(y, 0, height, 0, 1)));
//                for (int x=0; x<=width; x++) {
//                    p.setColor(x, y, lineCol);
//                }
//            }
//            break;
//        case leftToRight:
//            break;
//    }

    
    //    ofColor start, end;
    //    float strengthScaled = ofMap(strength, 0, 1.5, 0, 255);
    //    start.set(150, 150, 255, 0);
    //    end.set(150, 150, 255, 255);
    
    //    float xEnd = xPos + w;
    //    float yEnd = yPos + h;
    
    
    
    
    //    if (axis == xAxis) {
    //        float xEnd = xPos+w;
    //        for (float x=xPos; x<=xEnd; x++) {
    //            //                ofSetColor(150, 150, 255, ofMap(i, 0, 100, startOpacity, endOpacity) * strengthScaled);
    ////            ofSetColor(end.getLerped(start, i/xEnd));
    ////            ofDrawLine(i, y, i+h, xEnd);
    //            ofDrawLine(x, yPos, x, float y2)
    //        }
    //    }
    //    else if (axis == yAxis) {
    //
    //    }
    
    //    switch (axis) {
    //        case xAxis:
    //
    //            break;
    ////        case yAxis:
    ////            break;
    //    }
    //
    //    for (int x=0; x<100; x++) {
    //        ofSetColor(150, 150, 255, strength - x*2.55);
    //        ofDrawLine(x, 0, x, ofGetHeight());
    //    }
}
