#ifndef GAZON_H
#define GAZON_H

#include <iostream>
#include <terrain.h>

class Gazon : public Terrain {
    public :
        Gazon() { construire = true; }
        ~Gazon() {}
         /** @brief permet de set un terrain est constructible ou pas*/
        virtual bool getPeuConstruire() 
        {
            return construire;
        }

        virtual void afficher() {}

        virtual char get_char() 
        {
            return '#';
        }
};
#endif