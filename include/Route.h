#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include "Batiment.h"

class Route : public Batiment {
    private :
        
    public : 
        Route() { isRoute = true; }
        ~Route() {}

        void afficher() {

        }
        char get_char() {
            return '-';
        }
};

#endif