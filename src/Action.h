#pragma once
#include "TuilePlacee.h"


class Action {
public:
    void execute();
    void undo();
}

class ActionSelectionTuile: class Action {
private:
    Tuile* tuileSelection;
public:
    ActionSelectionTuile();
    ~ActionSelectionTuile();
    void execute();
    void undo();
}

class ActionSelectionJeton: class Action {
private:
    animalOuPas jetonSelection;
public:
    ActionSelectionJeton();
    ~ActionSelectionJeton();
    void execute();
    void undo();
}

class ActionPlacerTuile: class Action {
private:
    Tuile* tuile;
    Position pos;
public:
    ActionPlacerTuile(Tuile* t, Position p);
    ~ActionPlacerTuile();
    void execute();
    void undo();
}

class ActionPlacerJeton: class Action {
private:
    TuilePlacee* cible;
    animalOuPas jeton;
public:
    ActionPlacerJeton(animalOuPas* j, TuilePlacee* c);
    ~ActionPlacerJeton();
    void execute();
    void undo();
}

class ActionUtiliserJetonNature: class Action {
private:
    Action* actionCible;
public:
    ActionUtiliserJetonNature(Action* a);
    ~ActionUtiliserJetonNature();
    void execute();
    void undo();
}