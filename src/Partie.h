#pragma once
#include "Joueur.h"
#include "Pioche.h"
#include "CarteMarquageFaune.h"
#include "Action.h"

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
    Joueur joueurs**;
    Pioche* pioche;
    ControleurTour* ctrlTour;
    int nbTour = 20;
public:
    Partie();
    ~Partie();
    bool EstFini();
    Joueur* GetGagnant();
};