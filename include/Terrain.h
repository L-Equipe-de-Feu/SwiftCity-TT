#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain {
    protected :
        bool construire;
    public :
        /** @brief permet de set un terrain est constructible ou pas*/
        virtual void setPeuConstruire(bool c)=0;

        virtual void afficher() = 0;
        virtual char get_char() = 0;
};

#endif