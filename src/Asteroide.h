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
    int vie;
    float red, green, blue;
    
    std::vector<float> x;
    std::vector<float> y;
    
    //TODO vie, argent,  types, 
    // todo : vitesse, puissance astéroides
    
    public :
    Asteroide(const float x_, const float y_, const float v = 0.04);
    
    void initVectorsX();
    void initVectorsY();
    
    void reduireVie(const int v);
    int getVie();
    
    std::vector<float> getVectorsX();
    std::vector<float> getVectorsY();
    
    void setCentreX(const float x_);
    void setCentreY(const float y_);
    void setVector(const float v);
    
    float getCentreX();
    float getCentreY();
    float getVector();
    
    void setRed(const float r);
    void setGreen(const float g);
    void setBlue(const float b);
    
    float getRed();
    float getGreen();
    float getBlue();
    
    void draw();
    void tick(const float v);
};

#endif /* Asteroi_des_hpp */
