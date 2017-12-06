//
//  Case.hpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 23/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#ifndef Case_h
#define Case_h

#include <stdio.h>
//#include "Vaisseau.h"

class Case{
    private :
    //bool empty;
    //float keyX, keyY;
    //Vaisseau *vaisseau;
    
    public :
    static const int nb_lignes;
    
    Case();
    ~Case();
    
    static float getCaseX(const int x);
    static float getCaseY(const int y);
    
   // Vaisseau* getVaisseau();
    //void setVaisseau(Vaisseau v);
    //bool isEmpty();
    
    /*void setkeyX(const float x);
    void setkeyY(const float y);
    float getkeyX();
    float getkeyY();*/
};

#endif /* Case_h */
