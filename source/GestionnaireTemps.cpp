#include "GestionnaireTemps.h"

GestionnaireTemps::GestionnaireTemps()
{
	time_t now = time(0);
	tempsPresent = *gmtime(&now);
	VT = X1;
}

GestionnaireTemps::GestionnaireTemps(int s, int mi, int h, int j, int mo, int a)
{
	//TODO
}

/// <summary>
/// avance le temps et retourne combien d'heure se sont écoulé
/// </summary>
/// <param name="sec">quantité de sec a avancer</param>
/// <returns>nombre de trigger de calcul de bien</returns>
int GestionnaireTemps::avancerTemps(unsigned int sec)
{
	//multiplicateur
	sec = sec * VT;

	tempsPresent.tm_sec += sec;

	mktime(&tempsPresent);

	return sec / 3600;
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
		strftime(output, 80, "%h %d %R", &tempsPresent);
		break;
	}

	return output;
}
