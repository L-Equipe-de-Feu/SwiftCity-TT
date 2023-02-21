#include "ActionClavier.h"

using namespace std;

ActionClavier::ActionClavier(MenuConsole* menuT, Curseur* curseurT, Ville* villeT) {
    menu = menuT;
    curseur = curseurT;
    ville = villeT;
}


ActionClavier::~ActionClavier() {}


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
    vector<uint8_t> buffer;

    size_t taille = 0;//TODO serial.available();

    serial.read(buffer, taille);

    while(buffer.size() == 0)
    {
        switch (char(buffer.front()))
        {

        //case mouvement du curseur
        case 'J':
            buffer.erase(buffer.begin(), buffer.begin()+1);
            int x = int(buffer.at(0)) + int(buffer.at(1)) + int(buffer.at(2)) + int(buffer.at(3));
            buffer.erase(buffer.begin(), buffer.begin() + 4);
            int y = int(buffer.at(0)) + int(buffer.at(1)) + int(buffer.at(2)) + int(buffer.at(3));
            buffer.erase(buffer.begin(), buffer.begin() + 3);
            //Fonction curseur (x, y)
            cout << "Joystick : Jx" << x << "y" << y << endl;
            break;

        //bouton
        case 'A':
            //Fonction bouton A
            buffer.erase(buffer.begin());
            cout << "Bouton A pressé" << endl;
            break;
        case 'B':
            //Fonction bouton B
            buffer.erase(buffer.begin());
            cout << "Bouton B pressé" << endl;
            break;
        case 'M':
            //Fonction bouton MENU
            buffer.erase(buffer.begin());
            cout << "Bouton MENU pressé" << endl;
            break;
        case 'S':
            //Fonction bouton START
            buffer.erase(buffer.begin());
            cout << "Bouton START pressé" << endl;
            break;
        case 'D':
            //Fonction bouton arriere DROIT
            buffer.erase(buffer.begin());
            cout << "Bouton arriere DROIT pressé" << endl;
            break;
        case 'G':
            //Fonction bouton arriere GAUCHE
            buffer.erase(buffer.begin());
            cout << "Bouton arriere GAUCHE pressé" << endl;
            break;

        //Accéléromètre
        case 'C':
            //Fonction accéléromètre
            break;
        default:
            return true;
            break;
        }
    }
    return true;
}
*/