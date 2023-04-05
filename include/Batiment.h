/*
    Date : 26 janvier 2023
    Description : construction de la classe batiment
        qui est virtuel
*/

#ifndef BATIMENT_H
#define BATIMENT_H

#include "StructRessources.h"
#include <string>
#include <tuple>

class Batiment {
protected:
    Ressources ressources; 
    int couts = 100;
    int refund = 50;
    bool isRoute = false;
public:    
    Batiment() { }

    Batiment(const Batiment& obj) 
    { 
        ressources = obj.ressources;
        couts = obj.couts;
        refund = obj.refund;
        isRoute = obj.refund;
    }

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

    virtual std::string get_string() // pour avoir le messsage complet pour la route
    {
        return " ";
    }

    virtual int get_Couts()
    {
        return couts;
    }

    virtual int get_Refund()
    {
        return refund;
    }

    virtual bool estRoute()
    { 
        return isRoute; 
    }

    virtual void change_voisin(bool up, bool left, bool right, bool down) //changement la valeur des voisin pour la route
    {
    }

    virtual std::tuple<bool, bool, bool, bool> get_voisin() { //retourne les voisin connu par une route
        return std::make_tuple(false, false, false, false);
    }

};


#endif