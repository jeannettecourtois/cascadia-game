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
void ActionPlacerJeton::executer() {}
void ActionPlacerJeton::annuler() {}

ActionUtiliserJetonNature::ActionUtiliserJetonNature(Action* a) : actionCible(a) {}
ActionUtiliserJetonNature::~ActionUtiliserJetonNature() {}
void ActionUtiliserJetonNature::executer() {}
void ActionUtiliserJetonNature::annuler() {}
