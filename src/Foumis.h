//
//  Foumis.hpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 11/10/2017.
//

#pragma once
#ifndef Foumis_hpp
#define Foumis_hpp

#include "GraphicPrimitives.h"

class Fourmis {
    
public:
    Fourmis(float posX_ = 0.0f,float posY_ = 0.0f):
        posX1(posX_),posY1(posY_),
        posX2(posX_+0.08),posY2(posY_),
        posX3(posX_+0.04),posY3(posY_+0.1),
        VposX(0.01f),VposY(0.01f),
        R((float)rand()/(RAND_MAX)),
        G((float)rand()/(RAND_MAX)),
        B((float)rand()/(RAND_MAX)){ }
    
    float posX1,posY1, posX2,posY2, posX3,posY3;
    float VposX,VposY;
    float R,G,B;
    
    void draw();
    void tick();
    
};


#endif /* Foumis_hpp */
