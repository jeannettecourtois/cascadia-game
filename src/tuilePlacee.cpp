#include "tuilePlacee.h"
#include "enum.h"


Position::~Position() {}


TuilePlacee::TuilePlacee() : tuile(nullptr), jeton(animalOuPas::Vide), pos(0, 0), rotation(0) {}

TuilePlacee::TuilePlacee(const TuilePlaceeDeplacable* t) : tuile(t->GetTuile()), jeton(t->GetJeton()), pos(t->GetPosition()), rotation(t->GetRotation()) {}

TuilePlacee::~TuilePlacee() {}

void TuilePlacee::AjouterJeton(const animalOuPas a) {
    jeton = a;
}