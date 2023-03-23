
#ifndef COMARDUINO_H
#define COMARDUINO_H

#include <iostream>
#include <math.h>
#include <ctime>
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
#define SHAKETRESHOLD	75
#define RECORETRYTIME	5		//SECONDS

class ComArduino: public ActionClavier {
protected:
	char portName[20] = "COM4";
	int baudrate = 115200;
	SerialPort* serial;
	char incompleteMessage[MaxMsgLen];
	int leftLength = 0;
	int lastAccel[3] = { 0,0,0 };
	void DetectShake(int x, int y, int z);

	long lastReconnect = 0;

public:
	ComArduino(char* port, int baud, MenuConsole* menuT, Curseur* curseurT, Ville* villeT);
	~ComArduino();
	bool send(char* message, int bytes);
	bool lireManette();
	bool reconnect();
};



#endif

