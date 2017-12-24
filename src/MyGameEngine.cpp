#include "MyGameEngine.h"
#include "Jeu.h"
#include <math.h>

/* méthode qui anime tous les objects dans la fenêtre */
void MyGameEngine::idle(){
    
    if (Jeu::getPause()) {
        return;
    }
    
    for (int v = 0; v < vaisseau->size(); v++) {
        (*vaisseau)[v]->tick();
        
        for (int a = 0; a < Vague::asteroides.size(); a++) {
            
            if (fabs((*vaisseau)[v]->getY() - Vague::asteroides[a].getCentreY()) < 0.01){
                //si il y a un vaisseau et un astéroide sur la même ligne.
                
                if (!Jeu::collision_Missile_Asteroide((*vaisseau)[v], a)){
                    Jeu::collision_Vaisseau_Asteroide(&(*vaisseau), v, a);
                }
            }
        }
    }
    
    for (auto i = 0; i < Vague::asteroides.size(); i++) {
        Jeu::vague.tick();
    }
    
    // Si le premier astroide atteind le bord
    if (Vague::asteroides.size() > 0 and Vague::asteroides.front().getVectorsX()[1] <= -1){
        
        Jeu::reduireVie(Vague::asteroides.front().getVie());
        Vague::asteroides.pop_front();
        
        //vérifier qu'il reste encore des vies dans le jeu
        if (Jeu::getVie() <= 0){
            Jeu::finJeu = true;
            Jeu::destructionObjets(&(*vaisseau));
        }
    }
}
