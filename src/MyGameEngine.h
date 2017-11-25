#pragma once

#include "Engine.h"
#include "Papillon.h"
#include "Foumis.h"
#include "Vaisseau.h"

class MyGameEngine:public GameEngine {
 //   std::vector<Papillon * > *paps;
    //std::vector<Fourmis * > *four;
    std::vector<Vaisseau * > *vaisseau;
public:
    
   // MyGameEngine(std::vector<Papillon * > * paps_):paps(paps_){}
    //MyGameEngine(std::vector<Fourmis * > * four_):four(four_){}
    
    MyGameEngine(std::vector<Vaisseau * > *vaisseau_):vaisseau(vaisseau_){}
    
    virtual void idle();
    
};
