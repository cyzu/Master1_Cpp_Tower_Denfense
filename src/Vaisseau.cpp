//
//  Vaisseau.cpp
//  TowerDefence project
//
//  Created by Chloé BENSOUSSAN on 22/11/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#include "Vaisseau.h"
#include "Missile.h"
#include "Jeu.h"
#include <math.h>
#include <unistd.h>

Vaisseau::Vaisseau(const float r_, const float g_, const float b_, const float x_, const float y_, const float f, const float v, const float p, const int d, const int price){
    x = x_;
    y = y_;
    
    frequence = f;
    vitesse = v;
    puissance = p;
    distance = d;
    
    vie = 15;
    prix = price;
    
    red = r_;
    green = g_;
    blue = b_;
    
    redInit = red;
    greenInit = green;
    blueInit = blue;
    
    Missile m(x+getVectorX(), y, puissance, vitesse);
    missiles.push_back(m);
}

Vaisseau::Vaisseau(const Vaisseau &v){
    x = v.x;
    y = v.y;
    
    red = v.red;
    green = v.green;
    blue = v.blue;
    
    redInit = v.redInit;
    greenInit = v.greenInit;
    blueInit = v.blueInit;
    
    frequence = v.frequence;
    vitesse = v.vitesse;
    puissance = v.puissance;
    distance = v.distance;
    
    vie = v.vie;
    prix = v.prix;
}

float Vaisseau::getX(){ return x; }
float Vaisseau::getY(){ return y; }

float Vaisseau::getFrequence(){ return frequence; }
float Vaisseau::getVitesse(){ return vitesse; }
float Vaisseau::getPuissance(){ return puissance; }
int Vaisseau::getDistance(){ return distance; }

float Vaisseau::getRed(){ return red;}
float Vaisseau::getGreen(){ return green;}
float Vaisseau::getBlue(){ return blue;}

int Vaisseau::getCountF(){ return countF; }
int Vaisseau::getVie(){ return vie;}
int Vaisseau::getPrix(){ return prix; }

std::deque<Missile>* Vaisseau::getMissiles(){ return &missiles; }

const float Vaisseau::getVectorX(){ return 0.07; }
const float Vaisseau::getVectorY(){ return (2.0/Jeu::getNombreLignes())/3;; }

void Vaisseau::setX(const float a){ x = a;}
void Vaisseau::setY(const float a){ y = a;}

void Vaisseau::setFrequence(const float f){ frequence = f;}
void Vaisseau::setVitesse(const float v){ vitesse = v;}
void Vaisseau::setPuissance(const float p){ puissance = p;}
void Vaisseau::setDistance(const int d){ distance = d;}

void Vaisseau::setRed(const float r){ red = r;}
void Vaisseau::setGreen(const float g){ green = g;}
void Vaisseau::setBlue(const float b){ blue = b;}

void Vaisseau::setCountF(const int i){ countF = i; }
void Vaisseau::reduireVie(const int i){
    vie = getVie() - i;
    if (vie <= 0) vie = 0;
}
void Vaisseau::setPrix(const int p){ prix = p; }



void Vaisseau::draw(){
    GraphicPrimitives::drawFillTriangle2D(x+getVectorX()+0.003, y, x-getVectorX()-0.002, y+getVectorY()+0.004, x-getVectorX()-0.002, y-getVectorY()-0.004, redInit, greenInit, blueInit);
    GraphicPrimitives::drawFillTriangle2D(x+getVectorX(), y, x-getVectorX(), y+getVectorY(), x-getVectorX(), y-getVectorY(), red, green, blue);
    
    for (auto i = 0; i < missiles.size(); i++) {
        missiles[i].draw();
    }
}

void Vaisseau::tick(){
    
    // Gestion de temps d'intervalle pour créer une nouvelle missile
    if (getCountF() >= 1/getFrequence()*200){
        Missile m(getX()+getVectorX(), y, puissance, vitesse);
        missiles.push_back(m);
        setCountF(0);
    }
    
    // Animer les missiles
    for (auto i = 0; i < missiles.size(); i++) {
        if (missiles[i].getX() >= 1 or missiles[i].getX() >= (getX() + 0.2*distance)) missiles.pop_front();
        missiles[i].tick();
    }
    setCountF(getCountF()+1);
}
