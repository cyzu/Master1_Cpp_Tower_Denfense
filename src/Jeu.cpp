//
//  Jeu.cpp
//  TowerDefence project
//
//  Created by Chloé BENSOUSSAN on 23/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#include "Jeu.h"
//#include "Engine.h"
//#include "Vaisseau.h"
#include <unistd.h>
#include <math.h>

int Jeu::vie = 50;
int Jeu::totalVaisseaux = 0;

std::vector<Vaisseau> Jeu::typesVaisseaux;
Vaisseau Jeu::choix(0.0f, 0.0f, 0.0f, -10, -10);
Vague Jeu::vague;

float Jeu::getCaseX(const int x){
    float window = glutGet(GLUT_WINDOW_WIDTH)/2;
    float posX = (x - window) / window;
    
    float i = -1;
    while(i < 1 && posX > i){
        i += 0.2;
    }
    posX = i - 0.1;
    return posX;
}
    
float Jeu::getCaseY(const int y){
    float window = glutGet(GLUT_WINDOW_HEIGHT)/2;
    float posY = (y - window) / window;
        
    float i = -1;
    while(i < 1 && posY > i){
        i += 2.0/getNombreLignes();
    }
    posY = i - 2.0/(2*getNombreLignes());
    return -posY;
}

void Jeu::reduireVie(const int i){
    vie = getVie() - i;
    if (vie <= 0) vie = 0;
}

int Jeu::getVie(){
    return vie;
}

int Jeu::getNombreLignes(){
    return nb_lignes;
}

void Jeu::ajouterVaisseau(Vaisseau v){
    typesVaisseaux.push_back(v);
}

void Jeu::addTotalVaisseaux(){
    totalVaisseaux ++;
}

int Jeu::getTotalVaisseaux(){
    return totalVaisseaux;
}

/* retourne si l'astéroide a été supprimé ou pas */
bool Jeu::collision_Missile_Asteroide(Vaisseau *v, const int a){
    if (v->getMissiles()->size() > 0){
        Missile missile = v->getMissiles()->front();
        if (fabs(missile.getX()+missile.getVector() - Vague::asteroides[a].getVectorsX()[5]) < 0.02){
            impactMissile(v, a);
            return impactAsteroide(v, a);
        }
    }
    return false;
}

void Jeu::collision_Vaisseau_Asteroide(std::vector<Vaisseau *> *v, const int i, const int a){
    if (fabs((*v)[i]->getX()+(*v)[i]->getVectorX() - Vague::asteroides[a].getVectorsX()[5]) < 0.01){
        impactVaisseau(v, i, a);
        Vague::asteroides.erase(Vague::asteroides.begin()+a);
    }
}

bool Jeu::impactAsteroide(Vaisseau *v, const int a){
    Vague::asteroides[a].reduireVie(v->getPuissance());
    if (Vague::asteroides[a].getVie() == 0){
        Vague::asteroides.erase(Vague::asteroides.begin()+a);
        std::cout<<"astéroide supprimé..."<<std::endl;
        return true;
    }
    else {
        //diminuer la couleur en fonction de la vie perdue
        float tauxRouge = (1.0 - Vague::asteroides[a].getRed())/6; // == vie d'un astéroide + 1
        float tauxVert = (1.0 - Vague::asteroides[a].getGreen())/6;
        float tauxBleu = (1.0 - Vague::asteroides[a].getBlue())/6;
        
        Vague::asteroides[a].setRed(Vague::asteroides[a].getRed() - v->getPuissance()*tauxRouge);
        Vague::asteroides[a].setGreen(Vague::asteroides[a].getGreen() - v->getPuissance()*tauxVert);
        Vague::asteroides[a].setBlue(Vague::asteroides[a].getBlue() -v->getPuissance()*tauxBleu);
        return false;
    }
}

void Jeu::impactMissile(Vaisseau *v, const int a){
    if (v->getPuissance() < 2.5 * Vague::asteroides[a].getVie()) v->getMissiles()->pop_front();
}

void Jeu::impactVaisseau(std::vector<Vaisseau *> *v, const int i, const int a){
    (*v)[i]->reduireVie(Vague::asteroides[a].getVie());
    if ((*v)[i]->getVie() == 0){
        v->erase(v->begin()+i);
        std::cout<<"vaisseau supprimé..."<<std::endl;
    }
    else {
        std::cout<<"vaisseau "<<i<<" vie : "<<(*v)[i]->getVie()<<std::endl;
        //diminuer la couleur en fonction de la vie perdue
        float tauxRouge = (1.0 - (*v)[i]->getRed())/((*v)[i]->getVie()+2); // == vie d'un vaisseau + 1
        float tauxVert = (1.0 - (*v)[i]->getGreen())/((*v)[i]->getVie()+2);
        float tauxBleu = (1.0 - (*v)[i]->getBlue())/((*v)[i]->getVie()+2);
    
        (*v)[i]->setRed((*v)[i]->getRed() - tauxRouge);
        (*v)[i]->setGreen((*v)[i]->getGreen() - tauxVert);//Vague::asteroides[a].getVie()*tauxVert);
        (*v)[i]->setBlue((*v)[i]->getBlue() - tauxBleu);
    }
}

void Jeu::finPartie(){
    Vague::asteroides.clear();
    
    std::cout<<"\nAFFICHAGE FIN DE PARTIE\n"<<std::endl;
    std::cout<<"Total de vaisseaux posé pendant la partie : "<<Jeu::getTotalVaisseaux()<<std::endl;
    std::cout<<"Nombre de vague réussie : "<<Vague::getTotalVagues()<<std::endl;
    
    sleep(2);
    exit(0);
}
