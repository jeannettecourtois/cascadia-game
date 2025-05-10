#pargma once
#include "Joueur.h"
#include "Pioche.h"
#include "CarteMarquageFaune.h"

class ControleurTour {
public:
    ControleurTour();
    ~ControleurTour();
}


class Partie {
private:
    CarteMarquageFaune* cartesRegles[5];
    int nbJoueur;
    Joueur joueurs**;
    Pioche* pioche;
    ControleurTour* ctrlTour;
    int nbTour = 20;
public:
    Partie();
    ~Partie();
    bool EstFini();
    Joueur* GetGagnant();
}