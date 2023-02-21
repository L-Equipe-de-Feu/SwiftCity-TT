/*
    Date : 04 février 2023
    Description : Declaration de la class action clavier
*/

#ifndef ACTIONCLAVIER_H
#define ACTIONCLAVIER_H

#include <iostream>
#include "SerialPort.hpp"
#include "Menu.h"
#include "Curseur.h"
#include "Ville.h"
#include "Maison.h"
#include "Usine.h"
#include "Magasin.h"
#include "Route.h"

#define Port "COM6"
#define Baud 115200
#define MaxBit 255

class ActionClavier {
    private :
        char input;
        Menu* menu;
        Curseur* curseur;
        Ville* ville;
        int mult[4] = { 1000, 100, 10, 1 };

        int cTi(char c);

        bool inerMenu = false;
    public :
        ActionClavier(Menu* menuT, Curseur* curseurT, Ville* villeT);
        ~ActionClavier();
        bool lireClavier();
        bool lireManette();

};
#endif