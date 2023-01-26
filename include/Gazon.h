#ifndef GAZON_H
#define GAZON_H

#include <iostream>
#include <terrain.h>

class Gazon : public Terrain {
    public :
        Gazon(bool c = true);
        ~Gazon();
         /** @brief permet de set un terrain est constructible ou pas*/
        void setPeuConstruire(bool c);  
};
#endif