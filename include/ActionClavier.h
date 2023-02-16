/*
    Date : 04 février 2023
    Description : Declaration de la class action clavier
*/

#ifndef ACTIONCLAVIER_H
#define ACTIONCLAVIER_H

#include <iostream>
#include <conio.h>
#include "MenuConsole.h"
#include "Curseur.h"
#include "Ville.h"
#include "Route.h"

class ActionClavier {
    private :
        MenuConsole* menu;
        Curseur* curseur;
        Ville* ville;
        bool inerMenu = false;

    public :
        ActionClavier(MenuConsole* menuT, Curseur* curseurT, Ville* villeT);
        ~ActionClavier();
        bool lireClavier();

};
#endif