#include "Tremblement.h"
#include <random>
#include "randomeng.h"

//random
//extern std::random_device r;
//extern std::default_random_engine gen(r());

Flocon::Flocon() {}

Flocon::Flocon(int tailleX, int tailleY) {

	tX = tailleX;
	tY = tailleY;
	x = randEng::gen() % tX;
	y = randEng::gen() % tY;
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
	for (int i = 0; i < tX; i++) {
		for (int j = 0; j < tY;j++) {
			carte[i][j] = false;
		}
	}
	x = randEng::gen() % tX;
	y = randEng::gen() % tY;
}

bool Flocon::walk() {
	//genere une direction aleatoire
	int dx = (randEng::gen() % 3) - 1;
	int dy = (randEng::gen() % 3) - 1;

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

		switch (randEng::gen() % 4) {
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

void Flocon::getCopieTableau(bool** copie) {
	for (int i = 0; i < tX; i++) {
		for (int j = 0; j < tY; j++) {
			copie[i][j] = carte[i][j];
		}
	}
}

void Flocon::walkFor(int n) {
	for (int i = 0; i < n; i++) {
		walk();
	}
}