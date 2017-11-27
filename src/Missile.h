//
//  Missile.hpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 27/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#ifndef Missile_h
#define Missile_h

#include <stdio.h>

class Missile{
    
    private :
    
    float x, y, vector;
    const float r = 0.0f, g = 1.0f, b = 0.0f;
    
    Missile *missileSuiv;
    
    public :
    
    Missile(const float x_, const float y_, const float v);
    Missile(const float x_, const float y_, const float v, Missile *m);
    Missile(const Missile &m);
    ~Missile();
    
    float getX();
    float getY();
    float getVector();
    
    void setX(const float x_);
    void setY(const float y_);
};

#endif /* Missile_h */
