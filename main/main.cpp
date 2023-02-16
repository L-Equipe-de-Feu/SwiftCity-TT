#include <iostream>
#include <stdlib.h>
#include "ActionClavier.h"
#include "MenuConsole.h"
#include "Curseur.h"
#include "Ville.h"

using namespace std;
#define TAILLEX 15
#define TAILLEY 30

Batiment* gridB [TAILLEX][TAILLEY];
MenuConsole* menu = new MenuConsole();
Curseur* curseur = new Curseur(TAILLEX, TAILLEY);
Ville* ville = new Ville();

int main(int argc)
{
	ActionClavier clavier(menu, curseur, ville);

	while(clavier.lireClavier()){
		system("cls");
		ville->affiche(curseur);
	}

	delete menu;
	delete curseur;
	delete ville;

	return 1;
}
