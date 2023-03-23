#include "ActionClavier.h"
using namespace std;

ActionClavier::ActionClavier(MenuConsole* menuT, Curseur* curseurT, Ville* villeT) {
    menu = menuT;
    curseur = curseurT;
    ville = villeT;
}

ActionClavier::~ActionClavier() 
{
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
        if (!inerMenu) curseur->bougerGauche();
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
        if (!inerMenu) curseur->bougerDroit();
        
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

    case 'm':
        menu->toggleShowHiddenMenu();
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

    case 'c':
        ville->declencherCatastrophe();
        break;

    case '\x1b'://escape
        return quit = true;
        break;
    }

    return 0;

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

bool ActionClavier::getQuitState() 
{
    return quit;
}