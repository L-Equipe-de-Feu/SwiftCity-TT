/*  date : 26 janvier 2023
    description : structure pour ressources
    Exemple de declaration : Ressources myressources
*/

#ifndef STRUCTRESSOURCES_H
#define STRUCTRESSOURCES_H

typedef struct {
    int energie = 0;
    int eau = 0;
    int bonheur = 0;
    int materiaux = 0;
    int argent = 0;
    int habitant = 0;
} Ressources;

typedef struct {
    //produit
    int energieProd = 0;
    int eauProd = 0;
    int bonheurProd = 0;
    int materiauxProd = 0;
    int argentProd = 0;
    int habitantProd = 0;
    //consommé
    int energieCons = 0;
    int eauCons = 0;
    int bonheurCons = 0;
    int materiauxCons = 0;
    int argentCons = 0;
    int habitantCons = 0;
} RessourcesVille;


#endif
