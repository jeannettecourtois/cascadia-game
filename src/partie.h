#pragma once
#include<vector>
using namespace std;

class Pioche;
class ControleurTour;
class TuileDepart;
class TuilePlacee;
class Joueur;
class CarteMarquageFaune;
class Action;


class ControleurTour {
    vector<Action*> listeActions;
public:
    ControleurTour();
    ~ControleurTour();
    void executerAction(Action* a);
    void annulerDerniereAction();
};


class Partie {
private:
    CarteMarquageFaune* cartesRegles[5];
    int nbJoueur;
    Joueur** joueurs;
    Pioche* pioche;
    ControleurTour* ctrlTour;
    int nbTour = 20;
    int joueurCourant=0;
public:
    Partie(); //partie solo
    Partie(int nbJoueurs); //partie multi-joueurs
    Partie(const Partie&) = delete;
    Partie& operator=(const Partie&) = delete;
    ~Partie();

    int getNbJoueur() const {return nbJoueur;}
    int getNbTour() const {return nbTour;}
    Joueur* getJoueur(int i) const {return joueurs[i];}
    CarteMarquageFaune* getCarteRegle(int i) const { return cartesRegles[i]; }
    Pioche* getPioche() const { return pioche; }
    int getJoueurCourant() const { return joueurCourant; }

    bool estFini() const;
    Joueur* getGagnant() const;
    void initialiserPartie();
    void jouerTour();
    void passerAuJoueurSuivant();
};