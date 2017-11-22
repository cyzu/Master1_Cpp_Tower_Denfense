//
//  Vaisseau.cpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 22/11/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#include "Vaisseau.h"

Vaisseau::Vaisseau(float x1, float y1, float l, float f, float v, float p){
    x = x1;
    y = y1;
    ligne = l;
    frequence = f;
    vitesse = v;
    puissance = p;
}

Vaisseau::Vaisseau(const Vaisseau &v){
    x = v.x;
    y = v.y;
    ligne = v.ligne;
    frequence = v.frequence;
    vitesse = v.vitesse;
    puissance = v.puissance;
}

Vaisseau::~Vaisseau(){
    delete this;
}

float Vaisseau::getX(){ return x; }
float Vaisseau::getY(){ return y; }
float Vaisseau::getLigne(){ return ligne; }
float Vaisseau::getFrequence(){ return frequence; }
float Vaisseau::getVitesse(){ return vitesse; }
float Vaisseau::getPuissance(){ return puissance; }

void Vaisseau::setX(const float a){ x = a;}
void Vaisseau::setY(const float a){ y = a;}
void Vaisseau::setLigne(const float l){ ligne = l;}
void Vaisseau::setFrequence(const float f){ frequence = f;}
void Vaisseau::setVitesse(const float v){ vitesse = v;}
void Vaisseau::setPuissance(const float p){ puissance = p;}

void Vaisseau::draw(){
    GraphicPrimitives::drawFillTriangle2D(posX1, posY1, posX2, posY2, posX3, posY3, 0.5f, 0.5f, 0.5f);
}

