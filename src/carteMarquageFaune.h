#pragma once
#include "enum.h"
#include "joueur.h"

class CarteMarquageFaune {
private:
    animal animalCarte;
public:
    CarteMarquageFaune(animal a);
    ~CarteMarquageFaune();
    animal GetAnimalCarte() {return animalCarte;}
    int CalculPoints(PlateauJoueur&);
};

class CarteMarquageFauneParMasque : public CarteMarquageFaune {
public:
    CarteMarquageFauneParMasque(animal a);
    ~CarteMarquageFauneParMasque();
    int CalculPoints(PlateauJoueur&);
};

class CarteMarquageFauneParDiversiteDeType : public CarteMarquageFaune {//Utile pour le renard
public:
    CarteMarquageFauneParDiversiteDeType(animal a);
    ~CarteMarquageFauneParDiversiteDeType();
    int CalculPoints(PlateauJoueur&);
};