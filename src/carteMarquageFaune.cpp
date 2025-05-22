#include "carteMarquageFaune.h"
#include "joueur.h"

CarteMarquageFaune::CarteMarquageFaune(animal a) : animalCarte(a) {}
CarteMarquageFaune::~CarteMarquageFaune() {}

int CarteMarquageFaune::calculPoints(PlateauJoueur&) {
    return 0; 
}


CarteMarquageFauneParMasque::CarteMarquageFauneParMasque(animal a) : CarteMarquageFaune(a) {}
CarteMarquageFauneParMasque::~CarteMarquageFauneParMasque() {}

int CarteMarquageFauneParMasque::calculPoints(PlateauJoueur&) {
    return 0; 
}


CarteMarquageFauneParDiversiteDeType::CarteMarquageFauneParDiversiteDeType(animal a) : CarteMarquageFaune(a) {}
CarteMarquageFauneParDiversiteDeType::~CarteMarquageFauneParDiversiteDeType() {}

int CarteMarquageFauneParDiversiteDeType::calculPoints(PlateauJoueur&) {
    return 0; 
}

