#ifndef EAU_H
#define EAU_H

#include <iostream>
#include <terrain.h>

class Eau : public Terrain {
    public :
        Eau() { construire = false; }
        ~Eau() {}
        /** @brief permet de set un terrain est constructible ou pas*/
        bool getPeuConstruire() 
        {
            return construire;
        }

        void afficher() {}

        char get_char()
        {
            return ',';
        }
};
#endif