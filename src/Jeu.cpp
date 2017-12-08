//
//  Jeu.cpp
//  TowerDefence project
//
//  Created by Chloé BENSOUSSAN on 23/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#include "Jeu.h"
#include "Engine.h"
#include "Vaisseau.h"

int Jeu::vie = 100;
std::vector<Vaisseau> Jeu::typesVaisseaux;
Vaisseau Jeu::choix(0.0f, 0.0f, 0.0f, -10, -10);
Asteroide Jeu::asteroide(0, 0, 0.03);

float Jeu::getCaseX(const int x){
    float window = glutGet(GLUT_WINDOW_WIDTH)/2;
    float posX = (x - window) / window;
    
    float i = -1;
    while(i < 1 && posX > i){
        i += 0.2;
    }
    posX = i - 0.1;
    return posX;
}
    
float Jeu::getCaseY(const int y){
    float window = glutGet(GLUT_WINDOW_HEIGHT)/2;
    float posY = (y - window) / window;
        
    float i = -1;
    while(i < 1 && posY > i){
        i += 2.0/getNombreLignes();
    }
    posY = i - 2.0/(2*getNombreLignes());
    return -posY;
}

void Jeu::reduireVie(const int i){
    vie = getVie() - i;
}

int Jeu::getVie(){
    return vie;
}

int Jeu::getNombreLignes(){
    return nb_lignes;
}

void Jeu::ajouterVaisseau(Vaisseau v){
    typesVaisseaux.push_back(v);
}
