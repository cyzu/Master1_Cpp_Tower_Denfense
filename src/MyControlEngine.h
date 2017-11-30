#pragma once
#include "Engine.h"
#include "Vaisseau.h"

class MyControlEngine:public ControlEngine {
    std::vector<Vaisseau * > *vaisseau;
    
    public:
    MyControlEngine(std::vector<Vaisseau * > *vaisseau_):vaisseau(vaisseau_){}
   
    virtual void MouseCallback(int button, int state, int  x, int y) ;
};
