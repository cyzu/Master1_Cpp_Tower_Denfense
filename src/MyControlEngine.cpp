#include "MyControlEngine.h"
#include "Jeu.h"
#include "Vague.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        float x_ = Jeu::getCaseX(x);
        float y_ = Jeu::getCaseY(y);
        
        // Si on clique sur la bande d'en-tête
        if (y_ >= 0.8){
            annuler();
            return;
        }
        
        bool empty = true;
        
        for (auto i = 0; i < vaisseau->size(); i++) {
            if ((*vaisseau)[i]->getX() == x_ && (*vaisseau)[i]->getY() == y_){
                Jeu::setMessage("Il y a deja un vaisseau pose sur cette case !");
                empty = false;
                annuler();
            }
        }
        // le compteur se remet à zéro quand on change de case
        if (adding == true && (currentX != x_ || currentY != y_)){
            count = -1;
            currentX = x_;
            currentY = y_;
        }
        
        // Si la case est vide
        if (empty) {
            Jeu::setMessage("Appuyez sur 'delete' ou 'backspace' pour annuler");
            
            count++;
            int i = count % Jeu::typesVaisseaux.size();
            
            currentX = x_;
            currentY = y_;
            
            Jeu::choix.setRed(Jeu::typesVaisseaux[i].getRed());
            Jeu::choix.setGreen(Jeu::typesVaisseaux[i].getGreen());
            Jeu::choix.setBlue(Jeu::typesVaisseaux[i].getBlue());
            Jeu::choix.setX(x_);
            Jeu::choix.setY(y_);
            Jeu::choix.setFrequence(Jeu::typesVaisseaux[i].getFrequence());
            Jeu::choix.setVitesse(Jeu::typesVaisseaux[i].getVitesse());
            Jeu::choix.setPuissance(Jeu::typesVaisseaux[i].getPuissance());
            Jeu::choix.setDistance(Jeu::typesVaisseaux[i].getDistance());
            Jeu::choix.setPrix(Jeu::typesVaisseaux[i].getPrix());
            
            adding = true;
        }
    }
}

void MyControlEngine::KeyboardCallback(unsigned char key, int x, int y){
    if (key == '\r'){
        // Soit on est entrain de poser des vaisseaux
       if (adding == true){
           int i = count % Jeu::typesVaisseaux.size();

           if (Jeu::payer(Jeu::typesVaisseaux[i].getPrix())){
               vaisseau->push_back(new Vaisseau (Jeu::typesVaisseaux[i].getRed(),
                                    Jeu::typesVaisseaux[i].getGreen(),
                                    Jeu::typesVaisseaux[i].getBlue(),
                                    currentX, currentY,
                                    Jeu::typesVaisseaux[i].getFrequence(),
                                    Jeu::typesVaisseaux[i].getVitesse(),
                                    Jeu::typesVaisseaux[i].getPuissance(),
                                    Jeu::typesVaisseaux[i].getDistance(),
                                    Jeu::typesVaisseaux[i].getPrix()));
               
               Jeu::addTotalVaisseaux();
               //std::cout<<"Ma tirelire = "<<Jeu::getTirelire()<<std::endl;
           }
           else Jeu::setMessage("Vous n'avez pas assez d'argent pour poser ce vaisseau");// std::cout<<"Vous n'avez plus assez d'argents dans votre tirelire! ("<<Jeu::getTirelire()<<")"<<std::endl;
           annuler();
           
       }
        // Soit on lance une vague d'astéroides
       else {
           if (Vague::asteroides.size() == 0){
               Jeu::vague.nouvelleVague(1.1, 0, 0.04, Jeu::vague.getNombre()+1);
           }
           else Jeu::setMessage("La vague n'est pas encore terminee, battez-vous !"); //std::cout<<"La vague n'est pas encore terminée. Battez-vous!"<<std::endl;
       }
    }
    if (key == '\b' or key == 127){
        annuler();
    }
}

void MyControlEngine::annuler(){
    Jeu::choix.setRed(0.0f);
    Jeu::choix.setGreen(0.0f);
    Jeu::choix.setBlue(0.0f);
    Jeu::choix.setX(-10);
    Jeu::choix.setY(-10);
    
    adding = false;
    count = -1;
    
    currentX = -1;
    currentY = -1;
    
    Jeu::setMessage("Lancer une vague avec 'Entree'");
}
