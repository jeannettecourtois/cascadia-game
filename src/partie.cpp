#include "partie.h"
#include "controleurGeneral.h"

using namespace std;

// Controleur Tour
ControleurTour::ControleurTour() : nbrAction(0), listeActions(nullptr) {}

ControleurTour::~ControleurTour() {
    for (int i = 0; i < nbrAction; ++i) {
        delete listeActions[i];
    }
    delete[] listeActions;
}



// Partie
//1 joueur par defaut quand on créer une partie - Partie solo
Partie::Partie() : nbJoueur(1), joueurs(new Joueur*[1]), pioche(new Pioche()), ctrlTour(new ControleurTour()) {
        joueurs[0]=new Joueur();
}

//Partie avec plusieurs joueurs (max 4)
Partie::Partie(int nbJoueurs) : nbJoueur(nbJoueurs), joueurs(new Joueur*[nbJoueur]), pioche(new Pioche()), ctrlTour(new ControleurTour()) {
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
    if (nbTour == 0) { //au début de la partie, on a 20 tours
        return true;
    }
    return false; 
}

Joueur* Partie::GetGagnant() {
    int maxPoints = 0;
    Joueur* gagnant = nullptr;
    for (int i = 0; i < nbJoueur; ++i) {
        if (joueurs[i]->calculScore() > maxPoints) {
            maxPoints = joueurs[i]->calculScore();
            gagnant = joueurs[i];
        }
    }
    return gagnant;
}


void Partie::InitialiserPartie() {
    //récupération du singleton du jeu
    ControleurGeneral& ctrl = ControleurGeneral::getInstance();
    //initialisation du RNG (générateur de nombres aléatoires) pour choix de cartes
    srand(time(nullptr));
    // Sélection aléatoire de 5 cartes de marquage faune
    for (int i = 0; i < 5; ++i) {
        cartesRegles[i] = ctrl.getCarteRegleAleatoire();
    }
    // Sélection d’un set de 3 tuiles de départ (même pour tous les joueurs)
    TuileDepart* set = ctrl.getTuilesDepartAleatoires(); // un tableau de 3 tuiles
// Distribution du même set à chaque joueur
    for (int i = 0; i < nbJoueur; ++i) {
        joueurs[i]->getPlateau()->ajouterTuileDepart(set->tuiles[0]);
    }

    // Réinitialisation du compteur de tours
    nbTour = 20;
}