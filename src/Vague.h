//
//  Vague.h
//  TowerDefence
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 09/12/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#ifndef Vague_hpp
#define Vague_hpp

#include <stdio.h>
#include <deque>
#include "Asteroide.h"

class Vague{
    private :
    int nombre; //nombre d'astéroides dans une vague
    float vitesse;
    float intervalle;
    
    static int totalVagues; //nombre de vague créée
    //static bool init;
    
    public :
    static std::deque<Asteroide> asteroides;
    
    Vague(const float x, const float y, const float vecteur, const int nb = 4, const float v = 0.001, const float i_ = 0.2);
    Vague();
    ~Vague();
    
    static int getTotalVagues();
    void nouvelleVague(const float x, const float y, const float vecteur, const int nb, const float v, const float i_);
    
    float getVitesse();
    float getIntervalle();
    int getNombre();
    
    void setNombre(const int nb);
    void setVitesse(const float v);
    void setIntervalle(const float i);
    
    void draw();
    void tick();
};

#endif /* Vague_hpp */
