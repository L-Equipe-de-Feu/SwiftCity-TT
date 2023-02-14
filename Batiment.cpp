#include "Batiment.h"


Batiment::Batiment() {
    ressources.energie = 0;
    ressources.eau = 0;
    ressources.bonheur = 0;
    ressources.materiaux = 0;
    ressources.argent = 0;
    ressources.habitant = 0;
}

Batiment::~Batiment() {}

void Batiment::afficher() {

}

char Batiment::get_char() {
    return ' ';
}

void Batiment::SetRessources(Ressources NRessources) {
    ressources = NRessources;
}

Ressources Batiment::GetRessources() {
    return ressources;
}

