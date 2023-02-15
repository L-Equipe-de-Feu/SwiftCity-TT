#ifndef VILLE_H
#define VILLE_H

#include <iostream>
#include "Batiment.h"
#include "terrain.h"
#include "structRessources.h"
#include "Curseur.h"
#define TAILLEX 20
#define TAILLEY 20

#define PENTEHABS 0.2

class Ville
{
private:
    RessourcesVille ressourceTotal;
    Terrain* gridT[TAILLEX][TAILLEY];
    Batiment* gridB[TAILLEX][TAILLEY];
    int temps;
    
    void calculRessources();
    void calculRessourcesRapide();
    void catastrophe();
    bool isConstructible();
    void tick();
    void init();
public:
    Ville();
    ~Ville();

    void construireBatiment(int x, int y, Batiment* b);
    void construireRoute(int x, int y, Batiment* b);
    void detruire(int x, int y);

    void affiche(Curseur* curseur);
};

#endif