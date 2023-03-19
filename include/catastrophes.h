
#ifndef CATASTROPHES_H
#define CATASTROPHES_H

#include "sinkhole.h"
#include "Tremblement.h"
#include <random>



class Catastrophes {
public:
	Catastrophes();
	Catastrophes(int TailleX, int TailleY);
	~Catastrophes();

	void reinit();
	template <size_t rows, size_t cols>
	void destruction(int Pv, bool(&copie)[rows][cols]);

private:
	Flocon* flocon = new Flocon();
	Sinkhole* sinkhole = new Sinkhole();
};



#endif // !CATASTROPHES_H

