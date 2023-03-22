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
#define menuLargeur 10
#define menuHauteur 4
using namespace std;

class MenuConsole{
private : 
    int choix = 0;
    int valide = 0;
    int premierChoix = 0;
    int deuxiemeChoix = 0;
    string textMenu[menuHauteur][menuLargeur] = { {"Residentiel", "Maison", "MultiLogement(WIP)"},
                                {"Industriel", "Usine"},
                                {"Commerciale", "Magasin", "Bureau(WIP)"},
                                {"Services", "Aqueduc", "Energie", "Culture", "Ecole(WIP)", "Police(WIP)", "Pompier(WIP)"} };
public :

    void afficher_menu() 
    {
        char* tabulation = "                                                               ";
        cout << tabulation << endl;
        cout << "Menu : " << tabulation << endl;
        cout << "Touches    |    Description" << tabulation << endl;
        cout << "Q          |    ouvrir menu de construction" << tabulation << endl;
        cout << "K          |    ralentir l'avencement du temps" << tabulation << endl;
        cout << "L          |    accelerer l'avencement du temps" << tabulation << endl;
        cout << "ESC        |    quitter le jeu" << tabulation << endl;
        //padding
        cout << tabulation << tabulation << endl;
        cout << tabulation << tabulation << endl;
        cout << tabulation << tabulation << endl;
        cout << tabulation << tabulation << endl;
    }

    void afficher_Batiment_sousMenu() {
        char* tabulation = "                                                              ";
        cout << tabulation << endl;
        cout << "Que voulez vous construire : " << tabulation << endl;

        if (valide == 0) 
        {
            for (int i = 0; i < menuHauteur; i++) {
                if (choix == i)
                {
                    cout << '>';
                }
                premierChoix = choix;
                cout << textMenu[i][0] << " : " << tabulation << endl;
            }
        }
        
        if (valide == 1)
        {
            cout << textMenu[premierChoix][0] << " : " << tabulation << endl;
            for (int e = 1; e < menuLargeur - 1; e++)
            {
                if (choix == e)
                {
                    cout << '>';
                }
                deuxiemeChoix = choix;
                cout << "\t" << textMenu[premierChoix][e] << tabulation << endl;
            }
        }
        //padding
        cout << tabulation << tabulation << endl;
        cout << "Pour naviguer dans le sous-menu:  1: selectionner,  2: sortir" << tabulation << endl;
        cout << tabulation << tabulation << endl;
        cout << tabulation << tabulation << endl;
        cout << tabulation << tabulation << endl;
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