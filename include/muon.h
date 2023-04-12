#ifndef MUON_H
#define MUON_H

#include <Arduino.h>

class Muon
{
private:
    long time[100];
    long lastTime = 0;
    int position = 0;
    bool plein = false;

public:
    Muon();
    float calculMoyenne(long t);
    long get_lastTime();
};

#endif

/*
#ifndef MUONS_H_
#define MUONS_H_

float Detection[30];
float MOYENNE = 0;

int lecture();
float moyenne();

#endif
*/