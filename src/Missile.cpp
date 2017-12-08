//
//  Missile.cpp
//  TowerDefence project
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 27/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#include "Missile.h"
//#include <iostream>
//#include <unistd.h>

Missile::Missile(const float x_, const float y_, const float v, const float vposX_){
    x = x_;
    y = y_;
    vector = v * 0.03;
    vposX = vposX_/5;
}

Missile::Missile(const Missile &m){
    x = m.x;
    y = m.y;
    vector = m.vector;
    vposX = m.vposX/111;
}

Missile::~Missile(){
    
}

float Missile::getX(){
    return x;
}

float Missile::getY(){
    return y;
}

float Missile::getVector(){
    return vector;
}

float Missile::getVposX(){
    return vposX;
}

void Missile::setX(const float x_){
    x = x_;
}

void Missile::setY(const float y_){
    y = y_;
}

void Missile::draw(){
    GraphicPrimitives::drawLine2D(x, y, x+vector, y, r, g, b);
}

void Missile::tick(){
    setX(getX()+getVposX());
}


