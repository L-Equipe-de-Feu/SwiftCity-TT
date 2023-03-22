
#ifndef COMARDUINO_H
#define COMARDUINO_H

#include <iostream>
#include "SerialPort.hpp"
#include "ActionClavier.h"

#include "Maison.h"
#include "MultiLogement.h"

#include "Usine.h"

#include "Magasin.h"
#include "Bureau.h"

#include "Aqueduc.h"
#include "Culture.h"
#include "Ecole.h"
#include "Energie.h"
#include "Police.h"
#include "Pompier.h"

#define MaxBit 512

class ComArduino: public ActionClavier {
protected:
	SerialPort* serial;
public:
	ComArduino(char* port, int baud, MenuConsole* menuT, Curseur* curseurT, Ville* villeT);
	~ComArduino();
	bool send(char date[4], char vitesse);
	bool lireManette();
};



#endif

