/*
* Utilise "diffusion-limited aggregation" pour genere un tableau de bool qui contient les emplacemeent frapper
*/



#ifndef FLOCON_H
#define FLOCON_H



#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

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
	template <size_t rows, size_t cols>
	void getCopieTableau(bool(&copie)[rows][cols]);
	void walkFor(int n);



};

//random
random_device r;
default_random_engine generator(r());
uniform_int_distribution<int> coor(-1, 1), st(0, 4), start(0,1000);

Flocon::Flocon() {}

Flocon::Flocon(int tailleX, int tailleY) {

	tX = tailleX;
	tY = tailleY;
	x = start(generator)%tX;
	y = start(generator)%tY;
	carte[x][y] = true;
	minX = x;
	maxX = x;
	minY = y;
	maxY = y;
	domainMinX = std::max((minX - domain), 0);
	domainMaxX = std::min((maxX + domain), (tX));
	domainMinY = std::max((minY - domain), 0);
	domainMaxY = std::min((maxY + domain), (tY));
}

Flocon::~Flocon() {
}


void Flocon::reinit() {
	for (int i = 0; i < tY; i++) {
		for (int j = 0; j < tX;j++) {
			carte[i][j] = false;
		}
	}
	x = start(generator) % tX;
	y = start(generator) % tY;
}

bool Flocon::walk() {
	//genere une direction aleatoire
	int dx = coor(generator);
	int dy = coor(generator);

	//trouve la prochaine case sur laquel le curseur va se deplacer
	int newX = x + dx;
	int newY = y + dy;

	//regarde si le curseur est sorti du domain et le remet a l'oppose
	if (newX < domainMinX) newX = domainMaxX;
	if (newX > domainMaxX) newX = domainMinX;
	if (newY < domainMinY) newY = domainMaxY;
	if (newY > domainMaxY) newY = domainMinY;

	// regarde si le prochain pixel nm est deja placer
	if (carte[newX][newY] == true) {

		//Si le prochain est vrai mais celui present a vrai pour "grossir" le crystal
		carte[x][y] = true;

		//change les dimension
		if (x < minX) minX = x;
		if (x > maxX) maxX = x;
		if (y < minY) minY = y;
		if (y > maxY) maxY = y;

		//change le domaine dans lequel le curseur peut naviguer
		domainMinX = std::max((minX - domain), 0);
		domainMaxX = std::min((maxX + domain), (tX - 1));
		domainMinY = std::max((minY - domain), 0);
		domainMaxY = std::min((maxY + domain), (tY - 1));

		switch (st(generator)) {
		case 0:
			x = domainMinX;
			y = domainMinY;
			break;

		case 1:
			x = domainMinX;
			y = domainMaxY;
			break;

		case 2:
			x = domainMaxX;
			y = domainMaxY;
			break;

		case 3:
			x = domainMaxX;
			y = domainMinY;
			break;

		default:
			x = domainMinX;
			y = domainMinY;
			break;
		}

		return 1;
	}
	else {
		x = newX;
		y = newY;
		return 0;
	}
}

template <size_t rows, size_t cols>
void Flocon::getCopieTableau(bool(&copie)[rows][cols]) {
	for (int i = 0; i < tY; i++) {
		for (int j = 0; j < tX; j++) {
			copie[i][j] = carte[i][j];
		}
	}
}

void Flocon::walkFor(int n) {
	for (int i = 0; i < n; i++) {
		walk();
	}
}


#endif