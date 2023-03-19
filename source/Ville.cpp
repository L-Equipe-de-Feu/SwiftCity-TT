#include "Ville.h"

using namespace std;

Ville::Ville() {
    init();  

    ticktimelast = time(0);
}

void Ville::init() {
    genererTerrain(rand());    
    for (int i = 0; i < TAILLEX; i++) {
        for (int e = 0; e < TAILLEY; e++) {
            gridB[i][e] = nullptr;
            //gridT[i][e] = new Gazon();
        }
    }

    //starting ressources
    ressourceTotal.argentTot = 10000;

    calculRessourcesIndependant();
}

Ville::~Ville() {
    // TODO : crash a la fermeture, verifier pourquoi
    //delete[] gridB;
    //delete[] gridT;
}

bool Ville::construireBatiment(int x, int y, Batiment* b) {
    

    //1.verify index and ptr
    if (x < 0 || y < 0 || x >= TAILLEX || y >= TAILLEY) 
    {
        cout << "index erroné" << endl;
        return false;
    }
    if (b == nullptr)return false;

    //2.verify if spot ok
    //vide
    if (gridB[x][y] != nullptr)    {
        cout << "building deja a cette position" << endl;
        return false;
    }
    //terrain constructible
    if (!gridT[x][y]->getPeuConstruire()) 
    {
        cout << "ne peux pas construire a cette position" << endl;
        return false;
    }
    //route adjacente
    bool adj = false;
    if (x > 0) 
    {
        if (gridB[x - 1][y] != NULL)
        {
            adj = gridB[x - 1][y]->estRoute();
        }        
    }
    if (x < TAILLEX-1 && !adj)
    {
        if (gridB[x + 1][y] != NULL) 
        {
            adj = gridB[x + 1][y]->estRoute();
        }        
    }
    if (y > 0 && !adj)
    {
        if (gridB[x][y - 1] != NULL)
        {
            adj = gridB[x][y-1]->estRoute();
        }
    }
    if (y < TAILLEY-1 && !adj)
    { 
        if (gridB[x][y + 1] != NULL)
        {
            adj = gridB[x][y+1]->estRoute();
        }        
    }

    if (!adj) 
    {
        cout << "pas de route adjacente" << endl;
        return false;
    }

    //3.verify ressources
    //cout
    if (b->get_Couts() > ressourceTotal.argentTot)
    {
        cout << "t tro povre bruz" << endl;
        return false;
    }
    //eau
    if (b->GetRessources().eau < 0) 
    {
        if (ressourceTotal.eauCons-b->GetRessources().eau > ressourceTotal.eauProd)
        {
            cout << "mouille touer un peu" << endl;
            return false;
        }
    }
    //energie
    if (b->GetRessources().energie < 0)
    {
        if (ressourceTotal.energieCons - b->GetRessources().energie > ressourceTotal.energieProd)
        {
            cout << "t'as trip le breaker guy" << endl;
            return false;
        }
    }

    ressourceTotal.argentTot -= b->get_Couts();

    //4.ajouter batiment
    gridB[x][y] = b;   

    calculRessourcesIndependant();

    return true;
}

bool Ville::construireRoute(int x, int y, Batiment* b) {
    //1.verify index
    if (x < 0 || y < 0 || x >= TAILLEX || y >= TAILLEY)
    {
        cout << "index erroné" << endl;
        return false;
    }
    //2.verify if spot ok
    if (gridB[x][y] != nullptr) {
        cout << "building deja a cette position" << endl;
        return false;
    }

    //3.verify ressources
    if (b->get_Couts() > ressourceTotal.argentTot)
    {
        cout << "t tro povre bruz" << endl;
        return false;
    }

    ressourceTotal.argentTot -= b->get_Couts();
    
    gridB[x][y] = b;

    calculRessourcesIndependant();

    return true;
}

