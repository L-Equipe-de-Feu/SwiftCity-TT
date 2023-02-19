#pragma once

typedef struct TempsDate
{
	int seconde = 0;
	int minute = 0;
	int heure = 0;
	int jour = 1;
	int mois = 1;
	int annee = 2000;
};

typedef enum VitessesTemps
{
	X1 = 30, 
	X2 = 60, 
	X3 = 300,
	X4 = 900
};

class GestionnaireTemps
{
private:
	TempsDate tempsPresent;
public:
	GestionnaireTemps();
	GestionnaireTemps(int s, int mi, int h, int j, int mo, int a);

	void avancerTemps(int sec);

	char* afficher(int mode);
	//mode 1: communication manette
	//mode 2: affichage complet
	//mode 3: affichage en jeu
};

