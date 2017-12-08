//
//  Case.hpp
//  TowerDefence project
//
//  Created by Chloé BENSOUSSAN on 23/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//
#pragma once
#ifndef Case_h
#define Case_h


#include "Engine.h"
#include "Vaisseau.h"
//#include <stdio.h>

class Jeu{
    private:
    static const int nb_lignes = 5;
    static int vie;
    
    
    public :
    static std::vector<Vaisseau> typesVaisseaux;
    static Vaisseau choix;
    
    static float getCaseX(const int x);
    static float getCaseY(const int y);
    
    static void reduireVie(const int i);
    static int getVie();
    
    static int getNombreLignes();
    
    static void ajouterVaisseau(Vaisseau v);
    
    //TODO astéroides ? Argent !!
};

#endif /* Case_h */
