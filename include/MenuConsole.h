/*
    Date : 04 février 2023
    Description : Declaration de la class menu
*/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Maison.h"
#include "MultiLogement.h"

#include "Usine.h"

#include "Magasin.h"
#include "Bureau.h"

#include "Aqueduc.h"
#include "Culture.h"
#include "Ecole.h"
#include "Energie.h"
#include "Police.h"
#include "Pompier.h"

using namespace std;

class MenuConsole{
public :

    Batiment* construire_Batiment_sousMenu(char input) {
        switch (input) {
        case '1':
            //construire maison
            cout << "\tQue voulez vous construire : \n" << "\t\tMaison : 1\n" << "\t\tMultiLogement(WIP) : 2\n";
            return construire_Redentiel_sousMenu(getch());
            break;
        case '2':
            //construire usine
            cout << "\tQue voulez vous construire : \n" << "\t\tUsine : 1\n";
            return construire_Industriel_sousMenu(getch());
            break;
        case '3':
            //construire magasin
            cout << "\tQue voulez vous construire : \n" << "\t\tMagasin : 1\n" << "\t\tBureau(WIP) : 2\n";
            return construire_Commerciale_sousMenu(getch());
            break;
        case '4' :
            //Construire un service
            cout << "\tQue voulez vous construire : \n" << "\t\tAqueduc : 1" << "\tEnergie : 2" << "\tCulture(WIP) : 3\n"
                 << "\t\tEcole(WIP) : 4" << "\tPolice(WIP) : 5" << "\tPompier(WIP) : 6";
            return construire_Service_sousMenu(getch());
            break;
        }
        return nullptr;
    }

    Batiment* construire_Redentiel_sousMenu(char input) {
        switch (input)
        {
        case '1':
            return new Maison;
            break;

        case '2':
            cout << "(WIP)";
            return new MultiLogement;
            break;
        }
        return nullptr;
    }

    Batiment* construire_Industriel_sousMenu(char input) {
        return new Usine;
        return nullptr;
    }

    Batiment* construire_Commerciale_sousMenu(char input) {
        switch (input)
        {
        case '1':
            return new Magasin;
            break;

        case '2':
            cout << "(WIP)";
            return new Bureau;
            break;
        }
        return nullptr;
    }

    Batiment* construire_Service_sousMenu(char input) {
        switch (input)
        {
        case '1':
            return new Energie;
            break;

        case '2':
            return new Aqueduc;
            break;

        case '3':
            cout << "(WIP)";
            return new Culture;
            break;

        case '4':
            cout << "(WIP)";
            return new Ecole;
            break;

        case '5':
            cout << "(WIP)";
            return new Police;
            break;

        case '6':
            cout << "(WIP)";
            return new Pompier;
            break;
        }
        return nullptr;
    }

};

#endif