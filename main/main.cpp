#include <iostream>
#include <stdlib.h>
#include "ComArduino.h"
#include "MenuConsole.h"
#include "Curseur.h"
#include "Ville.h"
#include <ctime>
#include<windows.h>
using namespace std;
#define TAILLEX 15
#define TAILLEY 30

Batiment* gridB [TAILLEX][TAILLEY];
MenuConsole* menu = new MenuConsole();
Curseur* curseur = new Curseur(TAILLEX, TAILLEY);
Ville* ville = new Ville();

void main()
{
	char port[] = "COM4";
	int baud = 115200;
	ComArduino input(port, baud, menu, curseur, ville);
  
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
			if (input.getInerMenu()) {
				menu->afficher_Batiment_sousMenu();
			}
			lasttick = tick;
		}
		
		switch (input.lireClavier())
		{
		case 1:
			system("cls");
			ville->affiche(curseur);
			if (input.getInerMenu()) {
				menu->afficher_Batiment_sousMenu();
			}
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
