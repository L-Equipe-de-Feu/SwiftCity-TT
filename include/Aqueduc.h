/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour l'aqueduc
*/

#ifndef AQUEDUC_H
#define AQUEDUC_H

#include "Service.h"

class Aqueduc : public Service
{
private:
    /* data */
public:
    Aqueduc();
    ~Aqueduc();
    
    void afficher();
    char get_char();
};

Aqueduc::Aqueduc(){
    ressources.energie = -2;
    ressources.eau = 10;
    ressources.bonheur = 1;
    resso
    urces.materiaux = 0;
    ressources.argent = -250;
    ressources.habitant = -2;
}

Aqueduc::~Aqueduc(){}

void Aqueduc::afficher(){

}

char Aqueduc::get_char(){
    return 'w';
}

#endif