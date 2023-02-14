/*
    Date : 26 janvier 2023
    Description : Structure pour les batiments Commercial
*/

#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Batiment.h"

class Commercial : public Batiment {
private:
    /* data */
public:
    Commercial();
    ~Commercial();

    virtual void afficher()=0;
    virtual char get_char()=0;
};

Commercial::Commercial(){
    ressources.energie = -1;
    ressources.eau = -1;
    ressources.bonheur = 0;
    ressources.materiaux = -1;
    ressources.argent = -1;
    ressources.habitant = -1;
}

Commercial::~Commercial(){}

#endif