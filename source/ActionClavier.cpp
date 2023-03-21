#include "ActionClavier.h"
ActionClavier::ActionClavier()
{
}

using namespace std;

ActionClavier::ActionClavier(MenuConsole* menuT, Curseur* curseurT, Ville* villeT) {
    menu = menuT;
    curseur = curseurT;
    ville = villeT;
}

ActionClavier::~ActionClavier() 
{
    delete serial;
}


/// <summary>
/// getch non bloquant
/// </summary>
/// <returns>charactere detecte</returns>
int getch_noblock() {
    if (_kbhit())
        return _getch();
    else
        return -1;
}

int ActionClavier::lireClavier() {
    char input;
    input = getch_noblock();

    switch (input)
    {
        //case mouvement du curseur
    case 'w':
        if (inerMenu)
        {
            menu->bougerHaut();
        }
        else
        {
            curseur->bougerHaut();
        }
        
        return 1;
        break;
    case 'a':
        curseur->bougerGauche();
        return 1;
        break;
    case 's':
        if (inerMenu)
        {
            menu->bougerBas();
        }
        else
        {
            curseur->bougerBas();
        }
        return 1;
        break;
    case 'd':
        curseur->bougerDroit();
        
        return 1;
        break;
        //Fin case mouvement du curseur

        //case choix de construction
    //pourl'instant sur la touche n. le sub menu seras fait plus tard

    case 'q':
        //construire
        inerMenu = true;
        return 1;
        break;

    case 'r':
        //Construire une route
        ville->construireRoute(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Route);
        return 1;
        break;

    case 'x':
        ville->detruire(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y);
        break;

    case 'k':
        ville->decelerer();
        break;

    case 'l':
        ville->accelerer();
        break;

    case '1':
        if (inerMenu && menu->getValider()<1)
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
    case '2' :
        inerMenu = false;
        menu->sortir();
        souvien = nullptr;
        break;

    case '\x1b'://escape
        return -1;
        break;
    }

    return 0;

}


bool ActionClavier::lireManette()
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

    for(int i = 0; i < taille; i++)
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

int ActionClavier::cTi(char c)
{
    int i = c - '0';
    return i;
}

bool ActionClavier::getInerMenu()
{
    return inerMenu;
}

void ActionClavier::setInerMenu(bool menu)
{
    inerMenu = menu;
}
