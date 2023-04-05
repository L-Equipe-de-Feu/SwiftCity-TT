#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include "Batiment.h"

class Route : public Batiment {
    private :
        bool voisin[4] = { 0,0,0,0 };
    public : 
        Route() { isRoute = true; }
        Route(bool up, bool left, bool right, bool down) {
            isRoute = true;
            voisin[0] = up;
            voisin[1] = left;
            voisin[2] = right;
            voisin[3] = down;
        }

        ~Route() {}

        void afficher() {

        }
        char get_char() {
            return '-';
        }

        std::string get_string() {
            return std::to_string(voisin[0]) + std::to_string(voisin[1]) + std::to_string(voisin[2]) + std::to_string(voisin[3]);
        }

        void change_voisin(bool up, bool left, bool right, bool down){
            voisin[0] = up;
            voisin[1] = left;
            voisin[2] = right;
            voisin[3] = down;
        }

        std::tuple<bool, bool, bool, bool> get_voisin() {
            return std::make_tuple(voisin[0], voisin[1], voisin[2], voisin[3]);
        }
};

#endif