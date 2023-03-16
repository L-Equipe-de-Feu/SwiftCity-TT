#include "ComArduino.h"

ComArduino::ComArduino(char* port, int baud)
{
	serial = new SerialPort(port, baud);
}

ComArduino::~ComArduino()
{
	delete serial;
}

bool ComArduino::send(int date, int vitesse)
{
	char buffer[7] = {'t', 0, 0, 0, 0, 0, vitesse};

	if (serial->isConnected())
	{
		return false;
	}

	return serial->writeSerialPort(buffer ,MaxBit);
}
