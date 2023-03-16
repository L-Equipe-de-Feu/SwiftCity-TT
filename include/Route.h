#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>

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