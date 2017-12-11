//
//  Vague.h
//  TowerDefence
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 09/12/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//
#pragma once
#ifndef Vague_hpp
#define Vague_hpp

#include <stdio.h>
#include <deque>
#include "Asteroide.h"

class Vague{
    private :
    int nombre; //nombre d'astéroides dans une vague
    const float intervalle = 0.15;
    
    static int totalVagues; //nombre de vague terminée sans mourir
    
    public :
    static std::deque<Asteroide> asteroides;
    
    Vague(const float x, const float y, const float vecteur, const int nb = 4);
    Vague();
    ~Vague();
    
    static int getTotalVagues();
    void nouvelleVague(const float x, const float y, const float vecteur, const int nb);
    
    float getIntervalle();
    int getNombre();
    
    void setNombre(const int nb);
    
    void draw();
    void tick();
};

#endif /* Vague_hpp */
