#include "Action.h"

void Action::execute() {}
void Action::undo() {}

ActionSelectionTuile::ActionSelectionTuile() : tuileSelection(nullptr) {}
ActionSelectionTuile::~ActionSelectionTuile() {}
void ActionSelectionTuile::execute() {}
void ActionSelectionTuile::undo() {}

ActionSelectionJeton::ActionSelectionJeton() : jetonSelection(animalOuPas::Vide) {}
ActionSelectionJeton::~ActionSelectionJeton() {}
void ActionSelectionJeton::execute() {}
void ActionSelectionJeton::undo() {}

ActionPlacerTuile::ActionPlacerTuile(Tuile* t, Position p) : tuile(t), pos(p) {}
ActionPlacerTuile::~ActionPlacerTuile() {}
void ActionPlacerTuile::execute() {}
void ActionPlacerTuile::undo() {}

ActionPlacerJeton::ActionPlacerJeton(animalOuPas* j, TuilePlacee* c) : jeton(*j), cible(c) {}
ActionPlacerJeton::~ActionPlacerJeton() {}
void ActionPlacerJeton::execute() {}
void ActionPlacerJeton::undo() {}

ActionUtiliserJetonNature::ActionUtiliserJetonNature(Action* a) : actionCible(a) {}
ActionUtiliserJetonNature::~ActionUtiliserJetonNature() {}
void ActionUtiliserJetonNature::execute() {}
void ActionUtiliserJetonNature::undo() {}
