#include <iostream>
#include <stdlib.h>
#include "ActionClavier.h"
#include "MenuConsole.h"
#include "Curseur.h"
#include "Ville.h"
#include "map.h"
#include <ctime>

#define TAILLEX 15
#define TAILLEY 30

Batiment* gridB [TAILLEX][TAILLEY];
MenuConsole* menu = new MenuConsole();
Curseur* curseur = new Curseur(TAILLEX, TAILLEY);
Ville* ville = new Ville();
terrainGenerator* terGen = new terrainGenerator(TAILLEX,TAILLEY);

void main()
{
	terGen->afficher();
	terGen->randomized_map(rand());
	//terGen->afficher();
}
