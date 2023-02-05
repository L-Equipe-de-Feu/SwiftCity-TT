/*
    Date : 04 février 2023
    Description : Declaration de la class action clavier
*/

#ifndef ACTIONCLAVIER_H
#define ACTIONCLAVIER_H

#include "Menu.h"
#include "Curseur.h"

class ActionClavier {
    private :
        char input;
        Menu* menu;
        Curseur* curseur;
        bool inerMenu = false;
    public :
        ActionClavier(Menu* menuT, Curseur* curseurT);
        ~ActionClavier();
        char lireClavier();


};

ActionClavier::ActionClavier(Menu* menuT, Curseur* curseurT){
    menu = menuT;
    curseur = curseurT;
}


ActionClavier::~ActionClavier(){}

    
char ActionClavier::lireClavier(){
    char input;
    cin >> input;

    switch (input)
    {
        //case mouvement du curseur
    case 'w':
        curseur->bougerHaut();
        break;
    case 'a':
        curseur->bougerGauche();
        break;
    case 's':
        curseur->bougerBas();
        break;
    case 'd':
        curseur->bougerDroit();
        break;
        //Fin case mouvement du curseur
        
        //case choix de construction
    //pourl'instant sur la touche n. le sub menu seras fait plus tard
    case 'n':
        inerMenu = true;
        cout<< "construi un batiment\n";
        break;
    case 'f':
        if(inerMenu){
            //monter le menu
        }
        break;
    case 'v':
        if(inerMenu){
            //desendre le menu
        }
        break;

    case '1':
        //construire maison
        break;
    case '2':
        //construire usine
        break;
    case '3':
        //construire magasin
        break;
    
    case 'r':
        cout<<"construire une route\n";
        break;

    default:
        break;
    }
}

#endif