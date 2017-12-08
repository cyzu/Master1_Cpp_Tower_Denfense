#include "MyGameEngine.h"
#include "Jeu.h"

/* méthode qui anime tous les objects dans la fenêtre */
void MyGameEngine::idle(){
    
    for (int i = 0; i < vaisseau->size(); i++) {
        (*vaisseau)[i]->tick();
        
        if ((*vaisseau)[i]->getVie() == 0) {
            std::cout<<"destruction vaisseau..."<<std::endl;
            vaisseau->erase(vaisseau->begin()+i);
        }
    }
    
    Jeu::asteroide.tick();
}
