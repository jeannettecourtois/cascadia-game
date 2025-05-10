#pragma once
#include "TuilePlacee.h"
#include <string>


class PlateauJoueur {
private:
    int nbTuiles;
    TuilePlacee** tuiles;
public:
    PlateauJoueur();
    ~PlateauJoueur();
    void AjouterTuile(const TuilePlacee*);
}


class Joueur {
private:
    int idJoueur;
    int nbJetonNature;
    std::string  nomJoueur;
    PlateauJoueur* plateau;
public:
    Joueur();
    ~Joueur();
    int CalculScore();
    int GetNbJetonNature() const { return nbJetonNature; }
    std::string GetNomJoueur() const { return nomJoueur; }
}