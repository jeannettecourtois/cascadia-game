#include "tuile.h"

Tuile::Tuile():nbAnimaux(0),nbHabitat(0),listeAnimaux(nullptr),listeHabitat(nullptr){}

Tuile::~Tuile() {
    if (listeAnimaux) {
        for (int i = 0; i < nbAnimaux; ++i)
            delete listeAnimaux[i];
        delete[] listeAnimaux;
    }

    if (listeHabitat) {
        for (int i = 0; i < nbHabitat; ++i)
            delete listeHabitat[i];
        delete[] listeHabitat;
    }
}

Keystone::Keystone() : Tuile() {}

Keystone::~Keystone() {}

void Keystone::AssociationJeton() const {}
