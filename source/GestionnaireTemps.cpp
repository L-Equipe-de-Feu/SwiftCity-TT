#include "GestionnaireTemps.h"

GestionnaireTemps::GestionnaireTemps()
{
	tm datejeu;
	datejeu.tm_year = 111;
	datejeu.tm_mday = 3;
	datejeu.tm_mon = 2;
	datejeu.tm_hour = 8;
	datejeu.tm_min = 0;
	datejeu.tm_sec = 0;
	datejeu.tm_isdst = 0;
	datejeu.tm_wday = 0;
	datejeu.tm_yday = 0;

	mktime(&datejeu);
	tempsPresent = datejeu;
	VT = X2;
}

GestionnaireTemps::GestionnaireTemps(int s, int mi, int h, int j, int mo, int a)
{
	//TODO
}

/// <summary>
/// avance le temps et retourne le temps avancer en jeu
/// </summary>
/// <param name="sec">quantité de sec a avancer</param>
/// <returns>nombre sec elapsed in game</returns>
int GestionnaireTemps::avancerTemps(unsigned int sec)
{
	//multiplicateur
	sec = sec * VT;
	tempsPresent.tm_sec += sec;

	mktime(&tempsPresent);

	return sec;
}

void GestionnaireTemps::changerVitesse(VitessesTemps newVT)
{
	VT = newVT;
}

char* GestionnaireTemps::time_to_str(int mode)
{
	char* output = new char[80];
	switch (mode)
	{
	case 1:
		strftime(output, 80, "T%m%d", &tempsPresent);
		break;
	case 2:
		strftime(output, 80, "%c", &tempsPresent);
		break;
	case 3:
		strftime(output, 80, "%Y %h %d %R", &tempsPresent);
		break;
	}

	return output;
}
