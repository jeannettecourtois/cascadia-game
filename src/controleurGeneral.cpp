#include "controleurGeneral.h"

using namespace std;

TuileDepart::TuileDepart() {
    for (int i = 0; i < 3; ++i) {
        tuiles[i] = nullptr;
    }
}

TuileDepart::~TuileDepart() {
    for (int i = 0; i < 3; ++i) {
        delete tuiles[i];
    }
}



ControleurGeneral::ControleurGeneral() : nbTuiles(0), nbCartesRegles(0), nbTuilesDepart(0),
      tuiles(nullptr), cartesRegles(nullptr), tuilesDepart(nullptr) {
    srand(std::time(nullptr));
}

ControleurGeneral::~ControleurGeneral() {
    if (tuiles) {
        for (int i = 0; i < nbTuiles; ++i)
            delete tuiles[i];
        delete[] tuiles;
    }

    if (cartesRegles) {
        for (int i = 0; i < nbCartesRegles; ++i)
            delete cartesRegles[i];
        delete[] cartesRegles;
    }

    if (tuilesDepart) {
        for (int i = 0; i < nbTuilesDepart; ++i)
            delete tuilesDepart[i];
        delete[] tuilesDepart;
    }
}


CarteMarquageFaune* ControleurGeneral::getCarteRegleAleatoire() {
    if (nbCartesRegles == 0 || cartesRegles == nullptr) {
        throw runtime_error("Aucune carte règle disponible.");
    }
    int index = rand() % nbCartesRegles; // Choisir un index aléatoire parmis les cartes
    return cartesRegles[index];
}

TuileDepart* ControleurGeneral::getTuilesDepartAleatoires() {
    if (nbTuilesDepart == 0 || tuilesDepart == nullptr) {
        throw std::runtime_error("Aucune tuile de départ disponible.");
    }
    TuileDepart* set = new TuileDepart();
    for (int i = 0; i < 3; ++i) {
        int index = rand() % nbTuilesDepart;
        set->tuiles[i] = new TuilePlacee(*tuilesDepart[index]->tuiles[i]);
    }
    return set; // retourne un tableau de 3 tuiles
}
