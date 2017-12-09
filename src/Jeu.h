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
    //static int totalVaisseaux; //total de vaisseaux posés dans la partie
   // static int totalVagues;    //total de vague réussi
    
    public :
    static std::vector<Vaisseau> typesVaisseaux;
    //static std::deque<Asteroide> asteroides;
    static Vaisseau choix;
    static Vague vague;
    
    //static Asteroide asteroide;
    
    static float getCaseX(const int x);
    static float getCaseY(const int y);
    
    static void reduireVie(const int i);
    static int getVie();
    
    static int getNombreLignes();
    
    static void ajouterVaisseau(Vaisseau v);
    //static void ajouterAsteroides(const int nombre, const float intervalle);
    
    static void addTotalVaisseaux();
    static int getTotalVaisseaux();
    
    static void finPartie();
    /*static void addTotalVagues();
    static int getTotalVagues();*/
    
    //TODO astéroides ? Argent !!
};

#endif /* Case_h */
