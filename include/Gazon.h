#ifndef GAZON_H
#define GAZON_H

#include <iostream>
#include <terrain.h>

class Gazon : public Terrain {
    public :
        Gazon(bool c = true);
        ~Gazon();
        void setPeuConstruire(bool c);  
};
#endif