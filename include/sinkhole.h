

#ifndef SINKHOLE_H
#define SINKHOLE_H

#include <cstdlib>
#include <random>


struct Point
{
	int x = 0;
	int y = 0;

};

class Sinkhole
{
private:
	#define TailleMax 200

	bool carte[TailleMax][TailleMax]{ {} };
public:
	int tX = 1;
	int tY = 1;
	Sinkhole(int tailleX, int tailleY);
	~Sinkhole();

	void reinit();
	void random(int r = 0, bool e = 1);
	void fillCircle(int x,int y, double r);
	bool insideCircle(Point center, Point tile, double radius);
	void getCopieTableau(bool** copie);


};





#endif // !SINKHOLE_H
