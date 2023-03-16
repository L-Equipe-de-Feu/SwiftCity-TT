#include "ActionClavier.h"
ActionClavier::ActionClavier() 
{
    serial = new SerialPort(Port, Baud);
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
        curseur->bougerHaut();
        return 1;
        break;
    case 'a':
        curseur->bougerGauche();
        return 1;
        break;
    case 's':
        curseur->bougerBas();
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
        cout << "Que voulez vous construire : \n" << "\tResidentiel : 1\n" << "\tIndustriel : 2\n" << "\tCommerciale : 3\n" << "\tServices : 4\n";
        ville->construireBatiment(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, menu->construire_Batiment_sousMenu(getch()));
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

    case '\x1b'://escape
        return -1;
        break;
    }
    return 0;

}
/*TODO serial comm
bool ActionClavier::lireManette()
{   
    if (!serial->isConnected())
    {
        return false;
    }

    char buffer[MaxBit];

    size_t taille = serial->readSerialPort(buffer, MaxBit);

    for(int i = 0; i < taille; i++)
    {
        int x = 0;
        int y = 0;
        int z = 0;

        switch (buffer[i])
        {

        //case mouvement du curseur
        case 'J':
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
            break;

        //bouton
        case 'A':
            //Fonction bouton A
            cout << "Bouton A presse" << endl;
            break;
        case 'B':
            //Fonction bouton B
            cout << "Bouton B presse" << endl;
            break;
        case 'M':
            //Fonction bouton MENU
            cout << "Bouton MENU presse" << endl;
            break;
        case 'S':
            //Fonction bouton START
            cout << "Bouton START presse" << endl;
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
            i++;
            for (int j = 0; j < 3; j++)
            {
                x += cTi(buffer[++i]) * mult[j+1];
            }

            i++;

            for (int j = 0; j < 3; j++)
            {
                y += cTi(buffer[++i]) * mult[j+1];
            }

            i++;

            for (int j = 0; j < 3; j++)
            {
                z += cTi(buffer[++i]) * mult[j+1];
            }
            //Fonction accéléromètre (x, y, z)
            cout << "Accelerometre : Cx" << x << "y" << y << "z" << z << endl;
            break;
        default:
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
