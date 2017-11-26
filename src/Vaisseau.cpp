//
//  Vaisseau.cpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 22/11/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#include "Vaisseau.h"

Vaisseau::Vaisseau(const float x_, const float y_, const float f, const float v, const float p){
    x = x_;
    y = y_;
    
    posX1 = x+0.05;
    posY1 = y;
    posX2 = x-0.05;
    posY2 = y+0.05;
    posX3 = x-0.05;
    posY3 = y-0.05;
    
    frequence = f;
    vitesse = v;
    puissance = p;
    
    r = 0.0f;
    b = 0.0f;
    g = 1.0f;
}

Vaisseau::Vaisseau(const Vaisseau &v){
    x = v.x;
    y = v.y;
    
    frequence = v.frequence;
    vitesse = v.vitesse;
    puissance = v.puissance;
    
    r = v.r;
    g = v.g;
    b = v.b;
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
    GraphicPrimitives::drawFillTriangle2D(x+0.05, y, x-0.05, y+0.05, x-0.05, y-0.05, r, g, b);
}

void Vaisseau::tick(){
    posX1 += 0.05;                             //VECTEUR DEPLACEMENTS
    if (x > 1.0f /*- 0.1*/ || x < -1.0f) {  // LIMITES DES BORDURES FENÊTRES
        /* bord gauche */
        //VposX  = -VposX;
        x -= 0.05;
    }
    
    posY1 += 0.05;
    if (y > 1.0f /*- 0.1*/ || y < -1.0f) {
        /* en bas */
        //VposY = -VposY;
        y -= 0.05;
    }
    
    posX2 = posX1 - 0.05;//+= VposX;
    if (posX2 > 1.0f /*- 0.1*/ || posX2 < -1.0f) {
        /* bord droit */
        
        //VposX = -VposX;
        posX2 -= 0.05;
    }
    
    posY2 = posY1 + 0.05; //+= VposY;
    if (posY2 > 1.0f /*- 0.1*/ || posY2 < -1.0f) {
        
        //VposY = -VposY;
        posY2 -= 0.05;
    }
    
    posX3 = posX1 - 0.05; //+= VposX;
    if (posX3 > 1.0f /*- 0.1*/ || posX3 < -1.0f) {
        
        //VposX = -VposX;
        posX3 -= 0.05;
    }
    
    posY3 = posY1 - 0.05; //+= VposY;
    if (posY3 > 1.0f /*- 0.1*/ || posY3 < -1.0f) {
        /*en haut */
        
        //VposY = -VposY;
        posY3 -= 0.05;
    }
}
