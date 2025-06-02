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
        cartesRegles[i] = ctrl.getCarteMarquageFaune();
        cout << "Carte règle faune " << i+1 << " sélectionnée." << std::endl;
    }

    // Sélection d’un set de 3 tuiles de départ (même pour tous les joueurs)
    TuileDepart* set = ctrl.getTuile(); // un tableau de 3 tuiles
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
    if (estFini()) {
        cout << "La partie est terminée." << endl;
        return;
    }

    ControleurTour* controleur = this->ctrlTour;
    if (!ctrlTour) {
        cerr << "Erreur : controleur de tour non initialisé !" << endl;
        return;
    }
    if (joueurCourant < 0 || joueurCourant >= nbJoueur) {
        cerr << "Erreur : joueur courant invalide !" << endl;
        return;
    }
    Joueur* joueur = joueurs[joueurCourant];
    cout << "Tour du joueur " << joueur + 1 << endl;
    bool actionFinie = false;
    Tuile* tuileSelectionnee = nullptr;
    string animalJetonSelectionne = "";
    bool tuilePlacee = false;
    bool jetonPlace = false;

    while (!actionFinie) {
        cout << "Que voulez-vous faire ?" << endl;
        cout << "1. Sélectionner une tuile de la pioche" << endl;
        cout << "2. Placer une tuile sur votre plateau" << endl;
        cout << "3. Placer un jeton faune" << endl;
        cout << "4. Annuler dernière action" << endl;
        cout << "5. Terminer mon tour" << endl;

        int choix;
        cin >> choix;

        switch (choix) {
            case 1: { // Sélectionner une tuile de la pioche
                int indiceTuile;
                pioche->afficherTuilesDisponibles(); // Affiche les tuiles disponibles dans la pioche
                cout << "Quelle tuile souhaitez-vous prendre (indice 0-3) ? ";
                cin >> indiceTuile;
                if (indiceTuile < 0 || indiceTuile > 3 || !pioche->getTuile(indiceTuile)) {
                    cout << "Indice invalide." << endl;
                    break;
                }
                tuileSelectionnee = pioche->getTuile(indiceTuile);
                animalJetonSelectionne = pioche->getJeton(indiceTuile); // Récupère le jeton associé à la tuile sélectionnée
                cout << "Tuile sélectionnée : ";
                tuileSelectionnee->afficherTuile();
                cout << "Jeton sélectionné : " << animalJetonSelectionne << endl;

                Action* action = new ActionSelectionTuile();
                controleur->executerAction(action);
                break;
            }
            case 2: { // Placer une tuile sur le plateau
                if (!tuileSelectionnee) {
                    cout << "Aucune tuile sélectionnée. Veuillez d'abord sélectionner une tuile." << endl;
                    break;
                }
                int x, y;
                cout << "Où souhaitez-vous placer la tuile ? (x,y) : "; // pas avec la position mais avec les cardinaux d'un id de tuile déjà placée
                cout << " x : ";
                cin >> x;
                cout << " y : ";
                cin >> y;
                Position pos(x, y);
                Action* action = new ActionPlacerTuile(tuileSelectionnee, pos); // recupère la tuile sélectionnée dans case 1
                controleur->executerAction(action);
                tuilePlacee = true;
                break;
            }
            case 3: { // Placer un jeton faune
                if (animalJetonSelectionne.empty()){
                    cout << "Aucun jeton faune sélectionné. Veuillez d'abord sélectionner un jeton." << endl;
                    break;
                }
                int x,y;
                cout << "Sur quelle tuile souhaitez-vous placer le jeton faune ? (x,y) : " << animalJetonSelectionne << endl;
                cout << " x : ";
                cin >> x;
                cout << " y : ";
                cin >> y;

                Position pos(x, y);
                TuilePlacee* tuilePlacee = joueur->getPlateau()->getTuilePlacee(pos); // Récupère la tuile placée à la position donnée
                if (!tuilePlacee) {
                    cout << "Aucune tuile placée à cette position. Veuillez sélectionner un tuile déjà placée." << endl;
                    break;
                }
                // Vérifier si le jeton peut être placé sur la tuile
                if (!tuilePlacee->getTuile()->contientAnimal(animalJetonSelectionne)) {
                    cout << "Le jeton faune ne peut pas être placé sur cette tuile." << endl;
                    break;
                }

                Action* action = new ActionPlacerJeton(animalJetonSelectionne, tuilePlacee); //recupérer l'animal sélectionné dans la pioche et la tuile placée correspondante à la position
                controleur->executerAction(action);
                jetonPlace = true;
                break;
            }
            case 4: { // Annuler la dernière action
                controleur->annulerDerniereAction();
                break;
            }
            case 5: { // Terminer le tour
                if (tuilePlacee && jetonPlace) {
                    cout << "Tour terminé avec succès." << endl;
                } else if (!tuilePlacee) {
                    cout << "Vous devez placer une tuile avant de terminer votre tour." << endl;
                    continue; // Recommencer le tour si la tuile n'est pas placée
                } else if (!jetonPlace) {
                    cout << "Vous devez placer un jeton faune avant de terminer votre tour." << endl;
                    continue; // Recommencer le tour si le jeton n'est pas placé
                }
                actionFinie = true;
                break;
            }
            default:
                cout << "Choix invalide." << endl;
        }
    }

    passerAuJoueurSuivant();
    nbTour--;




    // Exemple : appeler le controleur de tour pour jouer une action
    // ctrlTour->executerAction(...); // à adapter selon ton système d’action

    // Diminuer le compteur de tour
    nbTour--;
    passerAuJoueurSuivant();
}

void Partie::passerAuJoueurSuivant() {
    joueurCourant = (joueurCourant + 1) % nbJoueur;
}


