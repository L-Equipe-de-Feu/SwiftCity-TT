#include <iostream>
#include "ActionClavier.h"
#include "Menu.h"
#include "Curseur.h"
using namespace std;

int main(int argc)
{
	Menu* menu;
	Curseur* curseur = new Curseur(64, 64);
	ActionClavier clavier(menu, curseur);
	for(int i = 0; i<10; i++){
		clavier.lireClavier();
	}
	delete menu;
	delete curseur;
	return 1;
}