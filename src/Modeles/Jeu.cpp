//
//  Jeu.cpp
//  TowerDefence project
//
//  Created by Chloé BENSOUSSAN on 23/11/2017.
//  Copyright © 2017 Chloé BENSOUSSAN. All rights reserved.
//

#include "Jeu.h"
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <sstream>
#include <iomanip>

int Jeu::vie = 20;
int Jeu::totalVaisseaux = 0;
int Jeu::tirelire = 50;

std::string Jeu::message = "Cliquez plusieurs fois sur une case pour choisir un vaisseau";

std::vector<Vaisseau> Jeu::typesVaisseaux;
std::vector<Asteroide> Jeu::typesAsteroides;

Vaisseau Jeu::choix(0.0f, 0.0f, 0.0f, -10, -10);
Vague Jeu::vague;

bool Jeu::pause = false;
bool Jeu::finJeu = false;


/* MÉTHODES */

void Jeu::initTypesVaisseaux(){
    Jeu::ajouterVaisseau(Vaisseau(0.4f, 0.0f, 0.2f, 0, 0, 6, 10, 3, 5, 17));// Bordeaux
    Jeu::ajouterVaisseau(Vaisseau(0.2f, 0.4f, 0.0f, 0, 0, 2, 6, 5, 10, 25)); // Vert
    Jeu::ajouterVaisseau(Vaisseau(0.4f, 0.2f, 0.0f, 0, 0, 9, 3, 1, 1, 7));// Marron
    Jeu::ajouterVaisseau(Vaisseau(0.0f, 0.2f, 0.4f, 0, 0, 1, 7, 15, 10, 50));// Bleu
}

void Jeu::initTypesAsteroides(){
    Jeu::ajouterAsteroide(Asteroide(0, 0, 0.0008, 0.035, 4));
    Jeu::ajouterAsteroide(Asteroide(0, 0, 0.0010, 0.04, 6));
    Jeu::ajouterAsteroide(Asteroide(0, 0, 0.0012, 0.045, 7));
    Jeu::ajouterAsteroide(Asteroide(0, 0, 0.0015, 0.05, 8));
    Jeu::ajouterAsteroide(Asteroide(0, 0, 0.0020, 0.055, 9));
}

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
    float posY = -((y - window) / window);
    
    float i = -1;
    while(i < 1 && posY > i){
        i += 1.8/getNombreLignes();
    }
    posY = i - 1.8/(2*getNombreLignes());
    return posY;
}

void Jeu::reduireVie(const int i){
    vie = getVie() - i;
    if (vie <= 0) vie = 0;
}

int Jeu::getVie(){
    return vie;
}

bool Jeu::payer(const int i){
    if (tirelire - i >= 0){
        tirelire -= i;
        return true;
    }
    return false;
}

void Jeu::gagner(const int a){
    tirelire += a;
}

int Jeu::getTirelire(){
    return tirelire;
}

int Jeu::getNombreLignes(){
    return nb_lignes;
}

void Jeu::ajouterVaisseau(Vaisseau v){
    typesVaisseaux.push_back(v);
}

