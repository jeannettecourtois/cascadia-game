#pragma once
#include "tuilePlacee.h"
#include <string>


class PlateauJoueur {
private:
    int nbTuiles;
    TuilePlacee** tuiles;
public:
    PlateauJoueur();
    ~PlateauJoueur();
    PlateauJoueur(const PlateauJoueur&) = delete;
    PlateauJoueur& operator=(const PlateauJoueur&) = delete;
    void AjouterTuile(const TuilePlacee*);
    int GetNbTuiles() const { return nbTuiles; }
};


class Joueur {
private:
    int idJoueur;
    int nbJetonNature;
    std::string  nomJoueur;
    PlateauJoueur* plateau;
public:
    Joueur();
    ~Joueur();
    Joueur(const Joueur&) = delete;
    Joueur& operator=(const Joueur&) = delete;
    int CalculScore();
    int GetNbJetonNature() const { return nbJetonNature; }
    std::string GetNomJoueur() const { return nomJoueur; }
};