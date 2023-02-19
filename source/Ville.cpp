#include "Ville.h"

using namespace std;

Ville::Ville() {
    init();   
}

void Ville::init() {
    for (int i = 0; i < TAILLEX; i++) {
        for (int e = 0; e < TAILLEY; e++) {
            gridB[i][e] = nullptr;
        }
    }

    //starting ressources
    ressourceTotal.argentTot = 50000;
    ressourceTotal.bonheurPour = 50;
    ressourceTotal.materiauxTot = 1000;
}

Ville::~Ville() {
    delete[] gridB;
    delete[] gridT;
}

bool Ville::construireBatiment(int x, int y, Batiment* b) {
    //1.verify index
    if (x < 0 || y < 0 || x >= TAILLEX || y >= TAILLEY) 
    {
        cout << "index erroné" << endl;
        return false;
    }
    //2.verify if spot ok
    if (gridB[x][y] != nullptr)
    {
        cout << "building deja a cette position" << endl;
        return false;
    }
    //3.verify ressources
    
    //4.ajouter batiment
    gridB[x][y] = b;
    //5.update ressource ville

    

    return true;
}

bool Ville::construireRoute(int x, int y, Batiment* b) {
    gridB[x][y] = b;
    
    //TODO
    //1.verify if spot ok
    //2.verify ressources
    //3.update ressource ville

    return true;
}

void Ville::affiche(Curseur* curseur) {
    //tick();
    //cout << endl << endl << endl << endl << endl << endl << endl << endl;
    //rajouter les calcules ici pour les affichage
    cout << "Votre argent : " << ressourceTotal.argentTot << endl;
    cout << "Votre income : " << ressourceTotal.argentProd << endl;
    cout << "Votre Population : " << ressourceTotal.habitantTot << " / " << ressourceTotal.habitantMax << endl;
    cout << "Votre Energie : " << ressourceTotal.energieCons << "/" << ressourceTotal.energieProd << endl;
    cout << "Votre Eau : " << ressourceTotal.eauCons << "/" << ressourceTotal.eauProd << endl;

    
    cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
    for (int i = 0; i < TAILLEX; i++) {
        for (int e = 0; e < TAILLEY; e++) {
            if (i == curseur->get_Coordonnee().x && e == curseur->get_Coordonnee().y) {
                cout << "| " << "." << " ";
            }
            else 
            {
                if (gridB[i][e] == NULL)
                {
                    cout << "| " << "  ";
                }
                else 
                {
                    cout << "| " << gridB[i][e]->get_char() << " ";
                }
            }
        }
        cout << "|" << endl;
        cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl;
    }
}

void Ville::detruire(int x, int y) 
{
    delete gridB[x][y];
    gridB[x][y] = nullptr;
}

