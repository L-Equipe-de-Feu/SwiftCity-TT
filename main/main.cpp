
#define NOMINMAX

#include <iostream>
#include <stdlib.h>
#include "ComArduino.h"
#include "MenuConsole.h"
#include "Curseur.h"
#include "Ville.h"
#include <ctime>
#include <windows.h>
#define TAILLEX 15
#define TAILLEY 30

MenuConsole* menu = new MenuConsole();
Curseur* curseur = new Curseur(TAILLEX, TAILLEY);
Ville* ville = new Ville();

void clearscreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);//fullscreen
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor invisible donc pas de flash
	SetConsoleCursorInfo(out, &cursorInfo);

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
			clearscreen();
			ville->tick();
			ville->affiche(curseur);
			if (input.getInerMenu()) {
				menu->afficher_Batiment_sousMenu();
			}
			else {
				menu->afficher_menu();
			}
			lasttick = tick;
		}
		
		switch (input.lireClavier() || input.lireManette())
		{
		case 1:
			clearscreen();
			ville->affiche(curseur);
			if (input.getInerMenu()) {
				menu->afficher_Batiment_sousMenu();
			}
			else {
				menu->afficher_menu();
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

