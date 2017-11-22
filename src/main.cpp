

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
    
    std::vector<Papillon *> paps;
//    std::vector<Fourmis *> four;
    
    GraphicEngine * geP = new MyGraphicEngine(&paps);
    GameEngine * gmeP = new MyGameEngine(&paps);
    ControlEngine * ceP = new MyControlEngine(&paps);

//    GraphicEngine * geF = new MyGraphicEngine(&four);
//    GameEngine * gmeF = new MyGameEngine(&four);
//    ControlEngine * ceF = new MyControlEngine(&four);
    
    /*for (int i = 0; i < 10; i++) {
        x = rand() % 800;
        y = rand() % 600;
        paps.push_back(new Papillon((x-400) / 400.f, (y-300)/ -300.f ));
    }*/

    e.setGraphicEngine(geP);
    e.setGameEngine(gmeP);
    e.setControlEngine(ceP);
    
//    e.setGraphicEngine(geF);
//    e.setGameEngine(gmeF);
//    e.setControlEngine(ceF);
    
    e.start();
    
    
    
    return 0;
}
