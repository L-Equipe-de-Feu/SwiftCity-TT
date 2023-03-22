#include "ComArduino.h"

ComArduino::ComArduino(char* port, int baud, MenuConsole* menuT, Curseur* curseurT, Ville* villeT) : ActionClavier(menuT, curseurT, villeT)
{
	serial = new SerialPort(port, baud);

    //fill incomplete message buffer for safety
    for (int i = 0; i < MaxMsgLen; i++)
    {
        incompleteMessage[i] = '\0';
    }
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

	std::cout << "Send" << endl;

	return true;
}

bool ComArduino::lireManette()
{

    if (!serial->isConnected())
    {
        return false;
    }

    char buffer[MaxByte];

    size_t taille = serial->readSerialPort(buffer, MaxByte);

    if (taille <= 0)
    {
        return true;
    }

    if (leftLength > 0) 
    {
        //concat incomplete message at start of buffer with incoming buffer 
        sprintf(buffer, "%s%s", incompleteMessage, buffer);// TODO : à vérifier si fonctionne
        taille += leftLength;
    }

    bool incompleteMsg = false;
    unsigned int i = 0;

    while ( i < taille && !incompleteMsg)
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
                std::cout << "Joystick : Jx" << x << "y" << y << endl;
            }
            else 
            {
                incompleteMsg = true;
                break;
            }
            if (!inerMenu)
            {
                if (x != NODATAJ) {
                    if (x > AdcResMiddle)
                    {
                        curseur->bougerDroit();
                    }
                    if (x < AdcResMiddle)
                    {
                        curseur->bougerGauche();
                    }
                }
                if (y != NODATAJ) {
                    if (y > AdcResMiddle)
                    {
                        curseur->bougerHaut();
                    }
                    if (y < AdcResMiddle)
                    {
                        curseur->bougerBas();
                    }
                }
            }
            else
            {
                if (y != NODATAJ) {
                    if (y > AdcResMiddle)
                    {
                        menu->bougerHaut();
                    }
                    if (y < AdcResMiddle)
                    {
                        menu->bougerBas();
                    }
                }
            }

            break;

            //bouton
        case 'A':
            //Fonction bouton A
            std::cout << "Bouton A presse" << endl;
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
            std::cout << "Bouton B presse" << endl;
            inerMenu = false;
            menu->sortir();
            souvien = nullptr;
            break;
        case 'M':
            //Fonction bouton MENU
            std::cout << "Bouton MENU presse" << endl;
            inerMenu = true;
            break;
        case 'S':
            //Fonction bouton START
            std::cout << "Bouton START presse" << endl;
            ville->construireRoute(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Route);
            break;
        case 'D':
            //Fonction bouton arriere DROIT
            std::cout << "Bouton arriere DROIT presse" << endl;
            ville->accelerer();
            break;
        case 'G':
            //Fonction bouton arriere GAUCHE
            std::cout << "Bouton arriere GAUCHE presse" << endl;
            ville->decelerer();
            break;
            
        case 'C':
            //Accéléromètre
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
                std::cout << "Accelerometre : Cx" << x << "y" << y << "z" << z << endl;
            }
            else
            {
                incompleteMsg = true;
                break;
            }
            break;
        default:
            std::cout << "Non valide" << endl;
            break;
        }
        i++;
    }

    if(incompleteMsg)
    {
        leftLength = 0;
        for (int j = 0; j < taille; j++)
        {
            incompleteMessage[j] = buffer[i++];
            leftLength++;
        }
        incompleteMessage[leftLength++] = '\0';
    }
    else 
    {
        for (int j = 0; j < MaxMsgLen; j++)
        {
            incompleteMessage[j] = '\0';
        }
        leftLength = 0;
    }

    return true;
}
