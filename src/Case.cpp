//
//  Case.cpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 23/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#include "Case.h"
#include "Engine.h"
#include <iostream>

float Case::nb_lignes = 5;

float Case::getCaseX(const int x){
    
    float window = glutGet(GLUT_WINDOW_WIDTH)/2;
    float posX = (x - window) / window;
    
    float i = -1;
    while(i < 1 && posX > i){
        i += 0.2;
    }
    posX = i - 0.1;
    return posX;
}

float Case::getCaseY(const int y){
    float window = glutGet(GLUT_WINDOW_HEIGHT)/2;
    float posY = (y - window) / window;
    
    float i = -1;
    while(i < 1 && posY > i){
        i += 2/nb_lignes;
    }
    posY = i - 2/(2*nb_lignes);
    return -posY;
}
