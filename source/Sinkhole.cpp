#include "sinkhole.h"
#include <random>
#include "randomeng.h"

//random
//extern std::random_device r;
//extern std::default_random_engine gen(r());

Sinkhole::Sinkhole() {}

Sinkhole::Sinkhole(int tailleX, int tailleY) {
	tX = tailleX;
	tY = tailleY;
}

Sinkhole::~Sinkhole() {
}

void Sinkhole::reinit() {
	for (int i = 0; i < tY; tY++) {
		for (int j = 0; j < tX; j++) {
			carte[i][j] = false;
		}
	}
}

//e = 1 totalement random)
void Sinkhole::random(int r, bool e) {
	if (e) fillCircle(randEng::gen() % tX, randEng::gen() % tY, randEng::gen() % (tX / 2) + 0.5);
	else fillCircle(randEng::gen() % tX, randEng::gen() % tY, r);

}

void Sinkhole::fillCircle(int x, int y, double r) {
	Point center;
	center.x = x;
	center.y = y;
	for (int i = 0; i < tY; i++) {
		for (int j = 0; j < tX; j++) {
			Point tile;
			tile.x = j;
			tile.y = i;
			carte[i][j] = insideCircle(center, tile, r);
		}
	}
}

bool Sinkhole::insideCircle(Point center, Point tile, double radius) {
	float dx = center.x - tile.x, dy = center.y - tile.y;
	float distance = sqrt(dx * dx + dy * dy);
	return distance <= radius;
}

template <size_t rows, size_t cols>
void Sinkhole::getCopieTableau(bool(&copie)[rows][cols]) {
	for (int i = 0; i < tY; i++) {
		for (int j = 0; j < tX; j++) {
			copie[i][j] = carte[i][j];
		}
	}
}