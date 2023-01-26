/*
    Date : 26 janvier 2023 (creation)
    Description : Classe pour les bureaux
*/

#ifndef BUREAU_H
#define BUREAU_H

#include "Commercial.h"

class Bureau : public Commercial {
private:
    /* data */
public:
    Bureau();
    ~Bureau();
};

Bureau::Bureau(){}

Bureau::~Bureau(){}



#endif