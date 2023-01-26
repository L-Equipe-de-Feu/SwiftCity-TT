#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain {
    protected :
        bool construire;
    public :
        virtual void setPeuConstruire(bool c)=0;
};

#endif