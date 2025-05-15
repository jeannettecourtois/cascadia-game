#pragma once
#include "Partie.h"
#include "Joueur.h"

class TuileDepart {
public:
    TuilePlacee* tuiles[3];
    TuileDepart();
    ~TuileDepart();
};


class ControleurGeneral { // Singleton
private:
    int nbTuiles;
    int nbCartesRegles;
    int nbTuilesDepart;
    Tuile** tuiles;
    CarteMarquageFaune** cartesRegles;
    TuileDepart** tuilesDepart;
    ControleurGeneral();
    ~ControleurGeneral();
public:
    ControleurGeneral(const ControleurGeneral&) = delete;
    ControleurGeneral& operator=(const ControleurGeneral&) = delete;
    static ControleurGeneral& GetInstance() {
        static ControleurGeneral instance;
        return instance;
    }
};