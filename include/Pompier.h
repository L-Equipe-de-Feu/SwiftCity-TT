/*
    Date : 26 janvier 2023
    Description : Classe pour les pompiers
*/

#ifndef POMPIER_H
#define POMPIER_H

#include "Service.h"

class Pompier : public Service
{
private:
    /* data */
public:
    Pompier();
    ~Pompier();

    void afficher();
    char get_char();
};

Pompier::Pompier(){
    ressources.energie = -1;
    ressources.eau = -5;
    ressources.bonheur = 10;
    ressources.materiaux = 0;
    ressources.argent = -100;
    ressources.habitant = -4;
}

Pompier::~Pompier(){}

void Pompier::afficher(){

}

char Pompier::get_char(){
    return ' ';
}

#endif