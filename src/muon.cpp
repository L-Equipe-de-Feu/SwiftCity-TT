#include <muon.h>

Muon::Muon()
{
    for(int i = 0; i < 100; i++)
    {
        time[i] = 0;
    }
}

float Muon::calculMoyenne(long currentTime)
{
    float moyenne = 0;

    if(position == 99)
        plein = true;

    time[position] = currentTime - lastTime;

    if(position == 99)
        position = 0;
    else
        position++;

    for(int i = 0; i < 100; i++)
    {
        moyenne += time[i];
    }

    if(plein)
        moyenne /= 100;
    else
        moyenne /= position;

    lastTime = currentTime;

    return moyenne;     
}

long Muon::get_lastTime()
{
    return lastTime;
}

/*
#include <muons.h>

int lecture()
{
    int position = 0;
    if (position == 30)
    {
        position = 0;
    }
    
    // Mettre l'acisition de données ici au lieu de donnée
    float donnee = 30;
    float referrenceDeDetection = 20;

    if (donnee > referrenceDeDetection)
    {
        Detection[position] = donnee;
        position = position + 1;
    }
}

float moyenne()
{
    float temp = 0;

    for (int x = 0; x < 30; x++)
    {
        temp = temp + Detection[x];
    }

    MOYENNE = temp;

    return MOYENNE;
}
*/
