

#ifndef SINKHOLE_H
#define SINKHOLE_H

#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;


random_device r;
default_random_engine gen(r());
uniform_int_distribution<int> dsit1000(0,1000);

struct Point
{
	int x = 0;
	int y = 0;

};

class Sinkhole
{
private:
	#define TailleMax 200
	int tX = 1;
	int tY = 1;
	bool carte[TailleMax][TailleMax]{ {} };
public:
	Sinkhole();
	Sinkhole(int tailleX, int tailleY);
	~Sinkhole();

	void reinit();
	void random(int r = 0, bool e = 1);
	void fillCircle(int x,int y, double r);
	bool insideCircle(Point center, Point tile, double radius);
	template <size_t rows, size_t cols>
	void getCopieTableau(bool (&copie)[rows][cols]);


};

Sinkhole::Sinkhole(){}

Sinkhole::Sinkhole(int tailleX, int tailleY) {
	tX = tailleX;
	tY = tailleY;
}

Sinkhole::~Sinkhole(){
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
	if (e) fillCircle(dsit1000(gen) % tX, dsit1000(gen) % tY, dsit1000(gen) % (tX / 2) + 0.5);
	else fillCircle(dsit1000(gen) % tX, dsit1000(gen) % tY, r);
	
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
void Sinkhole::getCopieTableau(bool (&copie)[rows][cols]) {
	for (int i = 0; i < tY; i++) {
		for (int j = 0; j < tX; j++) {
			copie[i][j] = carte[i][j];
		}
	}
}



#endif // !SINKHOLE_H
