
#ifndef CATASTROPHES_H
#define CATASTROPHES_H

#define NBCATA		2

#include "sinkhole.h"
#include "Tremblement.h"
#include "randomeng.h"



class Catastrophes {
public:
	Catastrophes(int TailleX, int TailleY);
	~Catastrophes();
	void reinit();	
	void destruction(int Pv, bool** copie);

private:
	Flocon* flocon;
	Sinkhole* sinkhole;
};



#endif // !CATASTROPHES_H

