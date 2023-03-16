#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <math.h>
#include <string.h>
#include <Eau.h>
#include <Gazon.h>

using namespace std;

class terrainGenerator
{
private:
	int m = 64;
	int n = 64;
	Terrain*** terrainGenere;

public:
	terrainGenerator(int x, int y);
	~terrainGenerator();

	void randomized_map(int x);
	void afficher();
};


#endif
