//
//  Painter.cpp
//  drawingDisplay
//
//  Created by Torbjørn Vik Lunde on 29/03/2018.
//

#include "Painter.hpp"

Painter::Painter() {
    pos.x = ofGetWidth() / 2;
    pos.y = ofGetHeight() / 2;
    movement =  { 0, 0, 0, 0 };
}

void Painter::update() {
    pos.x += movement.left;
    pos.x += movement.right;
    pos.y += movement.top;
    pos.y += movement.bottom;
}

void Painter::draw() {
    ofDrawEllipse(pos, 20, 20);
}

void Painter::setMovement(PainterMovement _movement) {
    movement = _movement;
}
