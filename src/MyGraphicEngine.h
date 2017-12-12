#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Vaisseau.h"
#include <stdlib.h>

class MyGraphicEngine:public GraphicEngine {
    
    std::vector<Vaisseau * > *vaisseau;
    
    public:
    MyGraphicEngine(std::vector<Vaisseau * > * vaisseau_);
    
    virtual void Draw();
    
};