void Jeu::ajouterAsteroide(Asteroide a){
    Jeu::typesAsteroides.push_back(a);
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
        if (Vague::asteroides[a].getVectorsX()[5] < 1 and fabs(missile.getX()+missile.getVector() - Vague::asteroides[a].getVectorsX()[5]) < 0.02){
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
    int gain = Vague::asteroides[a].getVie();
    Vague::asteroides[a].reduireVie(v->getPuissance());
    
    if (Vague::asteroides[a].getVie() == 0){
        
        Jeu::gagner(gain);
        Vague::asteroides.erase(Vague::asteroides.begin()+a);
        return true;
    }
    else {
        //diminuer la couleur en fonction de la vie perdue
        float tauxRouge = (1.0 - Vague::asteroides[a].getRed())/6; // == vie d'un astéroide + 1
        float tauxVert = (1.0 - Vague::asteroides[a].getGreen())/6;
        float tauxBleu = (1.0 - Vague::asteroides[a].getBlue())/6;
        
        Vague::asteroides[a].setRed(Vague::asteroides[a].getRed() - tauxRouge);
        Vague::asteroides[a].setGreen(Vague::asteroides[a].getGreen() - tauxVert);
        Vague::asteroides[a].setBlue(Vague::asteroides[a].getBlue() - tauxBleu);
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
    }
    else {
        //diminuer la couleur en fonction de la vie perdue
        float tauxRouge = (1.0 - (*v)[i]->getRed())/((*v)[i]->getVie()+2); // == vie d'un vaisseau + 1
        float tauxVert = (1.0 - (*v)[i]->getGreen())/((*v)[i]->getVie()+2);
        float tauxBleu = (1.0 - (*v)[i]->getBlue())/((*v)[i]->getVie()+2);
    
        (*v)[i]->setRed((*v)[i]->getRed() - tauxRouge);
        (*v)[i]->setGreen((*v)[i]->getGreen() - tauxVert);
        (*v)[i]->setBlue((*v)[i]->getBlue() - tauxBleu);
    }
}

void Jeu::changePause(){
    pause = !getPause();
}

bool Jeu::getPause(){
    return pause;
}

void Jeu::destructionObjets(std::vector<Vaisseau *> *v){
    sleep(1);
    Vague::asteroides.clear();
    
    for (int i = 0; i < v->size(); i++) {
        for (int j = 0; j < (*v)[i]->getMissiles()->size(); j++) {
            (*v)[i]->getMissiles()[j].clear();
        }
    }
    v->clear();
    
    sleep(1);
    Jeu::typesVaisseaux.clear();
    Jeu::typesAsteroides.clear();
}

void Jeu::setMessage(char *c){
    message = c;
}

std::string Jeu::getMessage(){ return message; }

void Jeu::affichageChoix(){
    Jeu::choix.draw();
    
    std::ostringstream fr;
    fr <<"Frequence : "<< std::setprecision(3) << Jeu::choix.getFrequence();
    std::string strFrequence = fr.str();
    
    std::ostringstream vi;
    vi<<"Vitesse : "<<std::setprecision(3)<<Jeu::choix.getVitesse();
    std::string strVitesse = vi.str();
    
    std::ostringstream pu;
    pu<<"Puissance : "<<std::setprecision(3)<<Jeu::choix.getPuissance();
    std::string strPuissance = pu.str();
    
    std::ostringstream di;
    di<<"Distance : "<<Jeu::choix.getDistance();
    std::string strDistance = di.str();

    std::ostringstream prix;
    prix<<"$ "<<Jeu::choix.getPrix();
    std::string strPrix = prix.str();
    
    float xDeriere = Jeu::choix.getX()+0.08;
    if (xDeriere > 0.6) xDeriere = Jeu::choix.getX() - 0.3;
    
    GraphicPrimitives::drawText2D(true, &strFrequence[0], xDeriere, Jeu::choix.getY()+0.10, 0.3f, 0.5f, 0.5f);
    GraphicPrimitives::drawText2D(true, &strVitesse[0], xDeriere, Jeu::choix.getY()+0.05, 0.3f, 0.5f, 0.5f);
    GraphicPrimitives::drawText2D(true, &strPuissance[0], xDeriere, Jeu::choix.getY(), 0.3f, 0.5f, 0.5f);
    GraphicPrimitives::drawText2D(true, &strDistance[0], xDeriere, Jeu::choix.getY()-0.05, 0.3f, 0.5f, 0.5f);
    GraphicPrimitives::drawText2D(true, &strPrix[0], xDeriere, Jeu::choix.getY()-0.10, 0.3f, 0.5f, 0.5f);
}

void Jeu::afficherInformations(){
    std::string strVie = std::to_string(Jeu::getVie()) + " vie(s)";
    GraphicPrimitives::drawText2D(false, &strVie[0], -0.95, 0.88, 0.9f, 0.7f, 0.7f);
    
    std::string strArgent = "$ " + std::to_string(Jeu::getTirelire());
    GraphicPrimitives::drawText2D(false, &strArgent[0], -0.73, 0.88, 0.9f, 0.9f, 0.7f);
    
    std::string strVague = "vague " + std::to_string(Vague::getTotalVagues()+1);
    GraphicPrimitives::drawText2D(false, &strVague[0], -0.55, 0.88, 0.7f, 0.7f, 0.8f);
}

void Jeu::afficherMessage(){
    GraphicPrimitives::drawText2D(true, &message[0], -0.2, 0.88, 0.7f, 0.7f, 0.7f);
}

void Jeu::finPartie(){

    std::string strJeu = "Vous n'avez plus de vie, la partie est terminee !";
    GraphicPrimitives::drawText2D(false, &strJeu[0], -0.42, 0.4, 0.4f, 0.4f, 0.4f);
    
    std::string strVaisseaux = "Nombre de vaisseau pose : " + std::to_string(Jeu::getTotalVaisseaux());
    GraphicPrimitives::drawText2D(false, &strVaisseaux[0], -0.25, 0.2, 0.4f, 0.3f, 0.4f);
    
    std::string strVague = "Nombre de vague reussie : " + std::to_string(Vague::getTotalVagues());
    GraphicPrimitives::drawText2D(false, &strVague[0], -0.25, 0.1, 0.4f, 0.3f, 0.4f);

    std::string strQuit = "Appuyez sur 'Entree' pour quitter le jeu.";
    GraphicPrimitives::drawText2D(true, &strQuit[0], -0.25, -0.4, 0.4f, 0.4f, 0.4f);
    
    std::string strMerci = "Merci beaucoup et j'espere que ca vous a plu ^^";
    GraphicPrimitives::drawText2D(false, &strMerci[0], -0.42, -0.6, 0.5f, 0.4f, 0.5f);
    
    std::string strAuthor = "Programming by Chloe Bensoussan";
    GraphicPrimitives::drawText2D(true, &strAuthor[0], 0.45, -0.95, 0.3f, 0.3f, 0.3f);
}
