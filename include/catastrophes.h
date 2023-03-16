
#ifndef CATASTROPHES_H
#define CATASTROPHES_H

#include "sinkhole.h"
#include "Tremblement.h"




class Catastrophes {
public:
	Catastrophes();
	Catastrophes(int TailleX, int TailleY);
	~Catastrophes();

	void reinit();
	template <size_t rows, size_t cols>
	void destruction(int Pv, bool(&copie)[rows][cols]);

private:
	uniform_int_distribution<int>* choice;
	Flocon* flocon;
	Sinkhole* sinkhole;
};


Catastrophes::Catastrophes() {
}

Catastrophes::Catastrophes(int TailleX, int TailleY) {
	Flocon* flocon1 = new Flocon(TailleX, TailleY);
	Sinkhole* sinkhole1 = new Sinkhole(TailleX, TailleY);
	choice = new uniform_int_distribution<int>(0, 1);
	flocon = flocon1;
	sinkhole = sinkhole1;
}

Catastrophes::~Catastrophes() {
	delete flocon;
	delete sinkhole;
}

void Catastrophes::reinit() {
	flocon->reinit();
	sinkhole->reinit();
}

template <size_t rows, size_t cols>
void Catastrophes::destruction(int Pv, bool(&copie)[rows][cols]) {
	switch ((*choice)(gen)) {
	case 0:
		sinkhole->random(Pv, 1);
		sinkhole->getCopieTableau(copie);
		sinkhole->reinit();
		break;

	case 1:
		flocon->walkFor(Pv * 1000);
		flocon->getCopieTableau(copie);
		flocon->reinit();
		break;
	}
}

#endif // !CATASTROPHES_H

