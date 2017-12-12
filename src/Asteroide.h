//
//  Asteroïdes.hpp
//  TowerDefence
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 08/12/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//
#pragma once
#ifndef Asteroi_des_hpp
#define Asteroi_des_hpp

#include <stdio.h>
#include <vector>
#include "GraphicPrimitives.h"

class Asteroide{
    private :
    float centreX, centreY;
    float vector; // vecteur pour draw();
    float red, green, blue;
    int vie;
    float vitesse;
    
    std::vector<float> x;
    std::vector<float> y;
    
    public :
    Asteroide(const float x_, const float y_, const float speed = 0.0005,  const float v = 0.04, const int life = 5);
    
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
    
    float getVitesse();
    void setVitesse(const float v);
    
    void draw();
    void tick();
};

#endif /* Asteroi_des_hpp */
