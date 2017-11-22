//
//  Foumis.cpp
//  generical_libGraphProject
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 11/10/2017.
//

#include "Foumis.h"

void Fourmis::draw(){
    
    GraphicPrimitives::drawFillTriangle2D(posX1, posY1, posX2, posY2, posX3, posY3, R, G, B);
}

void Fourmis::tick(){
    posX1 += VposX;                             //VECTEUR DEPLACEMENTS
    if (posX1 > 1.0f /*- 0.1*/ || posX1 < -1.0f) {  // LIMITES DES BORDURES FENÊTRES
        /* bord gauche */
        VposX  = -VposX;
        posX1 += VposX;
    }
    
    posY1 += VposY;
    if (posY1 > 1.0f /*- 0.1*/ || posY1 < -1.0f) {
        /* en bas */
        VposY = -VposY;
        posY1 += VposY;
    }
    
    posX2 = posX1 + 0.08;//+= VposX;
    if (posX2 > 1.0f /*- 0.1*/ || posX2 < -1.0f) {
        /* bord droit */
    
        VposX = -VposX;
        posX2 += VposX;
    }
    
    posY2 = posY1; //+= VposY;
    if (posY2 > 1.0f /*- 0.1*/ || posY2 < -1.0f) {
        
        VposY = -VposY;
        posY2 += VposY;
    }
    
    posX3 = posX1 + 0.04; //+= VposX;
    if (posX3 > 1.0f /*- 0.1*/ || posX3 < -1.0f) {
        
        VposX = -VposX;
        posX3 += VposX;
    }
    
    posY3 = posY1 + 0.1; //+= VposY;
    if (posY3 > 1.0f /*- 0.1*/ || posY3 < -1.0f) {
        /*en haut */
        
        VposY = -VposY;
        posY3 += VposY;
    }
}
