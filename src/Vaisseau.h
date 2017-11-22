//
//  Vaisseau.hpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 22/11/2017.
//  Copyright © 2017 Chloe Bensoussan. All rights reserved.
//

#ifndef Vaisseau_h
#define Vaisseau_h

#include <stdio.h>

class Vaisseau{
    
    private :
    
    float x,y;
    float ligne, frequence, vitesse, puissance;
    
    public :
    
    /* 
     Constructeurs / destructeur 
     */
    
    Vaisseau(float x, float y,
             float l = 0, float f = 1,
             float v = 1, float p = 1);
    
    Vaisseau(const Vaisseau &v);
    ~Vaisseau();
    
    /* 
     Getter / setter 
     */
    
    float getX();
    float getY();
    float getLigne();
    float getFrequence();
    float getVitesse();
    float getPuissance();
    
    void setX(const float a);
    void setY(const float a);
    void setLigne(const float l);
    void setFrequence(const float f);
    void setVitesse(const float v);
    void setPuissance(const float p);
    
    /*
     Fonctions interfaces
     */
    
    void draw();
    
    
    
    /* get windows height & width == glutGet(GLUT_WINDOW_HEIGHT)
        glutGet(GLUT_WINDOW_WIDTH)
     */
    
};

#endif /* Vaisseau_h */


