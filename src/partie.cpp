#include "partie.h"
#include "controleurGeneral.h"
#include "pioche.h"
#include "action.h"

using namespace std;

// Controleur Tour
ControleurTour::ControleurTour() {}

ControleurTour::~ControleurTour() {
    for (Action* a : listeActions) {
        delete a;
    }
    listeActions.clear();
}

void ControleurTour::executerAction(Action* a) {
    a->executer();
    listeActions.push_back(a);
}

void ControleurTour::annulerDerniereAction() {
    if (!listeActions.empty()) {
        listeActions.back()->annuler(); // annuler la derniere action
        delete listeActions.back(); // libérer la mémoire
        listeActions.pop_back(); // supprimer l'action du vecteur
    }
}



// PARTIE
//1 joueur par defaut quand on créer une partie - Partie solo
Partie::Partie() : nbJoueur(1), joueurs(new Joueur*[1]), pioche(new Pioche()), ctrlTour(new ControleurTour()), joueurCourant(0) {
        joueurs[0]=new Joueur();
}

//Partie avec plusieurs joueurs (max 4)
Partie::Partie(int nbJoueurs) : nbJoueur(nbJoueurs), joueurs(new Joueur*[nbJoueur]), pioche(new Pioche()), ctrlTour(new ControleurTour()), joueurCourant(0) {
    if (nbJoueurs < 1 || nbJoueurs > 4) {
        cerr << "Nombre de joueurs invalide. Doit être entre 1 et 4.\n";
        nbJoueur = 1; // Réinitialiser à 1 joueur par défaut
    }
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

bool Partie::estFini() const {
    return nbTour == 0;
}

Joueur* Partie::getGagnant() const {
    if (nbJoueur == 0) return nullptr;

    int maxPoints = joueurs[0]->calculScore();
    Joueur* gagnant = joueurs[0];
    bool egalite = false;

    for (int i = 1; i < nbJoueur; ++i) {
        int score = joueurs[i]->calculScore();
        if (score > maxPoints) {
            maxPoints = score;
            gagnant = joueurs[i];
            egalite = false;
        } else if (score == maxPoints) {
            egalite = true;
        }
    }
    if (egalite) {
        std::cout << "Il y a une égalité entre plusieurs joueurs." << std::endl;
        return nullptr;
    }
    return gagnant;
}


void Partie::initialiserPartie() {
    //récupération du singleton du jeu
    ControleurGeneral& ctrl = ControleurGeneral::getInstance();
    //initialisation du RNG (générateur de nombres aléatoires) pour choix de cartes
    srand(time(nullptr));

    // Sélection aléatoire de 5 cartes de marquage faune
    for (int i = 0; i < 5; ++i) {
        cartesRegles[i] = ctrl.getCarteRegleAleatoire();
        cout << "Carte règle faune " << i+1 << " sélectionnée." << std::endl;
    }

    // Sélection d’un set de 3 tuiles de départ (même pour tous les joueurs)
    TuileDepart* set = ctrl.getTuilesDepartAleatoires(); // un tableau de 3 tuiles
    cout << "Set de tuiles de départ généré." << std::endl;

    // Distribution d'une copie du set à chaque joueur
    for (int i = 0; i < nbJoueur; ++i) {
        TuileDepart* copie = new TuileDepart(*set); // copie pour chaque joueur
        joueurs[i]->getPlateau()->ajouterTuileDepart(copie);
    }
    delete set; // libération mémoire

    //Mise à jour de la pioche
    if (!pioche) {
        cerr << "Erreur : pioche non initialisée !" << std::endl;
        return;
    }
    pioche->preparerPioche();
    cout << "Pioche préparée." << std::endl;
    // Réinitialisation du compteur de tours
    nbTour = 20;
    cout << "Initialisation de la partie terminée." << std::endl;
}

void Partie::jouerTour() {
    cout << "Tour du joueur " << joueurCourant + 1 << endl;
    // Exemple : appeler le controleur de tour pour jouer une action
    // ctrlTour->executerAction(...); // à adapter selon ton système d’action

    // Diminuer le compteur de tour
    nbTour--;
    passerAuJoueurSuivant();
}

void Partie::passerAuJoueurSuivant() {
    joueurCourant = (joueurCourant + 1) % nbJoueur;
}


