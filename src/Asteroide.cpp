//
//  Asteroïdes.cpp
//  TowerDefence
//
//  Created by Chloé 雪乃 BENSOUSSAN 下村 on 08/12/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#include "Asteroide.h"
#include <vector>

Asteroide::Asteroide(const float x_, const float y_, const float v, const int life){
    centreX = x_;
    centreY = y_;
    vector = v;
    
    vie = life;
    
    initVectorsX();
    initVectorsY();
    
    red = life/10.0;   //0.5f; //life/0.5
    green = life/10.0; //0.5f;
    blue = life/16.6;  //0.3f;
}

void Asteroide::initVectorsX(){
    x.clear();
    x.push_back(getCentreX()+getVector());
    x.push_back(getCentreX()+getVector()+(getVector()/2));
    x.push_back(getCentreX()+getVector());
    x.push_back(getCentreX());
    x.push_back(getCentreX()-getVector());
    x.push_back(getCentreX()-getVector()-(getVector()/2));
    x.push_back(getCentreX()-getVector());
    x.push_back(getCentreX());
}

void Asteroide::initVectorsY(){
    y.clear();
    y.push_back(getCentreY()+getVector());
    y.push_back(getCentreY());
    y.push_back(getCentreY()-getVector());
    y.push_back(getCentreY()-getVector()-(getVector()/2));
    y.push_back(getCentreY()-getVector());
    y.push_back(getCentreY());
    y.push_back(getCentreY()+getVector());
    y.push_back(getCentreY()+getVector()+(getVector()/2));
}

void Asteroide::reduireVie(const int v){
    vie -= v;
    if (vie <= 0) vie = 0;
}

int Asteroide::getVie(){ return vie; }

std::vector<float> Asteroide::getVectorsX(){ return x; }
std::vector<float> Asteroide::getVectorsY(){ return y; }

void Asteroide::setCentreX(const float x_){
    centreX = x_;
    initVectorsX();
}

void Asteroide::setCentreY(const float y_){
    centreY = y_;
    initVectorsY();
}

void Asteroide::setVector(const float v){
    vector = v;
    initVectorsX();
    initVectorsY();
}

float Asteroide::getCentreX(){ return centreX; }
float Asteroide::getCentreY(){ return centreY; }
float Asteroide::getVector(){ return vector; }

void Asteroide::setRed(const float r) { red = r; }
void Asteroide::setGreen(const float g){ green = g; }
void Asteroide::setBlue(const float b){ blue = b; }

float Asteroide::getRed(){ return red; }
float Asteroide::getGreen(){ return green; }
float Asteroide::getBlue(){ return blue; }

void Asteroide::draw(){
    GraphicPrimitives::drawFillPolygone2D(x, y, red, green, blue);
    GraphicPrimitives::drawFillRect2D(x[4], y[4], getVector()*2, getVector()*2, red, green, blue);
}

void Asteroide::tick(const float v){
    setCentreX(getCentreX() - v);
}

