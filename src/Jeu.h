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
//#include "Asteroide.h"
#include "Vague.h"
//#include <stdio.h>

class Jeu{
    private:
    static const int nb_lignes = 5;
    static int vie;
    static int totalVaisseaux;
    
    public :
    static std::vector<Vaisseau> typesVaisseaux;
    static Vaisseau choix;
    static Vague vague;
    
    
    /* MÉTHODES */
    static float getCaseX(const int x);
    static float getCaseY(const int y);
    
    static void reduireVie(const int i);
    static int getVie();
    
    static int getNombreLignes();
    
    static void ajouterVaisseau(Vaisseau v);
    
    static void addTotalVaisseaux();
    static int getTotalVaisseaux();
    
    static void collision_Missile_Asteroide(Vaisseau *v, const int a);
    static bool collision_Vaisseau_Asteroide();
    
    static void impactAsteroide(Vaisseau *v, const int a);
    static void impactMissile(Vaisseau *v, const int a);
    static void impactVaisseau();
    static void finPartie();
    
    //TODO Argent !!
};

#endif /* Case_h */
