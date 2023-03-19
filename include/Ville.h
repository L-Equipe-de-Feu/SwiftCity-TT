#ifndef VILLE_H
#define VILLE_H

#include <iostream>
#include <fstream>
#include "Batiment.h"
#include "terrain.h"
#include "structRessources.h"
#include "GestionnaireTemps.h"
#include "Curseur.h"
#include "Gazon.h"

#define TAILLEX 15
#define TAILLEY 30

#define PENTEHABS 0.2

class Ville
{
private:
    RessourcesVille ressourceTotal;
    GestionnaireTemps GT;
    Terrain* gridT[TAILLEX][TAILLEY];
    Batiment* gridB[TAILLEX][TAILLEY];
    long ticktime = 0;
    long ticktimelast = 0;
    long ticktimeH = 0;
    long tickHtimelast = 0;
    
    void calculRessources();
    void calculRessourcesIndependant();
    void calculRessourcesDependant();
    void catastrophe();
    bool isConstructible();
    
    void init();
public:
    Ville();
    ~Ville();

    bool construireBatiment(int x, int y, Batiment* b);
    bool construireRoute(int x, int y, Batiment* b);
    void detruire(int x, int y);
    void tick();
    void affiche(Curseur* curseur);
    void accelerer();
    void decelerer();
};

#endif