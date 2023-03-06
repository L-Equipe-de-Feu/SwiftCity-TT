#include "ComArduino.h"

ComArduino::ComArduino(char* port, int baud)
{
	serial = new SerialPort(port, baud);
}

ComArduino::~ComArduino()
{
}

bool ComArduino::send(char date[4], char vitesse)
{
	char buffer[7] = {'T', date[0], date[1], date[2], date[3], '0', vitesse};

	if (!serial->isConnected())
	{
		return false;
	}

	serial->writeSerialPort(buffer, 7);

	cout << "Send" << endl;

	return true;
}
