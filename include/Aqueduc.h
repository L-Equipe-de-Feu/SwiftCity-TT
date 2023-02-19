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
    Aqueduc() 
    {
        ressources.energie = -2;
        ressources.eau = 10;
        ressources.bonheur = 1;
        ressources.materiaux = 0;
        ressources.argent = -250;
        ressources.habitant = -2;
    }

    ~Aqueduc() {}
    
    void afficher() {}
    
    char get_char() 
    {
        return 'w';
    }
};

#endif