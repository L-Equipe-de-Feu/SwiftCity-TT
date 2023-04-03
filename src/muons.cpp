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
