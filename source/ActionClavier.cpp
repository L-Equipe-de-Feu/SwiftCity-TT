#include "ActionClavier.h"

ActionClavier::ActionClavier(Menu* menuT, Curseur* curseurT, Ville* villeT) {
    menu = menuT;
    curseur = curseurT;
    ville = villeT;
}


ActionClavier::~ActionClavier() {}


bool ActionClavier::lireClavier() {
    char input;
    cin >> input;

    switch (input)
    {
        //case mouvement du curseur
    case 'w':
        curseur->bougerHaut();
        break;
    case 'a':
        curseur->bougerGauche();
        break;
    case 's':
        curseur->bougerBas();
        break;
    case 'd':
        curseur->bougerDroit();
        break;
        //Fin case mouvement du curseur

        //case choix de construction
    //pourl'instant sur la touche n. le sub menu seras fait plus tard
    case 'n':
        inerMenu = true;
        cout << "construi un batiment\n";
        break;
    case 'f':
        if (inerMenu) {
            //monter le menu
        }
        break;
    case 'v':
        if (inerMenu) {
            //desendre le menu
        }
        break;

    case '1':
        //construire maison
        ville->construireBatiment(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Maison);
        break;
    case '2':
        //construire usine
        ville->construireBatiment(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Usine);
        break;
    case '3':
        //construire magasin
        ville->construireBatiment(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Magasin);
        break;

    case 'r':
        //Construire une route
        ville->construireRoute(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Route);
        break;

    default:
        return false;
        break;
    }
    return true;

}

bool ActionClavier::lireManette()
{   
    SerialPort serial(Port, Baud);

    if (!serial.isConnected())
    {
        return false;
    }

    char buffer[MaxBit];

    size_t taille = serial.readSerialPort(buffer, MaxBit);

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
            for (int j = 0; j < 4; j++)
            {
                x += cTi(buffer[++i]) * mult[j];
            }

            i++;

            for (int j = 0; j < 4; j++)
            {
                y += cTi(buffer[++i]) * mult[j];
            }

            i++;

            for (int j = 0; j < 4; j++)
            {
                z += cTi(buffer[++i]) * mult[j];
            }
            //Fonction accéléromètre (x, y, z)
            cout << "Accelerometre : Cx" << x << "y" << y << "z" << z << endl;
            break;
        default:
            return true;
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