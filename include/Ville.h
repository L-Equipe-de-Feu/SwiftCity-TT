#ifndef VILLE_H
#define VILLE_H

#include <iostream>
#include "Batiment.h"
#include "terrain.h"
#include "structRessources.h"
#define taille 20

class Ville
{
private:
    Ressources ressourceTotal;
    Terrain* gridT[taille][taille];
    Batiment* gridB[taille][taille];
    int temps;

    void calculEnergie();
    void calculProd();
    void calculEau();
    void calculBonheur();
    void calculMaterieux();
    void calculArgent();
    void calculHabitant();
    void catastrophe();
    bool isConstructible();
    void init();
public:
    Ville();
    ~Ville();

    void construireBatiment(int x, int y, Batiment* b);
    void construireRoute(int x, int y, Batiment* b);
    void detruire(int x, int y);

    void affiche(Curseur* curseur);
};

Ville::Ville(){
    init();
}

void Ville::init(){
    for(int i=0; i<taille; i++){
		for(int e=0; e<taille; e++){
            gridB[i][e] = new Batiment;
        }
    }
}

Ville::~Ville(){
    delete[] gridB;
    delete[] gridT;
}

void Ville::construireBatiment(int x, int y, Batiment* b){
    //if(gridB[x+1][y]==Class(Route) || gridB[x-1][y]==Class(Route) || gridB[x][y+1]==Class(Route) || gridB[x][y-1]==Class(Route) && gridT[x][y]==constructible){
        gridB[x][y] = b;
    //}
}

void Ville::construireRoute(int x, int y, Batiment* b){
    gridB[x][y] = b;
}

void Ville::affiche(Curseur* curseur){
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    //rajouter les calcule de monayS ici pour les affichage
    cout << "Votre argent : " << endl;
    cout << "Votre income : " << endl;
    cout << "Votre Population : " << endl;

	cout << "|-------------------------------------------------------------------------------|" << endl;
	for(int i=0; i<taille; i++){
		for(int e=0; e<taille; e++){
			if(i == curseur->get_Coordonnee().x && e == curseur->get_Coordonnee().y){
				cout << "| " << "." << " ";
			}else{
                cout << "| " << gridB[i][e]->get_char() << " ";
            }
		}
		cout << "|" << endl;
		cout << "|-------------------------------------------------------------------------------|" << endl;
	}
}

#endif