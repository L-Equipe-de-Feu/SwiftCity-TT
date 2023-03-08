#include <iostream>
#include <stdlib.h>
#include "ActionClavier.h"
#include "MenuConsole.h"
#include "Curseur.h"
#include "Ville.h"
#include "map.h"
#include <ctime>

using namespace std;
#define TAILLEX 15
#define TAILLEY 30

Batiment* gridB [TAILLEX][TAILLEY];
MenuConsole* menu = new MenuConsole();
Curseur* curseur = new Curseur(TAILLEX, TAILLEY);
Ville* ville = new Ville();

void main()
{
	char map1[m][n];
	int x = 24;
	randomized_map(x, map1);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cout << map1[m][n] << endl;
}
