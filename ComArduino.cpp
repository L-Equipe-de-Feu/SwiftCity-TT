#include "ComArduino.h"

ComArduino::ComArduino(char* port, int baud)
{
	serial = new SerialPort(port, baud);
}

ComArduino::~ComArduino()
{
	delete serial;
}

bool ComArduino::comVitesse(int vitesse)
{
	char buffer[1] = { vitesse };

	if (serial->isConnected())
	{
		return false;
	}

	return serial->writeSerialPort(buffer ,MaxBit);
}

bool ComArduino::comDate(int date)
{
	if (serial->isConnected())
	{
		return false;
	}

	return true;
}
