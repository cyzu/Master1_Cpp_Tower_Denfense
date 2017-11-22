#pragma once

#include "Engine.h"
#include "Papillon.h"
#include "Foumis.h"

class MyGameEngine:public GameEngine {
    std::vector<Papillon * > *paps;
//    std::vector<Fourmis * > *four;
public:
    
    MyGameEngine(std::vector<Papillon * > * paps_):paps(paps_){}
//    MyGameEngine(std::vector<Fourmis * > * four_):four(four_){}
    
    virtual void idle();
    
};
