
#ifndef COMARDUINO_H
#define COMARDUINO_H

#include <iostream>
#include "SerialPort.hpp"

#define MaxBit 512

class ComArduino {
private:
	SerialPort* serial;
public:
	ComArduino(char* port, int baud);
	~ComArduino();
	bool send(int date, int vitesse);
};



#endif

