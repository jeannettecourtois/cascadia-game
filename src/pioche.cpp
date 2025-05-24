#include "pioche.h"
#include "enum.h"

SacTuile::SacTuile() {}

SacTuile::~SacTuile() {}

Tuile* SacTuile::Piocher() {return nullptr;} //à changer, juste pour compiler coder

void SacTuile::mettreDansLeSac(Tuile&) {}


SacJeton::SacJeton() {}

SacJeton::~SacJeton() {}

animal* SacJeton::Piocher() {return nullptr;} //à changer, juste pour compiler coder

void SacJeton::mettreDansLeSac(animal) {}


Pioche::Pioche() {
    for (int i = 0; i < 4; ++i) {
        tuiles[i] = nullptr;
        jetons[i] = animalOuPas::Vide;
    }
    idTuileChoisis = -1;
    sacDeTuiles = new SacTuile();
    sacDeJetons = new SacJeton();
}

Pioche::~Pioche() {
    for (int i = 0; i < 4; ++i) {
        delete tuiles[i]; 
    }
    delete sacDeTuiles;
    delete sacDeJetons;
}

void Pioche::preparerPioche() {
    // Préparer la pioche de tuiles et de jetons
    for (int i = 0; i < 4; ++i) {
        tuiles[i] = sacDeTuiles->Piocher();
        jetons[i] = static_cast<animalOuPas>(*(sacDeJetons->Piocher())); //Conversion animalOuPas vers animal
    }
}

void Pioche::selectionnerTuile() {
    // Sélectionner une tuile parmi celles disponibles
    idTuileChoisis = rand() % 4;
}

void Pioche::selectionnerJeton() {
    // Sélectionner un jeton parmi ceux disponibles
    int idJetonChoisis = rand() % 4;
    animalOuPas jetonChoisi = jetons[idJetonChoisis];
}