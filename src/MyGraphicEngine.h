#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Vaisseau.h"
//#include "Asteroide.h"
#include <stdlib.h>

class MyGraphicEngine:public GraphicEngine {
    
    std::vector<Vaisseau * > *vaisseau;
    char * str;
    
    public:
    MyGraphicEngine(std::vector<Vaisseau * > * vaisseau_);
    
    //float x1,x2,vx1,vx2;
    
    virtual void Draw();
    
};

