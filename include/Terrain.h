#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain {
    protected :
        bool construire = true;
    public :
        Terrain() {}
        ~Terrain() {}
        /** @brief permet de set un terrain est constructible ou pas*/
        virtual bool getPeuConstruire() { return construire; }

        virtual void afficher() { }
        virtual char get_char() { return 'T'; }
};

#endif