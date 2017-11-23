//
//  Case.cpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 23/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#include "Case.h"
#include <iostream>

float Case::nb_lignes = 10;

float Case::getCaseX(const int x){
    //i*10 + nb_lignes
    
    float posX = (x-400) / 400.0;
    float i = -0.8;
    while(i < 1 && posX > i){
        i += 0.2;
    }
    posX = i - 0.1;
    return posX;
}

float Case::getCaseY(const int y){
    //i*10 + nb_lignes
    float posY = (y-300) / 300.0;

    float i = -0.8;
    while(i < 1 && posY > i){
        i += 2/nb_lignes;
    }
    posY = i - 2/(2*nb_lignes);
    return -posY;
}
