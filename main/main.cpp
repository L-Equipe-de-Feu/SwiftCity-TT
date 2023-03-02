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
	ComArduino test(port, 115200);

	while (true)
	{
		test.send(0, 1);
		cout << "1" << endl;
		Sleep(1000);
		test.send(0, 2);
		cout << "2" << endl;
		Sleep(1000);
		test.send(0, 3);
		cout << "3" << endl;
		Sleep(1000);
		test.send(0, 4);
		cout << "4" << endl;
		Sleep(1000);
	}

	return 1;
}
