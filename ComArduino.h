
#ifndef COMARDUINO_H
#define COMARDUINO_H

#include <iostream>
#include "SerialPort.hpp"
#include "ActionClavier.h"

class ComArduino: public ActionClavier {
public:
	ComArduino(char* port, int baud);
	~ComArduino();
	bool send(char date[4], char vitesse);
};



#endif

