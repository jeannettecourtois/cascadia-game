#pragma once
#include "tuilePlacee.h"
#include "enum.h"


class Action {
public:
    void executer();
    void annuler();
};

class ActionSelectionTuile: public Action {
private:
    Tuile* tuileSelection;
public:
    ActionSelectionTuile();
    ~ActionSelectionTuile();
    void executer();
    void annuler();
};

class ActionSelectionJeton: public Action {
private:
    animalOuPas jetonSelection;
public:
    ActionSelectionJeton();
    ~ActionSelectionJeton();
    void executer();
    void annuler();
};

class ActionPlacerTuile: public Action {
private:
    Tuile* tuile;
    Position pos;
public:
    ActionPlacerTuile(Tuile* t, Position p);
    ~ActionPlacerTuile();
    void executer();
    void annuler();
};

class ActionPlacerJeton: public Action {
private:
    TuilePlacee* cible;
    animalOuPas jeton;
public:
    ActionPlacerJeton(animalOuPas* j, TuilePlacee* c);
    ~ActionPlacerJeton();
    void executer();
    void annuler();
};

class ActionUtiliserJetonNature: public Action {
private:
    Action* actionCible;
public:
    ActionUtiliserJetonNature(Action* a);
    ~ActionUtiliserJetonNature();
    void executer();
    void annuler();
};

class SelectionTuileJeton : public ActionUtiliserJetonNature {
public:
    SelectionTuileJeton();
    ~SelectionTuileJeton();
    void executer();
    void annuler();
};

class SupressionJetonPioche : public ActionUtiliserJetonNature {
public:
    SupressionJetonPioche();
    ~SupressionJetonPioche();
    void executer();
    void annuler();
};