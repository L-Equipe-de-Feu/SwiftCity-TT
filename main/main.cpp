#include <iostream>
#include <stdlib.h>
#include "ActionClavier.h"
#include "MenuConsole.h"
#include "Curseur.h"
#include "Ville.h"
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
	ActionClavier clavier(menu, curseur, ville);
	long tick = time(0);
	long lasttick = tick;


	bool quit = false;
	do{
		tick = time(0);
		if (tick - lasttick >= 1) 
		{			
			system("cls");
			ville->tick();
			ville->affiche(curseur);
			lasttick = tick;
		}
		
		switch (clavier.lireClavier())
		{
		case 1:
			system("cls");
			ville->affiche(curseur);
			break;
		case -1:
			quit = true;
			break;
		} 

	} while (!quit);

	delete menu;
	delete curseur;
	delete ville;
}
