#include <iostream>
#include <vector>
#include "ActionClavier.h"
#include "Menu.h"
#include "Curseur.h"
#include "SerialPort.hpp"

using namespace std;
#define carre 20

Batiment* gridB [carre][carre];
Menu* menu = new Menu();
Curseur* curseur = new Curseur(carre, carre);
Ville* ville = new Ville();
SerialPort s;

int main(int argc)
{
	ActionClavier clavier(menu, curseur, ville);

	while(clavier.lireClavier()){
		ville->affiche(curseur);
	}

	delete menu;
	delete curseur;
	delete ville;

	return 1;
}
