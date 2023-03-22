#include "catastrophes.h"

//extern std::random_device r;
//extern std::default_random_engine gen(r());
std::uniform_int_distribution<int> choice(0, 1);


Catastrophes::Catastrophes(int TailleX, int TailleY) {
	flocon = new Flocon(TailleX, TailleY);
	sinkhole = new Sinkhole(TailleX, TailleY);
}

Catastrophes::~Catastrophes() {
	delete flocon;
	delete sinkhole;
}

void Catastrophes::reinit() {
	flocon->reinit();
	sinkhole->reinit();
}


void Catastrophes::destruction(int Pv, bool** copie) {
	
	int choix = randEng::gen() % NBCATA;
	switch (choix) {
	case 0:
		sinkhole->random(Pv, 0);
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