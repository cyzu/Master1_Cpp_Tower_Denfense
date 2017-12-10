#include "MyControlEngine.h"
#include "Jeu.h"
#include "Vaisseau.h"
#include "Vague.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float x_ = Jeu::getCaseX(x);
        float y_ = Jeu::getCaseY(y);
        
        bool empty = true;
        
        for (auto i = 0; i < vaisseau->size(); i++) {
            if ((*vaisseau)[i]->getX() == x_ && (*vaisseau)[i]->getY() == y_){
                std::cout<<"Il y a déjà un vaisseau posé sur cette case. Changez !"<<std::endl;
                
                empty = false;
                annuler();
            }
        }
        
        // le compteur se remet à zéro quand on change de case
        if (adding == true && (currentX != x_ || currentY != y_)){
            std::cout<<"remise à zéro count"<<std::endl;
            count = -1;
            currentX = x_;
            currentY = y_;
        }
        
        // Si la case est vide
        if (empty) {
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
            
            adding = true;
        }
    }
}

void MyControlEngine::KeyboardCallback(unsigned char key, int x, int y){
    if (key == '\r'){
        //std::cout<<"Keyboard Callback : 'entrée'"<<key;
       if (adding == true){
          // std::cout<<" -- création vaisseau"<<key<<std::endl;
           int i = count % Jeu::typesVaisseaux.size();
        
           float x_ = Jeu::getCaseX(x);
           float y_ = Jeu::getCaseY(y);

           vaisseau->push_back(new Vaisseau (Jeu::typesVaisseaux[i].getRed(),
                                          Jeu::typesVaisseaux[i].getGreen(),
                                          Jeu::typesVaisseaux[i].getBlue(),
                                          x_, y_,
                                          Jeu::typesVaisseaux[i].getFrequence(),
                                          Jeu::typesVaisseaux[i].getVitesse(),
                                          Jeu::typesVaisseaux[i].getPuissance()));
           annuler();
           Jeu::addTotalVaisseaux();
       }
       else {
           //std::cout<<" -- autre"<<key<<std::endl;
           if (Vague::asteroides.size() == 0){
               Jeu::vague.nouvelleVague(1.1, 0, 0.04, Jeu::vague.getNombre()+1, Jeu::vague.getVitesse()+0.0001, Jeu::vague.getIntervalle()-0.008);
           
              // std::cout<<"Nombre de vague : "<<Vague::getTotalVagues()<<std::endl;
               //std::cout<<"mes vie : "<<Jeu::getVie()<<std::endl;
           }
       }
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
}
