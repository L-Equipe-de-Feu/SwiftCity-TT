
#ifndef COMARDUINO_H
#define COMARDUINO_H

#include <iostream>
#include <math.h>
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

#define MaxMsgLen		20
#define MaxByte			5000
#define AdcRes			1023
#define AdcResMiddle	511
#define NODATAJ			9999
#define SHAKETRESHOLD	100

class ComArduino: public ActionClavier {
protected:
	SerialPort* serial;
	char incompleteMessage[MaxMsgLen];
	int leftLength;
	int lastAccel[3] = { 0,0,0 };
	void DetectShake(int x, int y, int z);
	Ville* pVille;
public:
	ComArduino(char* port, int baud, MenuConsole* menuT, Curseur* curseurT, Ville* villeT);
	~ComArduino();
	bool send(char* message, int bytes);
	bool lireManette();
};



#endif

