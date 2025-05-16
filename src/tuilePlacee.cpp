#include "tuilePlacee.h"
#include "enum.h"


TuilePlacee::TuilePlacee():tuile(nullptr),jeton(animalOuPas::Vide),pos(0,0),rotation(0){}

TuilePlacee::TuilePlacee(const TuilePlaceeDeplacable* t):tuile(t->GetTuile()),jeton(t->GetJeton()),pos(t->GetPosition()),rotation(t->GetRotation()){}

TuilePlacee::~TuilePlacee(){}

void TuilePlacee::Deplacer(const Position& p) {
    // to do
}

void TuilePlacee::Tourner(int n) {
    // to do
}

void TuilePlacee::AjouterJeton(animalOuPas a) {
    jeton = a;
}