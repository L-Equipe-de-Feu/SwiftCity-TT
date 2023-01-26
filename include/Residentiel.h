/*
    Date : 26 janvier 2023
    Description : Classe pour les residence
*/

#ifndef RESIDENTIEL_H
#define RESIDENTIEL_H

#include "Batiment.h"

class Residentiel : public Batiment
{
private:
    /* data */
public:
    Residentiel();
    ~Residentiel();
};

Residentiel::Residentiel(){}

Residentiel::~Residentiel(){}

#endif