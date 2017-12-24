#pragma once
#include "Engine.h"
#include "Vaisseau.h"

class MyGameEngine:public GameEngine {
    std::vector<Vaisseau * > *vaisseau;
    
    public:
    MyGameEngine(std::vector<Vaisseau * > *vaisseau_):
        vaisseau(vaisseau_){}
    
    virtual void idle();
    
};
