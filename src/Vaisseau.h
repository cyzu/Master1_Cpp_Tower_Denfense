//
//  Vaisseau.hpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 22/11/2017.
//  Copyright © 2017 Chloe Bensoussan. All rights reserved.
//

#ifndef Vaisseau_h
#define Vaisseau_h

#include "GraphicPrimitives.h"
#include "Missile.h"
#include <stdio.h>

class Vaisseau{
    
    private :
    
    float x, y; //Coordonnées du milieu du vaisseau
    float frequence, vitesse, puissance;
    const float r = 0.4f ,b = 0.2f ,g = 0.0f; //couleur bordeaux
    
    Missile *missiles;
    //Missile *creationM = NULL;
    
    public :
    
    /* 
     Constructeurs / destructeur 
     */
    
    Vaisseau(const float x, const float y,
             const float f = 2, const float v = 2, const float p = 5);
    
    Vaisseau(const Vaisseau &v);
    
    /* 
     Getter / setter 
     */
    
    float getX();
    float getY();
    float getFrequence();
    float getVitesse();
    float getPuissance();
    Missile* getMissiles();
    
    /* Utile pour dessiner les vaisseaux */
    const float getVectorX();
    const float getVectorY();
    
    void setX(const float a);
    void setY(const float a);
    void setFrequence(const float f);
    void setVitesse(const float v);
    void setPuissance(const float p);
    
    
    /*
     Fonctions interfaces
     */
    
    void draw();
    void tick();
};

#endif /* Vaisseau_h */


