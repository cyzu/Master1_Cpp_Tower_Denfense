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
    float frequence, vitesse, puissance; //longueur des missiles varie en fonction de la puissance
    const float r = 0.4f ,b = 0.2f ,g = 0.0f;
    
    Missile *missiles;
    
    public :
    
    /* 
     Constructeurs / destructeur 
     */
    
    Vaisseau(const float x, const float y,
             const float f = 1, const float v = 1,
             const float p = 1);
    
    Vaisseau(const Vaisseau &v);
    
    /* 
     Getter / setter 
     */
    
    float getX();
    float getY();
    float getFrequence();
    float getVitesse();
    float getPuissance();
    
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
    
    
    
    /* get windows height & width == glutGet(GLUT_WINDOW_HEIGHT)
        glutGet(GLUT_WINDOW_WIDTH)
     */
    
};

#endif /* Vaisseau_h */


