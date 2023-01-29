/*
    Date : 26 janvier 2023
    Description : Classe pour l'energie
*/

#ifndef ENERGIE_H
#define ENERGIE_H

#include "Service.h"

class Energie : public Service
{
private:
    /* data */
public:
    Energie();
    ~Energie();
};

Energie::Energie(){
    ressources.energie = 20;
    ressources.eau = 0;
    ressources.bonheur = 1;
    ressources.materiaux = 0;
    ressources.argent = -250;
    ressources.habitant = -1;
}

Energie::~Energie(){}


#endif