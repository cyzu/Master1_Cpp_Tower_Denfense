//
//  Missile.hpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 27/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#ifndef Missile_h
#define Missile_h

#include "GraphicPrimitives.h"
#include <stdio.h>

class Missile{
    
    friend class Vaisseau;
    
    private :
    
    float x, y, vector; //pour la longeur du missile (puissance)
    float vposX; // vecteur déplacement missiles (vitesse)
    const float r = 0.0f, g = 1.0f, b = 0.0f;
    
    Missile *missileSuiv;
    
    public :
    
    Missile(const float x_, const float y_, const float v, const float vposX_ = 1);
    Missile(Missile *m, const float x_, const float y_, const float v, const float vposX_ = 1);
    Missile(const Missile &m);
    ~Missile();
    
    float getX();
    float getY();
    float getVector();
    float getVposX();
    
    Missile* getMissileSuiv();
    
    void setX(const float x_);
    void setY(const float y_);
    
    void setMissileSuiv(Missile *m);
    
    void draw();
    void tick();
};

#endif /* Missile_h */
