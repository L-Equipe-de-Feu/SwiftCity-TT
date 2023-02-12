/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour les batiments de culture
*/

#ifndef CULTURE_H
#define CULTURE_H

#include "Service.h"

class Culture : public Service
{
private:
    /* data */
public:
    Culture();
    ~Culture();

    void afficher();
    char get_char();
};

Culture::Culture(){
    ressources.energie = -10;
    ressources.eau = -5;
    ressources.bonheur = 20;
    ressources.materiaux = 0;
    ressources.argent = -250;
    ressources.habitant = -8;
}

Culture::~Culture(){}

void Culture::afficher(){

}

char Culture::get_char(){
    return ' ';
}

#endif