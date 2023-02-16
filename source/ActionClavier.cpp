#include "ActionClavier.h"

using namespace std;

ActionClavier::ActionClavier(MenuConsole* menuT, Curseur* curseurT, Ville* villeT) {
    menu = menuT;
    curseur = curseurT;
    ville = villeT;
}


ActionClavier::~ActionClavier() {}


bool ActionClavier::lireClavier() {
    char input;
    input = getch();

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

    case 'q':
        //construire
        cout << "Que voulez vous construire : \n" << "\tResidentiel : 1\n" << "\tIndustriel : 2\n" << "\tCommerciale : 3\n" << "\tServices : 4\n";
        ville->construireBatiment(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, menu->construire_Batiment_sousMenu(getch()));
        break;

    case 'r':
        //Construire une route
        ville->construireRoute(curseur->get_Coordonnee().x, curseur->get_Coordonnee().y, new Route);
        break;
        
    case '0':
        return false;
        break;

    default:
        break;
    }
    return true;

}
