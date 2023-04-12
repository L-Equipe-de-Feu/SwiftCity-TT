#include "ComArduino.h"

ComArduino::ComArduino(char* port, int baud, MenuConsole* menuT, Curseur* curseurT, Ville* villeT) : ActionClavier(menuT, curseurT, villeT)
{
    sprintf(portName, "%s", port);
    baudrate = baud;
	serial = new SerialPort(port, baud);

    menu = menuT;
    curseur = curseurT;
    ville = villeT;

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

bool ComArduino::send(char* message, int bytes)
{
	if (!serial->isConnected())
	{
        if (!reconnect())
        {
            return false;
        }
	}

	serial->writeSerialPort(message, bytes);

	//std::cout << "Send" << endl;

	return true;
}

bool ComArduino::reconnect() 
{
    if (time(0) - lastReconnect >= RECORETRYTIME) 
    {
        delete serial;
        serial = new SerialPort(portName, baudrate);

        lastReconnect = time(0);

        return serial->isConnected();
    }
    else 
    {
        return false;
    }   
}

bool ComArduino::lireManette()
{

    if (!serial->isConnected())
    {
        if (!reconnect())
        {
            return false;
        }
        
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
        sprintf(buffer, "%s%s", incompleteMessage, buffer);
        taille += leftLength;
    }

    bool incompleteMsg = false;
    unsigned int i = 0;
    char* space = "                                                      ";

    while ( i < taille && !incompleteMsg)
    {
        int x = 0;
        int y = 0;
        int z = 0;
        int muon = 0;

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
                //std::cout << "Joystick : Jx" << x << "y" << y << space << endl;
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
                    if (y < AdcResMiddle)
                    {
                        curseur->bougerHaut();
                    }
                    if (y > AdcResMiddle)
                    {
                        curseur->bougerBas();
                    }
                }
            }
            else
            {
                if (y != NODATAJ) {
                    if (y < AdcResMiddle)
                    {
                        menu->bougerHaut();
                    }
                    if (y > AdcResMiddle)
                    {
                        menu->bougerBas();
                    }
                }
            }

            break;

            //bouton
        case 'A':
            //Fonction bouton A
            std::cout << "Bouton A presse" << space << endl;
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
            std::cout << "Bouton B presse" << space << endl;
            inerMenu = false;
            menu->sortir();
            souvien = nullptr;
            break;
        case 'M':
            //Fonction bouton MENU
            std::cout << "Bouton MENU presse" << space << endl;
            inerMenu = true;
            break;
        case 'S':
            //Fonction bouton START
            std::cout << "Bouton START presse" << space << endl;
            ville->construireRoute(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Route);
            break;
        case 'D':
            //Fonction bouton arriere DROIT
            std::cout << "Bouton arriere DROIT presse" << space << endl;
            ville->accelerer();
            break;
        case 'G':
            //Fonction bouton arriere GAUCHE
            std::cout << "Bouton arriere GAUCHE presse" << space << endl;
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

                DetectShake(x,y,z);
                //Fonction accéléromètre (x, y, z)
                //std::cout << "Accelerometre : Cx" << x << "y" << y << "z" << z << endl;
            }
            else
            {
                incompleteMsg = true;
                break;
            }
            break;

        //case detecteur de muons
        case 'W':
            if (i + 9 < taille)
            {
                i++;
                for (int j = 0; j < 9; j++)
                {
                    muon += cTi(buffer[++i]) * pow(10,(8-j));
                }

                //Fonction muon (muon)
                std::cout << "muon : W" << muon << endl;
            }
            else
            {
                incompleteMsg = true;
                break;
            }

        default:
            //std::cout << "Non valide" << space << endl;
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

    std::cout << space << space << endl;

    return true;
}

void ComArduino::DetectShake(int x, int y, int z) 
{
    if (abs(x - lastAccel[0]) >= SHAKETRESHOLD) { ville->Shake(); }
    lastAccel[0] = x;
    if (abs(y - lastAccel[1]) >= SHAKETRESHOLD) { ville->Shake(); }
    lastAccel[1] = y;
    if (abs(z - lastAccel[2]) >= SHAKETRESHOLD) { ville->Shake(); }
    lastAccel[2] = z;
}
