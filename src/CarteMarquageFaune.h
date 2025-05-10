#pragma once
#include "enum.h"
#include "Joueur.h"

class CarteMarquageFaune {
private:
    animal animalCarte;
public:
    CarteMarquageFaune();
    ~CarteMarquageFaune();
    animal GetAnimalCarte() {return animalCarte;}
    int CalculPoints(PlateauJoueur&);
};

class CarteMarquageFauneParMasque : public CarteMarquageFaune {
public:
    CarteMarquageFauneParMasque();
    ~CarteMarquageFauneParMasque();
    int CalculPoints(PlateauJoueur&);
};

class CarteMarquageFauneParDiversiteDeType : public CarteMarquageFaune {//Utile pour le renard
public:
    CarteMarquageFauneParDiversiteDeType();
    ~CarteMarquageFauneParDiversiteDeType();
    int CalculPoints(PlateauJoueur&);
};