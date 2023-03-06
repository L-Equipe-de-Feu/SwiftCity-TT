#include <iostream>
#include <vector>
#include "ActionClavier.h"
#include "ComArduino.h"
#include "Menu.h"
#include "Curseur.h"
#include "SerialPort.hpp"

#include<windows.h>

using namespace std;

int main(int argc)
{
	char port[] = "COM4";
	int baud = 115200;
	ComArduino test(port, baud);

	char date[4] = { '0', '0', '0', '0' };

	while (true)
	{
		test.lireManette();
		test.send(date, '1');
		Sleep(50);
		test.send(date, '0');
		Sleep(50);
	}

	return 1;
}
