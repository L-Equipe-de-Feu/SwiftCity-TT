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
int map1[m][n];

void main()
{
	int x = 78;
	randomized_map(x, map1);
}
