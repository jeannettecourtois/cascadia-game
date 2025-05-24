#pragma once
#include <iostream>
#include "tuile.h"
#include "controleurGeneral.h"

class SacTuile {
private:
    int nbTuile;
    Tuile** tuiles;
public:
    SacTuile();
    ~SacTuile();
    Tuile* Piocher();
    void mettreDansLeSac(Tuile&);
};


class SacJeton {
private:
//Est-ce qu'il serait pas mieux de faire une liste basé sur l'énumération animal => on peut rajouter des animaux dans la liste
    int nbOurs;
    int nbCerf;
    int nbSaumon;
    int nbAigle;
    int nbRenard;
public:
    SacJeton();
    ~SacJeton();
    animal* Piocher();
    void mettreDansLeSac(animal);
};

class Pioche {
private:
    Tuile* tuiles[4];
    animalOuPas jetons[4];
    int idTuileChoisis;
    SacTuile* sacDeTuiles;
    SacJeton* sacDeJetons;
public:
    Pioche();
    ~Pioche();
    void preparerPioche();
    void selectionnerTuile();
    void selectionnerJeton();
};