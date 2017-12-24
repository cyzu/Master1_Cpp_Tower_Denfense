
#include "MyGraphicEngine.h"
#include "Jeu.h"
//#include "Asteroide.h"
#include <string.h>

MyGraphicEngine::MyGraphicEngine(std::vector<Vaisseau * > * vaisseau_){
    vaisseau = vaisseau_;
}


void MyGraphicEngine::Draw(){
    
    if (Jeu::finJeu){
        Jeu::finPartie();
        return;
    }
    
    /* Quadrillage gris en fond (1.8 = marge de bande en tête pour écrire les informations */
    const float horizontal_scale  = 1.8/Jeu::getNombreLignes();
    for (float i = -1; i < 1; i += 0.2) { //vertical
        for (float j = -1; j < 1; j += horizontal_scale) { //horizontal
            GraphicPrimitives::drawLine2D(i, 0.8, i, -1, 0.10f, 0.10f, 0.10f);
            GraphicPrimitives::drawLine2D(-1, j, 1, j, 0.10f, 0.10f, 0.10f);
        }
    }
    
    if (Vague::asteroides.size() <= 0){
        GraphicPrimitives::drawText2D(false, "Appuyez sur 'Entree' pour lancer une nouvelle vague", -0.5, -0.5, 0.1f, 0.1f, 0.1f);
    }
    Jeu::afficherInformations();
    Jeu::afficherMessage();
    Jeu::affichageChoix();
    
    for (auto i = 0; i < Vague::asteroides.size(); i++) {
        Vague::asteroides[i].draw();
    }
    
    for (int i = 0; i < vaisseau->size(); i++) {
        (*vaisseau)[i]->draw();
    }
    
}

