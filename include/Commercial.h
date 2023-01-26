/*
    Date : 26 janvier 2023
    Description : Structure pour les batiments Commercial
*/

#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Batiment.h"

class Commercial : public Batiment {
private:
    /* data */
public:
    Commercial();
    ~Commercial();
};

Commercial::Commercial(){}

Commercial::~Commercial(){}

#endif