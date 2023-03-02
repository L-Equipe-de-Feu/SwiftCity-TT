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
		test.comVitesse(1);
		cout << "1" << endl;
		Sleep(5000);
		test.comVitesse(2);
		cout << "2" << endl;
		Sleep(5000);
		test.comVitesse(3);
		cout << "3" << endl;
		Sleep(5000);
		test.comVitesse(4);
		cout << "4" << endl;
		Sleep(5000);
	}

	return 1;
}
