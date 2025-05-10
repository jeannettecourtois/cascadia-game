#include "ControleurGeneral.h"

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
      tuiles(nullptr), cartesRegles(nullptr), tuilesDepart(nullptr) {}

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