#pragma once
#include <string>
#include "tuilePlacee.h"
using namespace std;

class PlateauJoueur {
private:
    int nbTuiles;
    TuilePlacee** tuiles;
public:
    PlateauJoueur();
    ~PlateauJoueur();
    PlateauJoueur(const PlateauJoueur&) = delete;
    PlateauJoueur& operator=(const PlateauJoueur&) = delete;
    void ajouterTuile(const TuilePlacee*);
    void ajouterTuileDepart(const TuileDepart* set);
    int getNbTuiles() const { return nbTuiles; }
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
    int calculScore();
    int getNbJetonNature() const { return nbJetonNature; }
    string getNomJoueur() const { return nomJoueur; }
    PlateauJoueur* getPlateau() const { return plateau; }
};