//
//  Asteroïdes.hpp
//  TowerDefence
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 08/12/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#ifndef Asteroi_des_hpp
#define Asteroi_des_hpp

#include <stdio.h>
#include <vector>
#include "GraphicPrimitives.h"

class Asteroide{
    private :
    float centreX, centreY;
    float vector;
    
    std::vector<float> x;
    std::vector<float> y;
    
    //TODO vie, argent, impact missiles, types, choix aléatoires par l'ordi, count vague
    
    // todo : vitesse, puissance astéroides
    
    public :
    Asteroide(const float x_, const float y_, const float v = 0.04);
    
    void initVectorsX();
    void initVectorsY();
    
    std::vector<float> getVectorsX();
    std::vector<float> getVectorsY();
    
    void setCentreX(const float x_);
    void setCentreY(const float y_);
    void setVector(const float v);
    
    float getCentreX();
    float getCentreY();
    float getVector();
    
    void draw();
    void tick();
};

#endif /* Asteroi_des_hpp */
