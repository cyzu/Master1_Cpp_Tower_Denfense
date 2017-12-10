#include "MyGameEngine.h"
#include "Jeu.h"

/* méthode qui anime tous les objects dans la fenêtre */
void MyGameEngine::idle(){
    
    for (int i = 0; i < vaisseau->size(); i++) {
        (*vaisseau)[i]->tick();
        
        Missile premierM = (*vaisseau)[i]->getMissiles().front();
        
        for (int j = 0; j < Vague::asteroides.size(); j++) {
            //if (premierM = )
            //TODO effet de collision !!!!
        }
        
        
        
        if ((*vaisseau)[i]->getVie() == 0) {
            std::cout<<"destruction vaisseau..."<<std::endl;
            vaisseau->erase(vaisseau->begin()+i);
        }
    }
    
    for (auto i = 0; i < Vague::asteroides.size(); i++) {
        Jeu::vague.tick();
    }
    
    // Si le premier atteind le bord
    if (Vague::asteroides.size() > 0 and Vague::asteroides.front().getVectorsX()[1] <= -1){
        std::cout<<"destruction d'astéroides..."<<std::endl;
        Jeu::reduireVie(Vague::asteroides.front().getVie());
        Vague::asteroides.pop_front();
        
        //vérifier qu'il reste encore des vies dans le jeu
        if (Jeu::getVie() <= 0){
            Jeu::finPartie();
        }
    }
}
