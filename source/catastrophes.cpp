#include "catastrophes.h"
#include <random>
#include "randomeng.h"

//extern std::random_device r;
//extern std::default_random_engine gen(r());
std::uniform_int_distribution<int> choice(0, 1);


Catastrophes::Catastrophes() {
}

Catastrophes::Catastrophes(int TailleX, int TailleY) {
	delete flocon;
	delete sinkhole;
	Flocon* flocon1 = new Flocon(TailleX, TailleY);
	Sinkhole* sinkhole1 = new Sinkhole(TailleX, TailleY);
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
	int choix = choice(randEng::gen());
	switch (choix) {
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