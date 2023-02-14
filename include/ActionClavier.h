/*
    Date : 04 février 2023
    Description : Declaration de la class action clavier
*/

#ifndef ACTIONCLAVIER_H
#define ACTIONCLAVIER_H

#include <iostream>
#include "Menu.h"
#include "Curseur.h"
#include "Ville.h"
#include "Maison.h"
#include "Usine.h"
#include "Magasin.h"
#include "Route.h"

class ActionClavier {
    private :
        char input;
        Menu* menu;
        Curseur* curseur;
        Ville* ville;

        bool inerMenu = false;
    public :
        ActionClavier(Menu* menuT, Curseur* curseurT, Ville* villeT);
        ~ActionClavier();
        bool lireClavier();

};
#endif