//
//  Vague.cpp
//  TowerDefence
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 09/12/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#include "Vague.h"
#include <deque>

std::deque<Asteroide> Vague::asteroides;
int Vague::totalVagues = -1;
//bool init = true;

Vague::Vague(const float x, const float y, const float vecteur, const int nb, const float v, const float i_){
    nombre = nb;
    vitesse = v;
    intervalle = i_;
    
    for (auto i = 0; i < nombre; i++) {
        asteroides.push_back(Asteroide(x + (i*i_), y, vecteur));
    }
}

Vague::Vague(){
    //init = false;
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
    asteroides.clear();
    //Vague(x, y, vecteur, nb, v, i_);
    /*nombre = nb;
    vitesse = v;
    intervalle = i_;*/
    
    setNombre(nb);
    setVitesse(v);
    setIntervalle(i_);
    
    for (auto i = 0; i < getNombre(); i++) {
        asteroides.push_back(Asteroide(x + (i*getIntervalle()), y, vecteur));
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
