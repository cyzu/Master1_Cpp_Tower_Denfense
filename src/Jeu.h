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

#include "Vaisseau.h"
#include "Vague.h"

class Vaisseau;

class Jeu{
    private:
    static const int nb_lignes = 5;
    static int vie;
    static int totalVaisseaux;
    static int tirelire;
    
    public :
    static std::vector<Vaisseau> typesVaisseaux;
    static std::vector<Asteroide> typesAsteroides;
    static Vaisseau choix;
    static Vague vague;
    
    
    /* MÉTHODES */
    static void initTypesVaisseaux();
    static void initTypesAsteroides();
    
    static int getNombreLignes();
    
    static float getCaseX(const int x);
    static float getCaseY(const int y);
    
    static void reduireVie(const int i);
    static int getVie();
    
    static bool payer(const int a);
    static void gagner(const int a);
    static int getTirelire();
    
    static void ajouterVaisseau(Vaisseau v);
    static void ajouterAsteroide(Asteroide a);
    
    static void addTotalVaisseaux();
    static int getTotalVaisseaux();
    
    static bool collision_Missile_Asteroide(Vaisseau *v, const int a);
    static void collision_Vaisseau_Asteroide(std::vector<Vaisseau *> *v, const int i, const int a);
    
    static bool impactAsteroide(Vaisseau *v, const int a);
    static void impactMissile(Vaisseau *v, const int a);
    static void impactVaisseau(std::vector<Vaisseau *> *v, const int i, const int a);
    
    static void affichageChoix();
    static void finPartie();
    
    //TODO Argent !!
};

#endif /* Case_h */
