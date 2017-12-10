#include "MyGameEngine.h"
#include "Jeu.h"
#include <math.h>
#include <unistd.h>

/* méthode qui anime tous les objects dans la fenêtre */
void MyGameEngine::idle(){
    
    // pour tous les vaisseaux
    for (int v = 0; v < vaisseau->size(); v++) {
        (*vaisseau)[v]->tick();
        
        // pour tous les astéroides
        for (int a = 0; a < Vague::asteroides.size(); a++) {
            //si il y a un ou plusieurs astéroides sur la même ligne qu'un des vaisseaux
            if (fabs((*vaisseau)[v]->getY() - Vague::asteroides[a].getCentreY()) < 0.01){
                
                Jeu::collision_Missile_Asteroide((*vaisseau)[v], a);
            }
        }

        
    
        if ((*vaisseau)[v]->getVie() == 0) {
            std::cout<<"destruction vaisseau..."<<std::endl;
            vaisseau->erase(vaisseau->begin()+v);
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