/// <summary>
/// calcul toute les donnée pour un tick, repasse sur tout les elements
/// </summary>
void Ville::calculRessources()
{
    RessourcesVille tempRec;
    int temp;
    for (int i = 0; i < TAILLEX; i++)
    {
        for (int j = 0; j < TAILLEY; j++)
        {
            if (gridB[i][j] != nullptr)
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
                    tempRec.habitantMax += temp;
                }
                else if (temp < 0)
                {
                    tempRec.habitantTrav += temp;
                }

                //materiaux
                temp = gridB[i][j]->GetRessources().materiaux;
                if (temp > 0)
                {
                    tempRec.materiauxProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.materiauxCons += temp;
                }

                //argent
                temp = gridB[i][j]->GetRessources().argent;
                if (temp > 0)
                {
                    tempRec.argentProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.argentCons += temp;
                }
            }
        }
    }
    //calcul bonheur
    if (tempRec.bonheurCons > 0)
    {
        tempRec.bonheurPour = 100 * tempRec.bonheurProd / tempRec.bonheurCons;

        if (tempRec.bonheurPour > 100)
        {
            tempRec.bonheurPour = 100;
        }
        else if (tempRec.bonheurPour < 0)
        {
            tempRec.bonheurPour = 0;
        }
    }
    else
    {
        tempRec.bonheurPour = 75;
    }
    

    //calcul habitants
    int gain = (tempRec.bonheurPour-50)* PENTEHABS ;
    tempRec.habitantTot = ressourceTotal.habitantTot + gain;

    if (tempRec.habitantTot <= 0)//game over???
    {
        tempRec.habitantTot;
    }
    else if (tempRec.habitantTot >= tempRec.habitantMax)
    {
        tempRec.habitantTot = tempRec.habitantMax;
    }

    //calcul materiaux
    int manquant = 0;
    float travRatio = tempRec.habitantTot / tempRec.habitantTrav;
    if (travRatio > 1.0)
    {
        travRatio = 1.0;
    }
    else if (travRatio < 0)
    {
        travRatio = 0;
    }

    tempRec.materiauxTot = ressourceTotal.materiauxTot + (tempRec.materiauxProd * travRatio) - tempRec.materiauxCons;
    if (tempRec.materiauxTot < 0)
    {
        manquant = tempRec.materiauxTot;
        tempRec.materiauxTot = 0;
    }

    //calcul argent
    if (manquant == 0) 
    {
        tempRec.argentTot = ressourceTotal.argentTot + tempRec.argentProd - tempRec.argentCons;
    }
    else
    {
        float matRatio = (tempRec.materiauxCons - manquant) / tempRec.materiauxCons;
        tempRec.argentTot = ressourceTotal.argentTot + (tempRec.argentProd * matRatio) - tempRec.argentCons;
    }

    //transfer
    ressourceTotal = tempRec;

}

/// <summary>
/// update seulement les totaux
/// </summary>
void Ville::calculRessourcesRapide()
{
    RessourcesVille tempRec = ressourceTotal;
    //calcul materiaux    
    tempRec.bonheurPour = 100 * tempRec.bonheurProd / tempRec.bonheurCons;

    if (tempRec.bonheurPour > 100)
    {
        tempRec.bonheurPour = 100;
    }
    else if (tempRec.bonheurPour < 0)
    {
        tempRec.bonheurPour = 0;
    }

    //calcul habitants
    int gain = (tempRec.bonheurPour - 50) * PENTEHABS;
    tempRec.habitantTot = ressourceTotal.habitantTot + gain;

    if (tempRec.habitantTot <= 0)//game over???
    {
        tempRec.habitantTot;
    }
    else if (tempRec.habitantTot >= tempRec.habitantMax)
    {
        tempRec.habitantTot = tempRec.habitantMax;
    }

    //calcul materiaux
    int manquant = 0;
    float travRatio = tempRec.habitantTot / tempRec.habitantTrav;
    if (travRatio > 1.0)
    {
        travRatio = 1.0;
    }
    else if (travRatio < 0)
    {
        travRatio = 0;
    }

    tempRec.materiauxTot = ressourceTotal.materiauxTot + (tempRec.materiauxProd * travRatio) - tempRec.materiauxCons;
    if (tempRec.materiauxTot < 0)
    {
        manquant = tempRec.materiauxTot;
        tempRec.materiauxTot = 0;
    }

    //calcul argent
    if (manquant == 0)
    {
        tempRec.argentTot = ressourceTotal.argentTot + tempRec.argentProd - tempRec.argentCons;
    }
    else
    {
        float matRatio = (tempRec.materiauxCons - manquant) / tempRec.materiauxCons;
        tempRec.argentTot = ressourceTotal.argentTot + (tempRec.argentProd * matRatio) - tempRec.argentCons;
    }

    //transfer
    ressourceTotal = tempRec;
}


void Ville::tick()
{
    //1. calcul des ressources
    calculRessources();
    //calculRessourcesRapide(); l'un ou l'autre

    //2. avancement du temps


    //3. evenement aleatoire
}

void Ville::catastrophe()
{

}

bool Ville::isConstructible()
{
    return true;
}
