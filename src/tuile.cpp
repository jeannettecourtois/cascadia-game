#include "tuile.h"
#include <random>

Tuile::~Tuile() {
    for(unsigned int i = 0; i<nbAnimaux; ++i){
        delete listeAnimaux[i];
    }
    delete[] listeAnimaux;
    for(unsigned int i = 0; i<nbHabitat; ++i){
        delete listeHabitat[i];
    }
    delete[] listeHabitat;
}

bool Tuile::contientAnimal(const Animal& a) const {
    for (unsigned int i = 0; i < nbAnimaux; ++i) {
        if (*listeAnimaux[i] == a) {
            return true;
        }
    }
    return false;
}

/*
Keystone::Keystone() : Tuile() {}

Keystone::~Keystone() {}

// Donne un jeton keyStone � joueur si pose animal sur bonne case keyStone
void Keystone::associationJeton() const {}*/
