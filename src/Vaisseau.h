//
//  Vaisseau.hpp
//  TowerDefence project
//
//  Created by Chloé BENSOUSSAN on 22/11/2017.
//  Copyright © 2017 Chloe Bensoussan. All rights reserved.
//
#pragma once
#ifndef Vaisseau_h
#define Vaisseau_h

#include "GraphicPrimitives.h"
#include "Missile.h"
//#include <stdio.h>
#include <deque>

class Vaisseau{
    
    private :
    
    float x, y; //Coordonnées du milieu du vaisseau
    float frequence, vitesse, puissance;
    float red, green, blue;//r = 0.4f ,b = 0.2f ,g = 0.0f; //couleur bordeaux
    int vie;
    
    int countF = 0;
    
    std::deque<Missile> missiles;
    
    //static int totalVaisseaux;
    
    public :
    
    /* 
     Constructeurs / destructeur 
     */
    
    Vaisseau(const float r_, const float g_, const float b_, const float x, const float y,
             const float f = 1, const float v = 1, const float p = 1);
    
    Vaisseau(const Vaisseau &v);
    
    /* 
     Getter / setter 
     */
    
    float getX();
    float getY();
    
    float getFrequence();
    float getVitesse();
    float getPuissance();
    
    float getRed();
    float getGreen();
    float getBlue();
    
    int getCountF();
    int getVie();
    std::deque<Missile>* getMissiles();
    
    //static int getTotalVaisseaux();
    
    /* Utile pour dessiner les vaisseaux */
    const float getVectorX();
    const float getVectorY();
    
    void setX(const float a);
    void setY(const float a);
    
    void setFrequence(const float f);
    void setVitesse(const float v);
    void setPuissance(const float p);
    
    void setRed(const float r);
    void setGreen(const float g);
    void setBlue(const float b);
    
    void setCountF(const int i);
    void reduireVie(const int i);
    
    
    /*
     Fonctions interfaces
     */
    
    void draw();
    void tick();
};

#endif /* Vaisseau_h */


