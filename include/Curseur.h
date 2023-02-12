
/*
    Date : 04 février 2023
    Description : Declaration de la class curseur
*/

#ifndef CURSEUR_H
#define CURSEUR_H

#include <iostream>
#include "Coordonnee.h"

using namespace std;

class Curseur {
    private :
        Coordonnee coordonnee;
        int largeur = 0;
        int hauteur = 0;
    public :
        Curseur(int hauteurT, int largeurT);
        ~Curseur();
        void bougerHaut();
        void bougerBas();
        void bougerDroit();
        void bougerGauche();
        Coordonnee get_Coordonnee();
        void afficher();
};

Curseur::Curseur(int hauteurT, int largeurT){
    hauteur = hauteurT;
    largeur = largeurT;
    coordonnee.x = 0;
    coordonnee.y = 0;
}

Curseur::~Curseur(){}

void Curseur::bougerHaut(){
    if(coordonnee.x != 0){
        coordonnee.x -= 1;
    }
}

void Curseur::bougerBas(){
    if(coordonnee.x != hauteur-1){
        coordonnee.x += 1;
    }
}

void Curseur::bougerDroit(){
    if(coordonnee.y != largeur-1){
        coordonnee.y += 1;
    }
}
        
void Curseur::bougerGauche(){
    if(coordonnee.y != 0){
        coordonnee.y -= 1;
    }
}

Coordonnee Curseur::get_Coordonnee(){
    return coordonnee;
}


#endif