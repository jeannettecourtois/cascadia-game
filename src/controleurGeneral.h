#pragma once
#include <string>
#include "partie.h"
#include "joueur.h"
#include "carteMarquageFaune.h"

class TuileDepart {
public:
    TuilePlacee* tuiles[3];
    TuileDepart();
    ~TuileDepart();
    TuilePlacee* getTuile(int i) const { return tuiles[i]; }
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
    static ControleurGeneral& getInstance() {
        static ControleurGeneral instance;
        return instance;
    }
    CarteMarquageFaune* getCarteRegleAleatoire();
    TuileDepart* getTuilesDepartAleatoires(); // retourne un pointeur vers tableau de 3 tuiles
};