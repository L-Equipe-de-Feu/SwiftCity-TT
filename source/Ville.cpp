#include "Ville.h"

using namespace std;

Ville::Ville() {
    init();
}

void Ville::init() {
    for (int i = 0; i < TAILLEX; i++) {
        for (int e = 0; e < TAILLEY; e++) {
            gridB[i][e] = NULL;
        }
    }
}

Ville::~Ville() {
    delete[] gridB;
    delete[] gridT;
}

void Ville::construireBatiment(int x, int y, Batiment* b) {
    //if(gridB[x+1][y]==Class(Route) || gridB[x-1][y]==Class(Route) || gridB[x][y+1]==Class(Route) || gridB[x][y-1]==Class(Route) && gridT[x][y]==constructible){
    gridB[x][y] = b;
    //}
}

void Ville::construireRoute(int x, int y, Batiment* b) {
    gridB[x][y] = b;
}

void Ville::affiche(Curseur* curseur) {
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    //rajouter les calcule de monayS ici pour les affichage
    cout << "Votre argent : " << endl;
    cout << "Votre income : " << endl;
    cout << "Votre Population : " << endl;

    cout << "|-------------------------------------------------------------------------------|" << endl;
    for (int i = 0; i < TAILLE; i++) {
        for (int e = 0; e < TAILLE; e++) {
            if (i == curseur->get_Coordonnee().x && e == curseur->get_Coordonnee().y) {
                cout << "| " << "." << " ";
            }
            else {
                cout << "| " << gridB[i][e]->get_char() << " ";
            }
        }
        cout << "|" << endl;
        cout << "|-------------------------------------------------------------------------------|" << endl;
    }
}

void Ville::detruire(int x, int y) 
{
    

}


void Ville::calculTotal()
{
    RessourcesVille tempRec;
    int temp;
    for (int i = 0; i < TAILLEX; i++)
    {
        for (int j = 0; j < TAILLEY; j++)
        {
            if (gridB[i][j] != NULL)
            {
                //energie
                temp = gridB[i][j]->GetRessources().energie;
                if (temp > 0) 
                {
                    tempRec.energieProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.energieCons += temp;
                }

                //eau
                temp = gridB[i][j]->GetRessources().eau;
                if (temp > 0)
                {
                    tempRec.eauProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.eauCons += temp;
                }

                //bonheur 
                temp = gridB[i][j]->GetRessources().bonheur;
                if (temp > 0)
                {
                    tempRec.bonheurProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.bonheurCons += temp;
                }

                //habitant
                temp = gridB[i][j]->GetRessources().habitant;
                if (temp > 0)
                {
                    tempRec.eauProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.eauCons += temp;
                }

                //materiaux
                temp = gridB[i][j]->GetRessources().materiaux;
                if (temp > 0)
                {
                    tempRec.eauProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.eauCons += temp;
                }

                //argent
                temp = gridB[i][j]->GetRessources().argent;
                if (temp > 0)
                {
                    tempRec.eauProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.eauCons += temp;
                }
            }
        }
    }

    //calcul habitants

    //calcul materiaux

    //calcul argent

}


void Ville::calculEnergie()
{
    
}

void Ville::calculProd()
{

}

void Ville::calculEau()
{

}

void Ville::calculBonheur()
{

}

void Ville::calculMaterieux()
{

}

void Ville::calculArgent()
{

}

void Ville::calculHabitant()
{

}

void Ville::catastrophe()
{

}

bool Ville::isConstructible()
{
    return true;
}
