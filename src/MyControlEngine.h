#pragma once
#include "Engine.h"
#include "Papillon.h"
#include "Foumis.h"
#include "Vaisseau.h"

class MyControlEngine:public ControlEngine {
    /*std::vector<Papillon * > *paps;*/
     //std::vector<Fourmis * > *four;
    std::vector<Vaisseau * > *vaisseau;
public:
    //MyControlEngine(std::vector<Papillon * > * paps_):paps(paps_){}
    //MyControlEngine(std::vector<Fourmis * > * four_):four(four_){}
    
    MyControlEngine(std::vector<Vaisseau * > *vaisseau_):vaisseau(vaisseau_){}
   
    virtual void MouseCallback(int button, int state, int  x, int y) ;
};
