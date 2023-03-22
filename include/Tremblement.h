/*
* Utilise "diffusion-limited aggregation" pour genere un tableau de bool qui contient les emplacemeent frapper
*/



#ifndef FLOCON_H
#define FLOCON_H


#include <random>
#include <algorithm>



class Flocon
{

private:
	#define TailleMAX 200
	int x = 0;
	int y = 0;
	int tX = 1;
	int tY = 1;

	int maxX = 0;
	int minX = 0;
	int maxY = 0;
	int minY = 0;

	int domain = 5;

	int domainMaxX = 0;
	int domainMinX = 0;
	int domainMaxY = 0;
	int domainMinY = 0;

	
	bool carte[TailleMAX][TailleMAX]{ {} };

	bool flag = false;

	


public:
	Flocon();
	Flocon(int tailleX, int tailleY);
	~Flocon();

	void reinit();
	bool walk();
	void getCopieTableau(bool** copie);
	void walkFor(int n);



};


#endif