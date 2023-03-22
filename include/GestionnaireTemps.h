#pragma once
#include <iostream>
#include <ctime>
#include <chrono>

enum VitessesTemps
{
	X0 = 0,//pause
	X1 = 60, 
	X2 = 900, 
	X3 = 1800,
	X4 = 3600
};

class GestionnaireTemps
{
private:
	tm tempsPresent;
	VitessesTemps VT;
public:
	GestionnaireTemps();
	GestionnaireTemps(int s, int mi, int h, int j, int mo, int a);

	int avancerTemps(unsigned int sec);

	void changerVitesse(VitessesTemps newVT);
	
	VitessesTemps getVitesseTemps();
	
	char* vitesse_to_str();

	void accelerer();
	void decelerer();

	char* time_to_str(int mode);
	//mode 1: communication manette
	//mode 2: affichage complet
	//mode 3: affichage en jeu
};

