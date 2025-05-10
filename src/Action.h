#pragma once
#include "TuilePlacee.h"


class Action {
public:
    void execute();
    void undo();
}

class ActionSelectionTuile: public Action {
private:
    Tuile* tuileSelection;
public:
    ActionSelectionTuile();
    ~ActionSelectionTuile();
    void execute();
    void undo();
}

class ActionSelectionJeton: public Action {
private:
    animalOuPas jetonSelection;
public:
    ActionSelectionJeton();
    ~ActionSelectionJeton();
    void execute();
    void undo();
}

class ActionPlacerTuile: public Action {
private:
    Tuile* tuile;
    Position pos;
public:
    ActionPlacerTuile(Tuile* t, Position p);
    ~ActionPlacerTuile();
    void execute();
    void undo();
}

class ActionPlacerJeton: public Action {
private:
    TuilePlacee* cible;
    animalOuPas jeton;
public:
    ActionPlacerJeton(animalOuPas* j, TuilePlacee* c);
    ~ActionPlacerJeton();
    void execute();
    void undo();
}

class ActionUtiliserJetonNature: public Action {
private:
    Action* actionCible;
public:
    ActionUtiliserJetonNature(Action* a);
    ~ActionUtiliserJetonNature();
    void execute();
    void undo();
}

class SelectionTuileJeton : public ActionUtiliserJetonNature {
public:
    SelectionTuileJeton();
    ~SelectionTuileJeton();
    void execute();
    void undo();
}

class SupressionJetonPioche : public ActionUtiliserJetonNature {
public:
    SupressionJetonPioche();
    ~SupressionJetonPioche();
    void execute();
    void undo();
}