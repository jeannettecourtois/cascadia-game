#pragma once
#include "enum.h"
#include "controleurGeneral.h"
class PlateauJoueur; // Déclaration anticipée

class CarteMarquageFaune {
private:
    animal animalCarte;
public:
    CarteMarquageFaune(animal a);
    ~CarteMarquageFaune();
    animal GetAnimalCarte() {return animalCarte;}
    int calculPoints(PlateauJoueur&);
};

class CarteMarquageFauneParMasque : public CarteMarquageFaune {
public:
    CarteMarquageFauneParMasque(animal a);
    ~CarteMarquageFauneParMasque();
    int calculPoints(PlateauJoueur&);
};

class CarteMarquageFauneParDiversiteDeType : public CarteMarquageFaune {//Utile pour le renard
public:
    CarteMarquageFauneParDiversiteDeType(animal a);
    ~CarteMarquageFauneParDiversiteDeType();
    int calculPoints(PlateauJoueur&);
};