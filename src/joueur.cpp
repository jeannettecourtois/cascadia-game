#include "joueur.h"

Joueur :: Joueur() : idJoueur(1), nbJetonNature(0), nomJoueur("Joueur 1"), plateau(new PlateauJoueur()) {
    // Constructeur par défaut
}
Joueur :: ~Joueur() {
    delete plateau;
}
int Joueur :: CalculScore() {
    int score = 0;
    // Calculer le score en fonction des tuiles placées et des jetons selon les règles
    return score;
}


PlateauJoueur :: PlateauJoueur() : nbTuiles(0), tuiles(nullptr) {
    // Constructeur par défaut
}
PlateauJoueur :: ~PlateauJoueur() {
    for (int i = 0; i < nbTuiles; ++i) {
        delete tuiles[i];
    }
    delete[] tuiles;
}
void PlateauJoueur :: AjouterTuile(const TuilePlacee* tuile) {
    // Ajouter une tuile au plateau du joueur
    TuilePlacee** newTuiles = new TuilePlacee*[nbTuiles + 1]; //nouveau tableau de taille nbTuiles + 1
    for (int i = 0; i < nbTuiles; ++i) {
        newTuiles[i] = tuiles[i]; //copie des tuiles existantes
    }
    newTuiles[nbTuiles] = new TuilePlacee(*tuile); //copie de la tuile passé en paramètre
    delete[] tuiles;
    tuiles = newTuiles; //nouveau tableau avec la nouvelle tuile placée à la fin
    nbTuiles++;
}
