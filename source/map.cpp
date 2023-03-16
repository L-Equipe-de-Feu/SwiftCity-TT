#include "map.h"


terrainGenerator::terrainGenerator(int x, int y)
{
	m = x;
	n = y;

    //cree un tableau 2d de terrain
    terrainGenere = new Terrain * *[m];
    for (int i = 0; i < m; ++i) {
        terrainGenere[i] = new Terrain * [n];

        for (int j = 0; j < n; ++j) {
            terrainGenere[i][j] = new Terrain();
        }
    }
}

terrainGenerator::~terrainGenerator() 
{
    delete[] terrainGenere;
}

/// <summary>
/// Crée une map random
/// </summary>
/// <param name="x"></param>
void terrainGenerator::randomized_map(int x)
{
    //cree un tableau 2d de gazon
    delete[] terrainGenere;
    terrainGenere = new Terrain * *[m];
    for (int i = 0; i < m; ++i) {
        terrainGenere[i] = new Terrain * [n];

        for (int j = 0; j < n; ++j) {
            terrainGenere[i][j] = new Gazon();
        }
    }

//1: choisis les points a relier
//1.1: choisir 2 coter pour commencer et finir

//2: appliquer dijsktra de point a point

}

void terrainGenerator::afficher() 
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << terrainGenere[i][j]->get_char() << " ";
        }
        std::cout << std::endl;
    }
}