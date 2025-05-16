#include "pioche.h"
#include "enum.h"

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

void Pioche::PreparerPioche() {
    // Préparer la pioche de tuiles et de jetons
    for (int i = 0; i < 4; ++i) {
        tuiles[i] = sacDeTuiles->Piocher();
        jetons[i] = sacDeJetons->Piocher();
    }
}

void Pioche::SelectionnerTuile() {
    // Sélectionner une tuile parmi celles disponibles
    idTuileChoisis = rand() % 4;
}

void Pioche::SelectionnerJeton() {
    // Sélectionner un jeton parmi ceux disponibles
    int idJetonChoisis = rand() % 4;
    animalOuPas jetonChoisi = jetons[idJetonChoisis];
}