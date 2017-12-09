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
    
    for (auto i = 0; i < Vague::asteroides.size(); i++) {
        //Vague::asteroides[i].tick();
        Jeu::vague.tick();
    }
    // Si le premier atteind le bord
    if (Vague::asteroides.size() > 0 and Vague::asteroides.front().getVectorsX()[1] <= -1){
        std::cout<<"destruction d'astéroides..."<<std::endl;
        Jeu::reduireVie(Vague::asteroides.front().getVie());
        Vague::asteroides.pop_front();
        
        //vérifier qu'il reste encore des vies dans le jeu
        if (Jeu::getVie() <= 0){
            //engine->start();
            //engine->stop();
            
            //vaisseau->clear();
            Jeu::finPartie();
        }
        
        // Créer une nouvelle vague quand il n'y a plus d'astéroides
        /*if (Vague::asteroides.size() == 0){
            Jeu::vague.nouvelleVague(1.1, 0, 0.04, Jeu::vague.getNombre()+1, Jeu::vague.getVitesse()+0.0001, Jeu::vague.getIntervalle()-0.005);
            
            std::cout<<"Nombre de vague : "<<Vague::getTotalVagues()<<std::endl;
            std::cout<<"mes vie : "<<Jeu::getVie()<<std::endl;
        }*/
    }
    
    // Si le dernier a atteint la bord gauche
    /*if (Jeu::asteroides[Jeu::asteroides.size() - 1].getCentreX() < -1){
        Jeu::addTotalVagues();
    }*/
    
    //TODO : où incrémenter totalVagues
    //condition de fin du jeu
}
