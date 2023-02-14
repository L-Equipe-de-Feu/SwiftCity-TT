#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>

class Route : public Batiment {
    private :

    public : 
        Route() {}
        ~Route() {}

        void afficher() {

        }
        char get_char() {
            return 'R';
        }
};

#endif