void Ville::affiche(Curseur* curseur) {
    //tick();
    //cout << endl << endl << endl << endl << endl << endl << endl << endl;
    //rajouter les calcules ici pour les affichage
    cout << "Votre argent : " << ressourceTotal.argentTot << endl;
    cout << "Votre income : " << ressourceTotal.argentIncome << endl;
    cout << "Votre Population : " << ressourceTotal.habitantTot << " / " << ressourceTotal.habitantMax << endl;
    cout << "Votre Energie : " << ressourceTotal.energieCons << "/" << ressourceTotal.energieProd << endl;
    cout << "Votre Eau : " << ressourceTotal.eauCons << "/" << ressourceTotal.eauProd << endl;
    cout << "Votre Bonheur : " << ressourceTotal.bonheurPour << "%" << endl;
    cout << "Vos Materiaux : " << ressourceTotal.materiauxTot << endl;

    cout << GT.time_to_str(3) << "\tVitesse : " << GT.vitesse_to_str() << endl;
    
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
                    cout << "| " << gridT[i][e]->get_char() << " ";
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

void Ville::accelerer()
{
    GT.accelerer();
}

void Ville::decelerer()
{
    GT.decelerer();
}

/// <summary>
/// generation aléatoire de la map de depart
/// </summary>
/// <param name="x">chiffre random venant du generateur de muons</param>
void Ville::genererTerrain(int x)
{
    random_device r;
    default_random_engine generator(r());
    uniform_int_distribution<int> range(0, 1000);

    bool map[TAILLEX][TAILLEY];
    for (int i = 0; i < TAILLEX; i++)
    {
        for (int j = 0; j < TAILLEY; j++)
        {
            map[i][j] = false;
        }
    }

    int depart;
    if (TAILLEY>TAILLEX)
    {
        depart = x % TAILLEY;
    }
    else
    {
        depart = x % TAILLEX;
    }

    int position = depart;
    int virage = 0;
    int equation = range(generator);
    if (equation % 2 == 0)
    {
        if (TAILLEX > TAILLEY)
        {
            position = floor(position * TAILLEY / TAILLEX);
        }
        map[0][position] = 1;
        for (int i = 1; i < TAILLEX; i++)
        {
            equation = range(generator);
            if (equation % 3 == 0)
            {
                map[i][position] = 1;
                if (position > 0 && virage != 1)
                {
                    map[i][position - 1] = 1;
                    position--;
                    virage = 2;
                }
            }
            else if (equation % 3 == 1)
            {
                map[i][position] = 1;
                virage = 0;
            }
            else if (equation % 3 == 2)
            {
                map[i][position] = 1;
                if (position < TAILLEY - 1 && virage != 2)
                {
                    map[i][position + 1] = 1;
                    position++;
                    virage = 1;
                }
            }
        }
    }
    else
    {
        if (TAILLEY > TAILLEX)
        {
            position = floor(position * TAILLEX / TAILLEY);
        }
        map[position][0] = 1;
        for (int j = 1; j < TAILLEY; j++)
        {
            equation = range(generator);
            if (equation % 3 == 0)
            {
                map[position][j] = 1;
                if (position > 0 && virage != 1)
                {
                    map[position - 1][j] = 1;
                    position--;
                    virage = 2;
                }
            }
            else if (equation % 3 == 1)
            {
                map[position][j] = 1;
                virage = 0;
            }
            else if (equation % 3 == 2)
            {
                map[position][j] = 1;
                if (position < TAILLEX - 1 && virage != 2)
                {
                    map[position + 1][j] = 1;
                    position++;
                    virage = 1;
                }
            }
        }
    }
    for (int p = 0; p < TAILLEX; p++)
    {
        for (int q = 0; q < TAILLEY; q++)
        {
            if (!map[p][q]) 
            {
                gridT[p][q] = new Gazon();
            }
            else 
            {
                gridT[p][q] = new Eau();
            }            
        }
    }
}

void Ville::detruire(int x, int y) 
{
    if (gridB[x][y] == nullptr)return;

    ressourceTotal.argentTot += gridB[x][y]->get_Refund();
    delete gridB[x][y];
    gridB[x][y] = nullptr;
}

/// <summary>
/// calcul toute les donnée
/// </summary>
void Ville::calculRessources()
{
    calculRessourcesIndependant();
    calculRessourcesDependant();
}


/// <summary>
/// update les ressources independantes
/// </summary>
void Ville::calculRessourcesIndependant() 
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
                    tempRec.energieCons -= temp;
                }

                //eau
                temp = gridB[i][j]->GetRessources().eau;
                if (temp > 0)
                {
                    tempRec.eauProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.eauCons -= temp;
                }

                //bonheur 
                temp = gridB[i][j]->GetRessources().bonheur;
                if (temp > 0)
                {
                    tempRec.bonheurProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.bonheurCons -= temp;
                }

                //habitant
                temp = gridB[i][j]->GetRessources().habitant;
                if (temp > 0)
                {
                    tempRec.habitantMax += temp;
                }
                else if (temp < 0)
                {
                    tempRec.habitantTrav -= temp;
                }

                //materiaux
                temp = gridB[i][j]->GetRessources().materiaux;
                if (temp > 0)
                {
                    tempRec.materiauxProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.materiauxCons -= temp;
                }

                //argent
                temp = gridB[i][j]->GetRessources().argent;
                if (temp > 0)
                {
                    tempRec.argentProd += temp;
                }
                else if (temp < 0)
                {
                    tempRec.argentCons -= temp;
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

    ressourceTotal.argentCons = tempRec.argentCons;
    ressourceTotal.argentProd = tempRec.argentProd;
    ressourceTotal.bonheurCons = tempRec.bonheurCons;
    ressourceTotal.bonheurProd = tempRec.bonheurProd;
    ressourceTotal.habitantTrav = tempRec.habitantTrav;
    ressourceTotal.habitantMax = tempRec.habitantMax;
    ressourceTotal.materiauxCons = tempRec.materiauxCons;
    ressourceTotal.materiauxProd = tempRec.materiauxProd;
    ressourceTotal.eauCons = tempRec.eauCons;
    ressourceTotal.eauProd = tempRec.eauProd;
    ressourceTotal.energieCons = tempRec.energieCons;
    ressourceTotal.energieProd = tempRec.energieProd;
    ressourceTotal.bonheurPour = tempRec.bonheurPour;
}

