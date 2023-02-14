
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
        Curseur(int hauteurT, int largeurT) {
            hauteur = hauteurT;
            largeur = largeurT;
            coordonnee.x = 0;
            coordonnee.y = 0;
        }
        ~Curseur() {}
        void bougerHaut() {
            if (coordonnee.x != 0) {
                coordonnee.x -= 1;
            }
        }
        void bougerBas() {
            if (coordonnee.x != hauteur - 1) {
                coordonnee.x += 1;
            }
        }
        void bougerDroit() {
            if (coordonnee.y != largeur - 1) {
                coordonnee.y += 1;
            }
        }
        void bougerGauche() {
            if (coordonnee.y != 0) {
                coordonnee.y -= 1;
            }
        }
        Coordonnee get_Coordonnee() {
            return coordonnee;
        }
        void afficher() {}
};

#endif