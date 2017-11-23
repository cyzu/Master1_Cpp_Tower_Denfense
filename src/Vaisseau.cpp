//
//  Vaisseau.cpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 22/11/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#include "Vaisseau.h"

Vaisseau::Vaisseau(const float x1, const float y1, const float f, const float v, const float p){
    x = x1;
    y = y1;
    frequence = f;
    vitesse = v;
    puissance = p;
}

Vaisseau::Vaisseau(const Vaisseau &v){
    x = v.x;
    y = v.y;
    frequence = v.frequence;
    vitesse = v.vitesse;
    puissance = v.puissance;
}

Vaisseau::~Vaisseau(){
    delete this;
}

float Vaisseau::getX(){ return x; }
float Vaisseau::getY(){ return y; }
float Vaisseau::getFrequence(){ return frequence; }
float Vaisseau::getVitesse(){ return vitesse; }
float Vaisseau::getPuissance(){ return puissance; }

void Vaisseau::setX(const float a){ x = a;}
void Vaisseau::setY(const float a){ y = a;}
void Vaisseau::setFrequence(const float f){ frequence = f;}
void Vaisseau::setVitesse(const float v){ vitesse = v;}
void Vaisseau::setPuissance(const float p){ puissance = p;}

void Vaisseau::draw(){
    printf("Dans draw()\n");
    GraphicPrimitives::drawFillTriangle2D(x+0.05, y, x-0.05, y+0.05, x-0.05, y-0.05, 0.0f, 1.0f, 0.0f);
}

void Vaisseau::tick(){
    x = 0.5;
    y = 0.5;

}
