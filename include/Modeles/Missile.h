//
//  Missile.hpp
//  TowerDefence project
//
//  Created by Chloé BENSOUSSAN on 27/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//
#pragma once
#ifndef Missile_h
#define Missile_h

#include "GraphicPrimitives.h"

class Missile{
    private :
    
    float x, y, vector; //pour la longeur du missile (puissance)
    float vposX; // vecteur déplacement missiles (vitesse)
    const float r = 0.0f, g = 1.0f, b = 0.0f;
    
    public :
    
    Missile(const float x_, const float y_, const float v,  const float vposX_ /*= 1*/);
    Missile(const Missile &m);
    ~Missile();
    
    float getX();
    float getY();
    float getVector();
    float getVposX();
    
    void setX(const float x_);
    void setY(const float y_);
    
    void draw();
    void tick();
};

#endif /* Missile_h */
