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
	tm datejeu;
	datejeu.tm_year = a-1900;
	datejeu.tm_mday = j;
	datejeu.tm_mon = mo;
	datejeu.tm_hour = h;
	datejeu.tm_min = mi;
	datejeu.tm_sec = s;
	datejeu.tm_isdst = 0;
	datejeu.tm_wday = 0;
	datejeu.tm_yday = 0;

	mktime(&datejeu);
	tempsPresent = datejeu;
	VT = X2;
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

VitessesTemps GestionnaireTemps::getVitesseTemps()
{
	return VT;
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
	case 4:
		time_t epoch = mktime(&tempsPresent);
		sprintf(output, "%li", epoch);
	}

	return output;
}

char* GestionnaireTemps::vitesse_to_str() 
{
	switch (VT)
	{
	case X1:
		return "X1";
		break;
	case X2:
		return "X2";
		break;
	case X3:
		return "X3";
		break;
	case X4:
		return "X4";
		break;
	default:
		return "vitesse inconnue !?!";
		break;
	}
}

void GestionnaireTemps::accelerer()
{
	switch (VT)
	{
	case X1:
		VT = X2;
		break;
	case X2:
		VT = X3;
		break;
	case X3:
		VT = X4;
		break;
	}
}

void GestionnaireTemps::decelerer()
{
	switch (VT)
	{
	case X2:
		VT = X1;
		break;
	case X3:
		VT = X2;
		break;
	case X4:
		VT = X3;
		break;
	}
}