/// <summary>
/// update les ressources dependantes et calcul les gains
/// </summary>
void Ville::calculRessourcesDependant()
{
    RessourcesVille tempRec = ressourceTotal;
   
    //calcul habitants
    int gain = (tempRec.bonheurPour - 50) * PENTEHABS;
    tempRec.habitantTot = ressourceTotal.habitantTot + gain;

    if (tempRec.habitantTot <= 0)//game over???
    {
        tempRec.habitantTot = 0;
    }
    else if (tempRec.habitantTot >= tempRec.habitantMax)
    {
        tempRec.habitantTot = tempRec.habitantMax;
    }

    //calcul materiaux
    int manquant = 0;
    float travRatio = 0;
    if (tempRec.habitantTrav == 0)
    {
        travRatio = 0;
    }
    else
    {        
        travRatio = float(tempRec.habitantTot) / float(tempRec.habitantTrav);
        if (travRatio > 1.0)
        {
            travRatio = 1.0;
        }
        else if (travRatio < 0)
        {
            travRatio = 0;
        }
    }
    tempRec.materiauxTot = ressourceTotal.materiauxTot + (tempRec.materiauxProd * travRatio) - tempRec.materiauxCons;
    if (tempRec.materiauxTot < 0)
    {
        manquant = -tempRec.materiauxTot;
        tempRec.materiauxTot = 0;
    }

    //calcul argent
    if (manquant == 0)
    {
        tempRec.argentIncome = tempRec.argentProd - tempRec.argentCons;
        tempRec.argentTot = ressourceTotal.argentTot + tempRec.argentIncome;
    }
    else
    {
        float matRatio = (tempRec.materiauxCons - manquant) / tempRec.materiauxCons;
        tempRec.argentIncome = (tempRec.argentProd * matRatio) - tempRec.argentCons;
        tempRec.argentTot = ressourceTotal.argentTot + tempRec.argentIncome;
    }

    //transfer
    ressourceTotal = tempRec;
}

/// <summary>
/// 
/// </summary>
/// <param name="sec"></param>
void Ville::tick()
{
    ticktime = time(0);
    int elapsedSec = ticktime - ticktimelast;
    
    if(elapsedSec > 0)
    {
        //1. avancement du temps
        ticktimeH += GT.avancerTemps(elapsedSec);
        int elapsedH = int(ticktimeH - tickHtimelast) / 3600;
        //2. calcul des ressources    
        calculRessourcesIndependant();

        if (elapsedH > 0) 
        {
            for (int i = 0; i < elapsedH; i++)
            {
                calculRessourcesDependant();
            }
            tickHtimelast = ticktimeH;
        }

        //3. evenement aleatoire
        //TODO

        ticktimelast = ticktime;
    }    
}

void Ville::catastrophe()
{

}

bool Ville::isConstructible()
{
    return true;
}

void Ville::save()
{
    ofstream Save("save.txt", ios::out | ios::trunc); //efface le contenu du fichier s'il n'est pas vide
    RessourcesVille res;
    if (Save)
    {
        Save << TAILLEX << endl << TAILLEY << endl;
        Save << GT.time_to_str(4) << endl;
        Save << res.habitantTot << ";" << res.materiauxTot << ";" << res.argentTot << endl;
        for (int i = 0; i < TAILLEX; i++)
        {
            for (int j = 0; j < TAILLEY; j++)
            {
                Save << gridT[i][j] << ",";
            }
            Save << ";";
        }
        for (int i = 0; i < TAILLEX; i++)
        {
            for (int j = 0; j < TAILLEY; j++)
            {
                Save << gridB[i][j] << ",";
            }
            Save << ";";
        }
        Save.close();
    }
}
