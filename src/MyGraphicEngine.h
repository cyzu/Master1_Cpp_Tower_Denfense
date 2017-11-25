#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Papillon.h"
#include "Foumis.h"
#include "Case.h"
#include "Vaisseau.h"
#include <stdlib.h>

class MyGraphicEngine:public GraphicEngine {
    
    //std::vector<Papillon * > *paps;
    //std::vector<Fourmis * > *four;
    std::vector<Vaisseau * > *vaisseau;
    
    char * str;
public:
    /*MyGraphicEngine(std::vector<Fourmis * > * four_):
    //MyGraphicEngine(std::vector<Papillon * > * paps_):
   // paps(paps_),
    four(four_),
    str(new char[10]{'F','o','u','r','m','i','s',' ','P','l','a','y','\0'}),
    x1(0.6f),
    x2(-0.6f),
    vx1(0.01),
    vx2(-0.02) { }*/
    
    MyGraphicEngine(std::vector<Vaisseau * > * vaisseau_):
    vaisseau(vaisseau_),
    str(new char[13]{'C','l','i','c',' ','&',' ','E','n','j','o','y','\0'}),
        x1(0.5f),
        x2(-0.5f),
        vx1(0.01),
        vx2(-0.02) { }
    
    
 /*   MyGraphicEngine(std::vector<Fourmis * > * four_):
    four(four_),
    str(new char[13]{'C','l','i','c',' ','c','l','i','c','k',' ','!','\0'}),
    x1(0.6f),
    x2(-0.4f),
    vx1(0.02),
    vx2(-0.01) { }*/
    
    float x1,x2,vx1,vx2;
    
    virtual void Draw();
    
};

