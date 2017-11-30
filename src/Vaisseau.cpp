//
//  Vaisseau.cpp
//  generical_libGraphProject
//
//  Created by Chloé BENSOUSSAN on 22/11/2017.
//  Copyright © 2017 Chloé Bensoussan. All rights reserved.
//

#include "Vaisseau.h"
#include "Missile.h"
#include "Case.h"
#include <math.h>
#include <unistd.h>

Vaisseau::Vaisseau(const float x_, const float y_, const float f, const float v, const float p){
    x = x_;
    y = y_;
    
    frequence = f;
    vitesse = v;
    puissance = p;
    
    missiles = new Missile(x+getVectorX(), y, puissance, vitesse);
}

Vaisseau::Vaisseau(const Vaisseau &v){
    x = v.x;
    y = v.y;
    
    frequence = v.frequence;
    vitesse = v.vitesse;
    puissance = v.puissance;
    
    missiles = v.missiles;
}

float Vaisseau::getX(){ return x; }
float Vaisseau::getY(){ return y; }
float Vaisseau::getFrequence(){ return frequence; }
float Vaisseau::getVitesse(){ return vitesse; }
float Vaisseau::getPuissance(){ return puissance; }

Missile* Vaisseau::getMissiles(){ return missiles; }

const float Vaisseau::getVectorX(){ return 0.07;}
const float Vaisseau::getVectorY(){ return (2/Case::nb_lignes)/3;}

void Vaisseau::setX(const float a){ x = a;}
void Vaisseau::setY(const float a){ y = a;}
void Vaisseau::setFrequence(const float f){ frequence = f;}
void Vaisseau::setVitesse(const float v){ vitesse = v;}
void Vaisseau::setPuissance(const float p){ puissance = p;}

void Vaisseau::draw(){
    const float vectorX = getVectorX();
    const float vectorY = getVectorY();
    GraphicPrimitives::drawFillTriangle2D(x+vectorX, y, x-vectorX, y+vectorY, x-vectorX, y-vectorY, r, g, b);
    missiles->draw();
}

void Vaisseau::tick(){
    
    // si la distance entre x1 du vaisseau et le missile == 1/frequence
   /* float distance = missiles->getX() - (getX()+getVectorX() + 1/getFrequence());
    distance = fabsf(distance); //valeur absolue
                                */
    /*if (distance <= 0.0001){
        Missile *newM = new Missile(x+getVectorX(), y, puissance, vitesse);
        newM->setMissileSuiv(missiles);
        
        missiles = newM;
    }*/
    
    for (Missile* i = missiles; i != NULL; i = i->getMissileSuiv()) {
        i->tick();
    }
    
    //std::cout<<std::endl;
    
    
    
}
