#include "controleurGeneral.h"
#include "enum.h"
#include "affichable.h"
using namespace std;

TuileDepart::TuileDepart() {
    for (int i = 0; i < 3; ++i) {
        tuiles[i] = nullptr;
    }
}

TuileDepart::TuileDepart(const TuileDepart& other) {
    for (int i = 0; i < 3; ++i) {
        if (other.tuiles[i])
            tuiles[i] = new TuilePlacee(*other.tuiles[i]); // Copie profonde
        else
            tuiles[i] = nullptr;
    }
}

TuileDepart::~TuileDepart() {
    for (int i = 0; i < 3; ++i) {
        delete tuiles[i];
    }
}

ControleurGeneral::ControleurGeneral() : nbTuilesHabitat(85), nbJetonFaune(100), nbJetonsNature(25), nbCartesMarquageFaune(21){
    //construction des jetons Faune
    //20 Ours 
    for(unsigned int i=0; i<20; ++i){ tabJetons[i] = new JetonFaune(Animal::Ours);}
    //20 Cerfs
    for(unsigned int i=0; i<20; ++i){ tabJetons[i] = new JetonFaune(Animal::Cerf);}
    //20 Saumons
    for(unsigned int i=0; i<20; ++i){ tabJetons[i] = new JetonFaune(Animal::Saumon);}
    //20 Aigles
    for(unsigned int i=0; i<20; ++i){ tabJetons[i] = new JetonFaune(Animal::Aigle);}
    //20 Renards 
    for(unsigned int i=0; i<20; ++i){ tabJetons[i] = new JetonFaune(Animal::Renard);}

    //construction des Tuiles 
    for(unsigned int i = 0; i <85; ++i){ tabTuiles[i] = new Tuile();}

}



/*ControleurGeneral::ControleurGeneral() : nbTuiles(0), nbCartesRegles(0), nbTuilesDepart(0),
      tuiles(nullptr), cartesRegles(nullptr), tuilesDepart(nullptr) {
    srand(std::time(nullptr));
}

ControleurGeneral::~ControleurGeneral() {
    if (tuiles) {
        for (int i = 0; i < nbTuiles; ++i)
            delete tuiles[i];
        delete[] tuiles;
    }

    if (cartesRegles) {
        for (int i = 0; i < nbCartesRegles; ++i)
            delete cartesRegles[i];
        delete[] cartesRegles;
    }

    if (tuilesDepart) {
        for (int i = 0; i < nbTuilesDepart; ++i)
            delete tuilesDepart[i];
        delete[] tuilesDepart;
    }
}


CarteMarquageFaune* ControleurGeneral::getCarteRegleAleatoire() {
    if (nbCartesRegles == 0 || cartesRegles == nullptr) {
        throw runtime_error("Aucune carte règle disponible.");
    }
    int index = rand() % nbCartesRegles; // Choisir un index aléatoire parmis les cartes
    return cartesRegles[index];
}

TuileDepart* ControleurGeneral::getTuilesDepartAleatoires() {
    if (nbTuilesDepart == 0 || tuilesDepart == nullptr) {
        throw std::runtime_error("Aucune tuile de départ disponible.");
    }
    TuileDepart* set = new TuileDepart();
    for (int i = 0; i < 3; ++i) {
        int index = rand() % nbTuilesDepart;
        set->tuiles[i] = new TuilePlacee(*tuilesDepart[index]->tuiles[i]);
    }
    return set; // retourne un tableau de 3 tuiles
}*/
