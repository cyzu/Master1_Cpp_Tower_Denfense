//
//  Vague.cpp
//  TowerDefence
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 09/12/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#include "Jeu.h"
#include "Vague.h"
#include <deque>
#include <cstdlib>

std::deque<Asteroide> Vague::asteroides;
int Vague::totalVagues = -1;

Vague::Vague(const float x, const float y, const float vecteur, const int nb, const float v, const float i_){
    nombre = nb;
    vitesse = v;
    intervalle = i_;
    
    for (auto i = 0; i < nombre; i++) {
        asteroides.push_back(Asteroide(x + (i*i_), y, vecteur));
    }
}

Vague::Vague(){
    nombre = 2;
    vitesse = 0.0005;
    intervalle = 0.2;
}

Vague::~Vague(){
    asteroides.clear();
}

int Vague::getTotalVagues(){
    return totalVagues;
}

void Vague::nouvelleVague(const float x, const float y, const float vecteur, const int nb, const float v, const float i_){
    std::cout<<"Nouvelle Vague : "<<nb<<std::endl;
    std::srand(std::time(0));
    asteroides.clear();
    
    setNombre(nb);
    setVitesse(v);
    setIntervalle(i_);
 
    for (auto i = 0; i < getNombre(); i++) {
        int randomY = std::rand() % Jeu::getNombreLignes();
        float coordY = (-1 + (2.0/Jeu::getNombreLignes()/2.0)) + (randomY * (2.0/Jeu::getNombreLignes()));
        
        if (totalVagues > 2 and totalVagues < 8){
            int randomA = std::rand() % Jeu::typesAsteroides.size()-1;
            asteroides.push_back(Asteroide(x + (i*getIntervalle()), coordY, Jeu::typesAsteroides[randomA+1].getVector(), Jeu::typesAsteroides[randomA+1].getVie()));
        }
        else if (totalVagues >= 8 and totalVagues < 13){
            int randomA = std::rand() % Jeu::typesAsteroides.size()-2;
            asteroides.push_back(Asteroide(x + (i*getIntervalle()), coordY, Jeu::typesAsteroides[randomA+2].getVector(), Jeu::typesAsteroides[randomA+2].getVie()));
        }
        else if (totalVagues >= 13 and totalVagues < 18){
            int randomA = std::rand() % Jeu::typesAsteroides.size()-3;
            asteroides.push_back(Asteroide(x + (i*getIntervalle()), coordY, Jeu::typesAsteroides[randomA+3].getVector(), Jeu::typesAsteroides[randomA+3].getVie()));
        }
        else if (totalVagues >= 18){
            int randomA = std::rand() % Jeu::typesAsteroides.size()-4;
            asteroides.push_back(Asteroide(x + (i*getIntervalle()), coordY, Jeu::typesAsteroides[randomA+4].getVector(), Jeu::typesAsteroides[randomA+4].getVie()));
        }
        else asteroides.push_back(Asteroide(x + (i*getIntervalle()), coordY, vecteur));
    }
    totalVagues++;
}

float Vague::getVitesse(){
    return vitesse;
}

float Vague::getIntervalle(){
    return intervalle;
}

int Vague::getNombre(){
    return nombre;
}

void Vague::setNombre(const int nb){
    nombre = nb;
}

void Vague::setVitesse(const float v){
    vitesse = v;
}

void Vague::setIntervalle(const float i){
    intervalle = i;
}

void Vague::draw(){
    for (int i = 0; i < asteroides.size(); i++) {
        asteroides[i].draw();
    }
}

void Vague::tick(){
    for (int i = 0; i < asteroides.size(); i++) {
        asteroides[i].tick(vitesse);
    }
}
