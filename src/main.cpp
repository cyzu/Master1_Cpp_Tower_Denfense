

#include <iostream>
#include <stdlib.h>
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"


int main(int argc, char * argv[])
{
    //float x, y;
//    srand(time(NULL));
    
    Engine e(argc,argv);
    
    std::vector<Vaisseau * > vaisseau;
    
    //std::vector<Papillon *> paps;
//    std::vector<Fourmis *> four;
    
    GraphicEngine * ge  = new MyGraphicEngine(&vaisseau);
    GameEngine    * gme = new MyGameEngine(&vaisseau);
    ControlEngine * ce  = new MyControlEngine(&vaisseau);

//    GraphicEngine * geF = new MyGraphicEngine(&four);
//    GameEngine * gmeF = new MyGameEngine(&four);
//    ControlEngine * ceF = new MyControlEngine(&four);

    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
//    e.setGraphicEngine(geF);
//    e.setGameEngine(gmeF);
//    e.setControlEngine(ceF);
    
    e.start();
    
    
    
    return 0;
}
