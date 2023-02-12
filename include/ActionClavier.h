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

ActionClavier::ActionClavier(Menu* menuT, Curseur* curseurT,  Ville* villeT){
    menu = menuT;
    curseur = curseurT;
    ville = villeT;
}


ActionClavier::~ActionClavier(){}

    
bool ActionClavier::lireClavier(){
    char input;
    cin >> input;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    //rajouter les calcule de monay ici pour les affichage


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
        ville->construireBatiment(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Maison);
        break;
    case '2':
        //construire usine
        ville->construireBatiment(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Usine);
        break;
    case '3':
        //construire magasin
        ville->construireBatiment(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Magasin);
        break;
    
    case 'r':
        cout<<"construire une route\n";
        ville->construireRoute(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Route);
        break;

    default:
        return false;
        break;
    }
    return true;

}

#endif