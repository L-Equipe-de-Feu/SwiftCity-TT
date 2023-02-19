#ifndef EAU_H
#define EAU_H

#include <iostream>
#include <terrain.h>

class Eau : public Terrain {
    public :
        Eau(bool c = false);
        ~Eau();
        /** @brief permet de set un terrain est constructible ou pas*/
        void setPeuConstruire(bool c);  

        void afficher() {}

        char get_char()
        {
            return ',';
        }
};
#endif