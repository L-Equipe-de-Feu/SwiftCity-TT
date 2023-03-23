
#define NOMINMAX

#include <iostream>
#include <stdlib.h>
#include "ComArduino.h"
#include "MenuConsole.h"
#include "Curseur.h"
#include "Ville.h"
#include <ctime>
#include <windows.h>

MenuConsole* menu = new MenuConsole();
Curseur* curseur = new Curseur(TAILLEX, TAILLEY);
Ville* ville = new Ville();

//position de curseur dans la console
typedef struct pos { int x = 0; int y = 0; };
pos curPosOrigin;		//0,0
pos curPosGrid;			//grid et info ville
pos curPosMenu;			//menu
pos curPosMessage;		//messages

void setCurPos(pos p)
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = p.x;
	Position.Y = p.y;
	SetConsoleCursorPosition(hOut, Position);
}

void setup() 
{
	//setup console
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);//fullscreen
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor invisible donc pas de flash
	SetConsoleCursorInfo(out, &cursorInfo);

	//setup cursor coord
	curPosGrid.x = 0;
	curPosGrid.y = 0;
	curPosMenu.x = 0;
	curPosMenu.y = 0;
	curPosMessage.x = 0;
	curPosMessage.y = 0;
}

void main()
{
	setup();

	char port[] = "COM4";
	int baud = 115200;
	ComArduino input(port, baud, menu, curseur, ville);
  
	long tick = time(0);
	long lasttick = tick;

	bool quit = false;

	char sendMsg[10] = "";

	//affiche la ville et le menu au départ
	system("cls");
	ville->affiche(curseur);
	if (input.getInerMenu()) {
		menu->afficher_Batiment_sousMenu();
	}
	else {
		menu->afficher_Controles();
	}

	do{
		//refresh l'affichage 
		tick = time(0);
		if (tick - lasttick >= 1)
		{			
			setCurPos(curPosOrigin);
			ville->tick();
			ville->affiche(curseur);
			menu->afficher_Controles();
			if (input.getInerMenu()) {
				menu->afficher_Batiment_sousMenu();
			}
			ville->getTempsStr(sendMsg);
			lasttick = tick;			
		}		
		
		if (input.lireClavier() || input.lireManette())
		{
			setCurPos(curPosOrigin);
			ville->affiche(curseur);
			menu->afficher_Controles();
			if (input.getInerMenu()) {
				menu->afficher_Batiment_sousMenu();
			}
			ville->getTempsStr(sendMsg);
		}

		if (sendMsg[0] != '\0')
		{
			input.send(sendMsg, strlen(sendMsg));
			sendMsg[0] = '\0';
		}

	} while (!input.getQuitState());

	delete menu;
	delete curseur;
	delete ville;
}

