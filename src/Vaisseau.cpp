//
//  Vaisseau.cpp
//  TowerDefence project
//
//  Created by Chloé BENSOUSSAN on 22/11/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#include "Vaisseau.h"
#include "Missile.h"
#include "Jeu.h"
#include <math.h>
#include <unistd.h>

//int Vaisseau::totalVaisseaux = 0;

Vaisseau::Vaisseau(const float r_, const float g_, const float b_, const float x_, const float y_, const float f, const float v, const float p){
    x = x_;
    y = y_;
    
    frequence = 1 - (0.1 * f);
    vitesse = v;
    puissance = p;
    
    vie = 15;
    
    red = r_;
    green = g_;
    blue = b_;
    
    Missile m(x+getVectorX(), y, puissance, vitesse);
    missiles.push_back(m);
}

Vaisseau::Vaisseau(const Vaisseau &v){
    x = v.x;
    y = v.y;
    
    red = v.red;
    green = v.green;
    blue = v.blue;
    
    frequence = v.frequence;
    vitesse = v.vitesse;
    puissance = v.puissance;
    
    vie = v.vie;
}

float Vaisseau::getX(){ return x; }
float Vaisseau::getY(){ return y; }

float Vaisseau::getFrequence(){ return frequence; }
float Vaisseau::getVitesse(){ return vitesse; }
float Vaisseau::getPuissance(){ return puissance; }

float Vaisseau::getRed(){ return red;}
float Vaisseau::getGreen(){ return green;}
float Vaisseau::getBlue(){ return blue;}

int Vaisseau::getCountF(){ return countF; }
int Vaisseau::getVie(){ return vie;}

std::deque<Missile>* Vaisseau::getMissiles(){ return &missiles; }

const float Vaisseau::getVectorX(){ return 0.07;}
const float Vaisseau::getVectorY(){ return (2.0/Jeu::getNombreLignes())/3;}

void Vaisseau::setX(const float a){ x = a;}
void Vaisseau::setY(const float a){ y = a;}

void Vaisseau::setFrequence(const float f){ frequence = 1 - (0.1*f);}
void Vaisseau::setVitesse(const float v){ vitesse = v;}
void Vaisseau::setPuissance(const float p){ puissance = p;}

void Vaisseau::setRed(const float r){ red = r;}
void Vaisseau::setGreen(const float g){ green = g;}
void Vaisseau::setBlue(const float b){ blue = b;}

void Vaisseau::setCountF(const int i){ countF = i; }
void Vaisseau::reduireVie(const int i){
    vie = getVie() - i;
    if (vie <= 0) vie = 0;
}

void Vaisseau::draw(){
    const float vectorX = getVectorX();
    const float vectorY = getVectorY();
    GraphicPrimitives::drawFillTriangle2D(x+vectorX, y, x-vectorX, y+vectorY, x-vectorX, y-vectorY, red, green, blue);
    
    for (auto i = 0; i < missiles.size(); i++) {
        missiles[i].draw();
    }
}

void Vaisseau::tick(){
    
    // Gestion de temps d'intervalle pour créer une nouvelle missile
    if (getCountF() >= getFrequence()*150){
        Missile m(getX()+getVectorX(), y, puissance, vitesse);
        missiles.push_back(m);
        //std::cout<<"Test reduce vie vaisseau"<<std::endl;
        //reduce(getPuissance());
        setCountF(0);
    }
    
    // Animer les missiles
    for (auto i = 0; i < missiles.size(); i++) {
        if (missiles[i].getX() >= 1) missiles.pop_front();
        missiles[i].tick();
    }
    setCountF(getCountF()+1);
}
