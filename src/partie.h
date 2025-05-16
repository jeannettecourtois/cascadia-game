#pragma once
#include "joueur.h"
#include "pioche.h"
#include "carteMarquageFaune.h"
#include "action.h"

class ControleurTour {
    int nbrAction;
    Action** listeActions;
public:
    ControleurTour();
    ~ControleurTour();
    void ExecuterAction(Action* a);
    void AnnulerDerniereAction();
};


class Partie {
private:
    CarteMarquageFaune* cartesRegles[5];
    int nbJoueur;
    Joueur** joueurs;
    Pioche* pioche;
    ControleurTour* ctrlTour;
    int nbTour = 20;
public:
    Partie();
    Partie(int nbJoueurs);
    Partie(const Partie&) = delete;
    Partie& operator=(const Partie&) = delete;
    ~Partie();
    bool EstFini();
    Joueur* GetGagnant();
};