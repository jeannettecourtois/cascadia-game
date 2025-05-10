#include "CarteMarquageFaune.h"

CarteMarquageFaune::CarteMarquageFaune(animal a) : animalCarte(a) {}
CarteMarquageFaune::~CarteMarquageFaune() {}

animal CarteMarquageFaune::GetAnimalCarte() { return animalCarte; }

int CarteMarquageFaune::CalculPoints(PlateauJoueur&) {
    return 0; 
}


CarteMarquageFauneParMasque::CarteMarquageFauneParMasque(animal a) : CarteMarquageFaune(a) {}
CarteMarquageFauneParMasque::~CarteMarquageFauneParMasque() {}

int CarteMarquageFauneParMasque::CalculPoints(PlateauJoueur&) {
    return 0; 
}


CarteMarquageFauneParDiversiteDeType::CarteMarquageFauneParDiversiteDeType(animal a) : CarteMarquageFaune(a) {}
CarteMarquageFauneParDiversiteDeType::~CarteMarquageFauneParDiversiteDeType() {}

int CarteMarquageFauneParDiversiteDeType::CalculPoints(PlateauJoueur&) {
    return 0; 
}

