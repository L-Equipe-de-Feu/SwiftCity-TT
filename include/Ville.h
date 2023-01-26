#ifndef VILLE_H
#define VILLE_H

#include <iostream>
#include "batiment.h"
#include "terrain.h"
#include "structRessources.h"

class Ville
{
private:
    Ressources ressourceTotal;
    Terrain* gridT[100][100];
    Batiment* gridB[100][100];
    int temps;

    void calculEnergie();
    void calculProd();
    void calculEau();
    void calculBonheur();
    void calculMaterieux();
    void calculArgent();
    void calculHabitant();
    void catastrophe();
    bool isConstructible();
public:
    Ville();
    ~Ville();

    void construireBatiment(int x, int y);
    void construireRoute(int x, int y);
    void detruire(int x, int y);
};
#endif