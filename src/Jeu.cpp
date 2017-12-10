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
#include <unistd.h>

int Jeu::vie = 100;
int Jeu::totalVaisseaux = 0;

std::vector<Vaisseau> Jeu::typesVaisseaux;
Vaisseau Jeu::choix(0.0f, 0.0f, 0.0f, -10, -10);
Vague Jeu::vague;

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
    if (vie < 0) vie = 0;
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

/*void Jeu::ajouterAsteroides(const int nombre, const float intervalle){
    for (auto i = 0; i < nombre; i++) {
        asteroides.push_back(Asteroide(1.1 +(i*intervalle), 0, 0.03));
         //std::cout<<"astéroides "<<i<<" : "<<asteroides[i].getCentreX()<<std::endl;
    }
}*/

void Jeu::addTotalVaisseaux(){
    totalVaisseaux ++;
}

int Jeu::getTotalVaisseaux(){
    return totalVaisseaux;
}

void Jeu::finPartie(){
    Vague::asteroides.clear();
    
    std::cout<<"\nAFFICHAGE FIN DE PARTIE\n"<<std::endl;
    std::cout<<"Total de vaisseaux posé pendant la partie : "<<Jeu::getTotalVaisseaux()<<std::endl;
    std::cout<<"Nombre de vague réussie : "<<Vague::getTotalVagues()<<std::endl;
    
    //std::this::sleep_for(1500);
    sleep(2);
    exit(0);

}

/*void Jeu::addTotalVagues(){
    totalVagues ++;
}

int Jeu::getTotalVagues(){
    return totalVagues;
}*/
