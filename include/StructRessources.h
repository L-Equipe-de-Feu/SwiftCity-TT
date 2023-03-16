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
    int habitant = 0;
    int materiaux = 0;
    int argent = 0;  
} Ressources;

typedef struct {
    //energie
    int energieProd = 0;
    int energieCons = 0;
    //eau
    int eauProd = 0;
    int eauCons = 0;
    //bonheur
    float bonheurCons = 0; //bonheur necessaire (total de perte par les usine) 
    float bonheurProd = 3; //bonheur total (total de production de bonheur par culture)
    float bonheurPour = 0;//bonheur en pourcentage
    //habitants 
    int habitantTrav = 0; //nombre d'habitant necessaire pour la production optimale
    int habitantTot = 0; //habitant present dans la ville
    int habitantMax = 0; //nombre d'habitants maximum (depend du residentiel)
    //materiaux
    int materiauxCons = 0;
    int materiauxProd = 0;
    int materiauxTot = 0;
    //argent
    int argentTot = 0;
    int argentCons = 0;
    int argentProd = 0;
    int argentIncome = 0;
} RessourcesVille;


#endif
