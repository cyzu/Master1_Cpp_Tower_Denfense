
#include <iostream>
//#include <stdlib.h>
//#include <cstdlib>
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
    
    Jeu::ajouterVaisseau(Vaisseau(0.4f, 0.0f, 0.2f, 0, 0, 2, 10, 3));// Bordeaux
    Jeu::ajouterVaisseau(Vaisseau(0.2f, 0.4f, 0.0f, 0, 0, 5, 6, 5)); // Vert
    Jeu::ajouterVaisseau(Vaisseau(0.4f, 0.2f, 0.0f, 0, 0, 10, 3, 1));// Marron
    Jeu::ajouterVaisseau(Vaisseau(0.0f, 0.2f, 0.4f, 0, 0, 1, 7, 15));// Bleu
    
    e.start();
    
    return 0;
}
