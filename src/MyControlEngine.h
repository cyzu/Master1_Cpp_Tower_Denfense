#pragma once
#include "Engine.h"
#include "Vaisseau.h"
//#include "Jeu.h"

class MyControlEngine : public ControlEngine {
    std::vector<Vaisseau * > *vaisseau;
    
    private:
    int count = -1;
    bool adding = false;
    float currentX = -1, currentY = -1;
    
    public:
    MyControlEngine(std::vector<Vaisseau * > *vaisseau_):vaisseau(vaisseau_){}
   
    void annuler();
    virtual void MouseCallback(int button, int state, int  x, int y);
    virtual void KeyboardCallback(unsigned char key,int x, int y);
};
