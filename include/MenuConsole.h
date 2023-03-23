/*
    Date : 04 février 2023
    Description : Declaration de la class menu
*/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstring>
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
#define menuLargeur 7
#define menuHauteur 4
using namespace std;

class MenuConsole{
private : 
    int choix = 0;
    int valide = 0;
    int premierChoix = 0;
    int deuxiemeChoix = 0;
    bool showHiddenMenu = false;
    string textMenu[menuHauteur][menuLargeur] = { {"Residentiel", "Maison", "MultiLogement(WIP)"},
                                {"Industriel", "Usine"},
                                {"Commerciale", "Magasin", "Bureau(WIP)"},
                                {"Services", "Aqueduc", "Energie", "Culture", "Ecole(WIP)", "Police(WIP)", "Pompier(WIP)"} };
    int nbElementMenu[menuHauteur] = { 2, 1, 2, 6 };

public :

    void afficher_Controles() 
    {
        char* tabulation = "                                                               ";
        cout << tabulation << tabulation << endl;
        cout << "Clavier  | Manette      |  Description" << tabulation << endl;
        cout << "WASD     | Joystick     |  Deplacement du curseur" << tabulation << endl;
        cout << "Q        | Menu         |  Ouvrir menu de construction" << tabulation << endl;
        cout << "R        | Start        |  Construire une route" << tabulation << endl;
        cout << "K        | Gach. Gauche |  ralentir l'avencement du temps" << tabulation << endl;
        cout << "L        | Gach. droit  |  accelerer l'avencement du temps" << tabulation << endl;
        cout << "ESC      |              |  quitter le jeu" << tabulation << endl;

        if (showHiddenMenu)
        {
        cout << "DEBUG" << tabulation << tabulation << endl;
        cout << "C        |              |  Declencher une catastrophe" << tabulation << endl;
        cout << "V        |              |  Simulation Shake" << tabulation << endl;
        cout << "O        |              |  Save" << tabulation << endl;
        cout << "P        |              |  Load" << tabulation << endl;
        }

        cout << tabulation << tabulation << endl;
    }

    void toggleShowHiddenMenu()
    {
        showHiddenMenu = !showHiddenMenu;
    }

    void afficher_Batiment_sousMenu() {
        showHiddenMenu = false;
        char* tabulation = "                                                                      ";
        cout << tabulation << tabulation << endl;
        cout << "Pour naviguer dans le menu:  1 ou A: selectionner,  2 ou B: retour" << tabulation << endl;
        cout << tabulation << tabulation << endl;
        cout << "Que voulez vous construire : " << tabulation << endl;

        if (valide == 0) 
        {
            for (int i = 0; i < menuHauteur; i++) {
                if (choix % menuHauteur == i )
                {
                    cout << '>';
                }
                premierChoix = choix % menuHauteur;
                cout << textMenu[i][0] << " : " << tabulation << endl;
            }
        }
        
        if (valide == 1)
        {
            cout << textMenu[premierChoix][0] << " : " << tabulation << endl;
            for (int e = 1; e < menuLargeur - 1; e++)
            {
                if ((choix % nbElementMenu[premierChoix])+1 == e)
                {
                    cout << '>';
                }
                deuxiemeChoix = (choix % nbElementMenu[premierChoix]) + 1;
                cout << "    " << textMenu[premierChoix][e] << tabulation << endl;
            }
        }
        
    }

    void bougerBas() {
        choix++;
    }

    void bougerHaut() {
        choix--;
    }

    void valider() {
        choix = 0;
        valide++;
    }

    int getValider() {
        return valide;
    }

    void sortir() {
        choix = 0;
        valide = 0;
        premierChoix = 0;
        deuxiemeChoix = 0;
    }

    //

    Batiment* construire_Batiment_sousMenu() {
        valide = 0;
        switch (premierChoix) {
        case 0:
            //construire maison
            return construire_Redentiel_sousMenu(deuxiemeChoix);
            break;
        case 1:
            //construire usine
            return construire_Industriel_sousMenu(deuxiemeChoix);
            break;
        case 2:
            //construire magasin
            return construire_Commerciale_sousMenu(deuxiemeChoix);
            break;
        case 3 :
            //Construire un service
            return construire_Service_sousMenu(deuxiemeChoix);
            break;
        }
        return nullptr;
    }

    Batiment* construire_Redentiel_sousMenu(int input) {
        switch (input)
        {
        case 1:
            return new Maison;
            break;

        case 2:
            return new MultiLogement;
            break;
        }
        return nullptr;
    }

    Batiment* construire_Industriel_sousMenu(int input) {
        return new Usine;
        return nullptr;
    }

    Batiment* construire_Commerciale_sousMenu(int input) {
        switch (input)
        {
        case 1:
            return new Magasin;
            break;

        case 2:
            return new Bureau;
            break;
        }
        return nullptr;
    }

    Batiment* construire_Service_sousMenu(int input) {
        switch (input)
        {
        case 1:
            return new Aqueduc;
            break;

        case 2:
            return new Energie;
            break;

        case 3:
            return new Culture;
            break;

        case 4:
            return new Ecole;
            break;

        case 5:
            return new Police;
            break;

        case 6:
            return new Pompier;
            break;
        }
        return nullptr;
    }

};

#endif