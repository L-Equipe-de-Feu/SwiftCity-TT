
#ifndef CATASTROPHES_H
#define CATASTROPHES_H

#define NBCATA		2

#include "sinkhole.h"
#include "Tremblement.h"
#include "randomeng.h"



class Catastrophes {
public:
	Catastrophes();
	Catastrophes(int TailleX, int TailleY);
	~Catastrophes();

	void reinit();
	template <size_t rows, size_t cols>
	void destruction(int Pv, bool(&copie)[rows][cols], int choix);

private:
	Flocon* flocon = new Flocon();
	Sinkhole* sinkhole = new Sinkhole();
};



#endif // !CATASTROPHES_H

