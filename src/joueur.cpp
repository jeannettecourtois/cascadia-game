#include "joueur.h"
#include "partie.h"

Joueur :: Joueur() : idJoueur(1), nbJetonNature(0), nomJoueur("Joueur 1"), plateau(new PlateauJoueur()) {
    // Constructeur par défaut
}
Joueur :: ~Joueur() {
    delete plateau;
}
int Joueur :: calculScore() {
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
void PlateauJoueur:: ajouterTuile(const TuilePlacee* tuile) {
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
void PlateauJoueur::ajouterTuileDepart(const TuileDepart* set) {
    Position pos1(0, 0); //tuile 1 au centre (0,0)
    Position pos2 = pos1.getSE();  // (0, 1)
    Position pos3 = pos1.getSW(); // (-1, 1)

    set->getTuile(0)->deplacer(pos1);
    ajouterTuile(set->getTuile(0));

    set->getTuile(1)->deplacer(pos2);
    ajouterTuile(set->getTuile(1));

    set->getTuile(2)->deplacer(pos3);
    ajouterTuile(set->getTuile(2));
}