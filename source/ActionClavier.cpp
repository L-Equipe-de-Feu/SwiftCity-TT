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
    vector<uint8_t> buffer;

    size_t taille = serial.available();

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
