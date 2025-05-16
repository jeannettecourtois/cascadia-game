#include "partie.h"

// Controleur Tour

ControleurTour::ControleurTour() : nbrAction(0), listeActions(nullptr) {}

ControleurTour::~ControleurTour() {
    for (int i = 0; i < nbrAction; ++i) {
        delete listeActions[i];
    }
    delete[] listeActions;
}



// Partie
//1 joueur par defaut quand on créer une partie
Partie::Partie() : nbJoueur(1), joueurs(new Joueur*[1]), pioche(new Pioche()), ctrlTour(new ControleurTour(), nbTour(0)) {
        joueurs[0]=new Joueur();
}

//Partie avec plusieurs joueurs (max 4)
Partie::Partie(int nbJoueurs) : nbJoueur(nbJoueurs), joueurs(new Joueur*[nbJoueur]), pioche(new Pioche()), ctrlTour(new ControleurTour(), nbTour(0)) {
    for (int i = 0; i < nbJoueur; ++i) {
        joueurs[i] = new Joueur();
    }
}

Partie::~Partie() {
    for (int i = 0; i < nbJoueur; ++i) {
        delete joueurs[i];
    }
    delete[] joueurs;
    delete pioche;
    delete ctrlTour;
}

bool Partie::EstFini() {
    if (nbTour == 20) {
        return true;
    }
    return false; 
}

Joueur* Partie::GetGagnant() {
    int maxPoints = 0;
    Joueur* gagnant = nullptr;
    for (int i = 0; i < nbJoueur; ++i) {
        if (joueurs[i]->CalculScore() > maxPoints) {
            maxPoints = joueurs[i]->CalculScore();
            gagnant = joueurs[i];
        }
    }
    return gagnant;
}