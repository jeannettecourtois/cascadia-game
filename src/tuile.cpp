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



bool contientAnimal(const std::string& animal) {
    for (unsigned int i = 0; i < nbAnimaux; ++i) {
        if (listeAnimaux[i] == animal) {
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
