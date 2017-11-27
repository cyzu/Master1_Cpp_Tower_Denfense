//
//  Missile.cpp
//  generical_libGraphProject
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 27/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#include "Missile.h"

Missile::Missile(const float x_, const float y_, const float v){
    x = x_;
    y = y_;
    vector = v;
    missileSuiv = NULL;
}

Missile::Missile(const float x_, const float y_, const float v, Missile *m){
    x = x_;
    y = y_;
    vector = v;
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

void Missile::setX(const float x_){
    x = x_;
}

void Missile::setY(const float y_){
    y = y_;
}

