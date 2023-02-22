#include <iostream>
#include <vector>
#include "ActionClavier.h"
#include "Menu.h"
#include "Curseur.h"
#include "SerialPort.hpp"

using namespace std;

int main(int argc)
{
	ActionClavier clavier;

	while(clavier.lireManette()){}

	return 1;
}
