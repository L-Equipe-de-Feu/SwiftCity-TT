/*
    Date : 26 janvier 2023
    Description : Classe pour les pompiers
*/

#ifndef POMPIER_H
#define POMPIER_H

#include "Service.h"

class Pompier : public Service
{
private:
    /* data */
public:
    Pompier();
    ~Pompier();
};

Pompier::Pompier(){}

Pompier::~Pompier(){}


#endif