/*
    Date : 26 janvier 2023
    Description : construction de la classe batiment
        qui est virtuel
*/

#ifndef BATIMENT_H
#define BATIMENT_H

#include "StructRessources.h"

class Batiment {
protected:
    Ressources ressources;
    int couts = 10;
public:
    Batiment() { }

    virtual ~Batiment() {}

    void SetRessources(Ressources NRessources) 
    {
        ressources = NRessources;
    }
   
    Ressources GetRessources() 
    {
        return ressources;
    }

    virtual void afficher() {}
    

    virtual char get_char()
    {
        return ' ';
    }
};

#endif