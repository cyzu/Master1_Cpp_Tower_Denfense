
#include <iostream>
#include "Vaisseau.h"
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
    
    Jeu::initTypesVaisseaux();
    Jeu::initTypesAsteroides();
    
    e.start();
    
    return 0;
}
