#ifndef EAU_H
#define EAU_H

#include <iostream>
#include <terrain.h>

class Eau : public Terrain {
    public :
        Eau(bool c = false);
        ~Eau();
        void setPeuConstruire(bool c);  
};
#endif