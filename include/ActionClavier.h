/*
    Date : 04 février 2023
    Description : Declaration de la class action clavier
*/

#ifndef ACTIONCLAVIER_H
#define ACTIONCLAVIER_H

#include <iostream>
#include "SerialPort.hpp"
#include <conio.h>
#include "MenuConsole.h"
#include "Curseur.h"
#include "Ville.h"
#include "Route.h"
#include "SerialPort.hpp"
#include <vector>

#define Port "COM6"
#define Baud 115200
#define MaxBit 512

class ActionClavier {
    private :
        MenuConsole* menu;
        Curseur* curseur;
        Ville* ville;
        int mult[4] = { 1000, 100, 10, 1 };

        SerialPort* serial;

        int cTi(char c);

        bool inerMenu = false;
    public :
        ActionClavier();
        ActionClavier(MenuConsole* menuT, Curseur* curseurT, Ville* villeT);
        ~ActionClavier();
        int lireClavier();
        //bool lireManette();

};
#endif