#include "ComArduino.h"

ComArduino::ComArduino(char* port, int baud, MenuConsole* menuT, Curseur* curseurT, Ville* villeT) : ActionClavier(menuT, curseurT, villeT)
{
	serial = new SerialPort(port, baud);
}

ComArduino::~ComArduino()
{
    delete serial;
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

bool ComArduino::lireManette()
{

    if (!serial->isConnected())
    {
        return false;
    }

    char buffer[MaxBit];

    size_t taille = serial->readSerialPort(buffer, MaxBit);

    if (taille <= 0)
    {
        return true;
    }

    for (int i = 0; i < taille; i++)
    {
        int x = 0;
        int y = 0;
        int z = 0;

        switch (buffer[i])
        {

            //case mouvement du curseur
        case 'J':
            if (i + 10 < taille)
            {
                i++;
                for (int j = 0; j < 4; j++)
                {
                    x += cTi(buffer[++i]) * mult[j];
                }

                i++;

                for (int j = 0; j < 4; j++)
                {
                    y += cTi(buffer[++i]) * mult[j];
                }
                //Fonction curseur (x, y)
                cout << "Joystick : Jx" << x << "y" << y << endl;
            }
            if (!inerMenu)
            {
                if (x != 9999) {
                    if (x > 511)
                    {
                        curseur->bougerDroit();
                    }
                    if (x < 511)
                    {
                        curseur->bougerGauche();
                    }
                }
                if (y != 9999) {
                    if (y > 511)
                    {
                        curseur->bougerHaut();
                    }
                    if (y < 511)
                    {
                        curseur->bougerBas();
                    }
                }
            }
            else
            {
                if (y != 9999) {
                    if (y > 511)
                    {
                        menu->bougerHaut();
                    }
                    if (y < 511)
                    {
                        menu->bougerBas();
                    }
                }
            }

            break;

            //bouton
        case 'A':
            //Fonction bouton A
            cout << "Bouton A presse" << endl;
            if (inerMenu && menu->getValider() < 1)
            {
                menu->valider();
            }
            else
            {
                ville->construireBatiment(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, menu->construire_Batiment_sousMenu());
                inerMenu = false;
                //menu->sortir();
            }
            break;
        case 'B':
            //Fonction bouton B
            cout << "Bouton B presse" << endl;
            inerMenu = false;
            menu->sortir();
            souvien = nullptr;
            break;
        case 'M':
            //Fonction bouton MENU
            cout << "Bouton MENU presse" << endl;
            inerMenu = true;
            break;
        case 'S':
            //Fonction bouton START
            cout << "Bouton START presse" << endl;
            ville->construireRoute(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Route);
            break;
        case 'D':
            //Fonction bouton arriere DROIT
            cout << "Bouton arriere DROIT presse" << endl;
            break;
        case 'G':
            //Fonction bouton arriere GAUCHE
            cout << "Bouton arriere GAUCHE presse" << endl;
            break;

            //Accéléromètre
        case 'C':
            if (i + 12 < taille)
            {
                i++;
                for (int j = 0; j < 3; j++)
                {
                    x += cTi(buffer[++i]) * mult[j + 1];
                }

                i++;

                for (int j = 0; j < 3; j++)
                {
                    y += cTi(buffer[++i]) * mult[j + 1];
                }

                i++;

                for (int j = 0; j < 3; j++)
                {
                    z += cTi(buffer[++i]) * mult[j + 1];
                }
                //Fonction accéléromètre (x, y, z)
                cout << "Accelerometre : Cx" << x << "y" << y << "z" << z << endl;
            }
            break;
        default:
            cout << "Non valide" << endl;
            break;
        }

    }

    return true;
}
