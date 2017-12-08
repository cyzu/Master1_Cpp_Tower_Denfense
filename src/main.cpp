
#include <iostream>
#include <stdlib.h>
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Jeu.h"



int main(int argc, char * argv[])
{
    Engine e(argc,argv);
    
    std::vector<Vaisseau * > vaisseau;
    
    GraphicEngine * ge  = new MyGraphicEngine(&vaisseau);
    GameEngine    * gme = new MyGameEngine(&vaisseau);
    ControlEngine * ce  = new MyControlEngine(&vaisseau);

    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    ////r = 0.4f ,b = 0.2f ,g = 0.0f
    
    Vaisseau v(0.4f, 0.0f, 0.2f, 0, 0, 1, 10, 3);
    Jeu::ajouterVaisseau(v);
    
    v.setRed(0.2f);
    v.setGreen(0.4f);
    v.setBlue(0.0f);
    v.setFrequence(5);
    v.setVitesse(6);
    v.setPuissance(5);
    Jeu::ajouterVaisseau(v);
    
    v.setRed(0.4f);
    v.setGreen(0.2f);
    v.setBlue(0.0f);
    v.setFrequence(10);
    v.setVitesse(10);
    v.setPuissance(1);
    Jeu:: ajouterVaisseau(v);
    
    v.setRed(0.0f);
    v.setGreen(0.2f);
    v.setBlue(0.4f);
    v.setFrequence(1);
    v.setVitesse(7);
    v.setPuissance(15);
    Jeu::ajouterVaisseau(v);
    
    e.start();
    
    return 0;
}
