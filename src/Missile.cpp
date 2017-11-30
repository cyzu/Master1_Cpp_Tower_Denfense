//
//  Missile.cpp
//  generical_libGraphProject
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 27/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#include "Missile.h"
#include <iostream>
#include <unistd.h>

Missile::Missile(const float x_, const float y_, const float v, const float vposX_){
    x = x_;
    y = y_;
    vector = v * 0.03;
    vposX = vposX_/100;
    missileSuiv = NULL;
}

Missile::Missile(Missile *m, const float x_, const float y_, const float v, const float vposX_){
    x = x_;
    y = y_;
    vector = v * 0.03;
    vposX = vposX_;
    missileSuiv = m;
}

Missile::Missile(const Missile &m){
    x = m.x;
    y = m.y;
    vector = m.vector;
    
    missileSuiv = m.missileSuiv;
}

Missile::~Missile(){
    delete missileSuiv;
    missileSuiv = NULL;
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

Missile* Missile::getMissileSuiv(){ return missileSuiv; }

void Missile::setX(const float x_){
    x = x_;
}

void Missile::setY(const float y_){
    y = y_;
}

void Missile::setMissileSuiv(Missile *m){
    missileSuiv = m;
}

void Missile::draw(){
    Missile *missileCourant = this;
    
    while (missileCourant != NULL){
        GraphicPrimitives::drawLine2D(x, y, x+vector, y, r, g, b);
        missileCourant = missileCourant->missileSuiv;
    }
}

void Missile::tick(){
    setX(getX()+getVposX());
}


