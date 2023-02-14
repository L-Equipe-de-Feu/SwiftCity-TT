/*
    Date : 26 janvier (creation)
    Description : Classe pour les multi logement
*/

#ifndef MULTILOGEMENT_H
#define MULTILOGEMENT_H

#include "Residentiel.h"

class MultiLogement : public Residentiel{
private:
    /* data */
public:
    MultiLogement() {
        ressources.energie = -10;
        ressources.eau = -5;
        ressources.bonheur = 0;
        ressources.materiaux = 0;
        ressources.argent = -200;
        ressources.habitant = 15;
    }
    ~MultiLogement() {}

    void afficher() {

    }
    char get_char() {
        return 'M';
};

#endif