#include "action.h"

void Action::executer() {}
void Action::annuler() {}

ActionSelectionTuile::ActionSelectionTuile() : tuileSelection(nullptr) {}
ActionSelectionTuile::~ActionSelectionTuile() {}
void ActionSelectionTuile::executer() {}
void ActionSelectionTuile::annuler() {}

ActionSelectionJeton::ActionSelectionJeton() : jetonSelection(animalOuPas::Vide) {}
ActionSelectionJeton::~ActionSelectionJeton() {}
void ActionSelectionJeton::executer() {}
void ActionSelectionJeton::annuler() {}

ActionPlacerTuile::ActionPlacerTuile(Tuile* t, Position p) : tuile(t), pos(p) {}
ActionPlacerTuile::~ActionPlacerTuile() {}
void ActionPlacerTuile::executer() {}
void ActionPlacerTuile::annuler() {}

ActionPlacerJeton::ActionPlacerJeton(animalOuPas j, TuilePlacee* c) : jeton(j), cible(c) {}
ActionPlacerJeton::~ActionPlacerJeton() {}
void ActionPlacerJeton::executer() {
    //verifier si la tuile est déjà placée
    // verifier si l'animal du jeton est valide pour la tuile
}
void ActionPlacerJeton::annuler() {}

ActionUtiliserJetonNature::ActionUtiliserJetonNature(Action* a) : actionCible(a) {}
ActionUtiliserJetonNature::~ActionUtiliserJetonNature() {}
void ActionUtiliserJetonNature::executer() {}
void ActionUtiliserJetonNature::annuler() {}
