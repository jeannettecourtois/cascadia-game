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


/*
Keystone::Keystone() : Tuile() {}

Keystone::~Keystone() {}

// Donne un jeton keyStone � joueur si pose animal sur bonne case keyStone
void Keystone::associationJeton() const {}*/
