#include "controleurGeneral.h"
#include "enum.h"
#include "affichable.h"
#include <mutex>
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

// Initialisation des attributs statiques du singleton
ControleurGeneral* ControleurGeneral::instancePtr = nullptr;
mutex ControleurGeneral::mtx;

// Constructeur privé
ControleurGeneral::ControleurGeneral()
    : nbTuilesHabitat(85), nbJetonFaune(100), nbJetonsNature(25), nbCartesMarquageFaune(15),
      gen(rd()), distTuiles(0, 84), distJetons(0, 99), distCartes(0, 14) {
    
    // Création des jetons Faune
    for (unsigned int i = 0; i < 20; ++i) tabJetons[i] = new JetonFaune(Animal::Ours);
    for (unsigned int i = 20; i < 40; ++i) tabJetons[i] = new JetonFaune(Animal::Cerf);
    for (unsigned int i = 40; i < 60; ++i) tabJetons[i] = new JetonFaune(Animal::Saumon);
    for (unsigned int i = 60; i < 80; ++i) tabJetons[i] = new JetonFaune(Animal::Aigle);
    for (unsigned int i = 80; i < 100; ++i) tabJetons[i] = new JetonFaune(Animal::Renard);

    // Création des tuiles
    for (unsigned int i = 0; i < 85; ++i) tabTuiles[i] = new Tuile();

    // Création des cartes de marquage faune
    for (unsigned int i = 0; i < 3; ++i) tabCartesMarquage[i] = new CarteMarquageFaune(Animal::Aigle);
    for (unsigned int i = 3; i < 6; ++i) tabCartesMarquage[i] = new CarteMarquageFaune(Animal::Cerf);
    for (unsigned int i = 6; i < 9; ++i) tabCartesMarquage[i] = new CarteMarquageFaune(Animal::Ours);
    for (unsigned int i = 9; i < 12; ++i) tabCartesMarquage[i] = new CarteMarquageFaune(Animal::Renard);
    for (unsigned int i = 12; i < 15; ++i) tabCartesMarquage[i] = new CarteMarquageFaune(Animal::Saumon);
}

// Destructeur
ControleurGeneral::~ControleurGeneral() {
    for (unsigned int i = 0; i < 100; ++i) delete tabJetons[i];
    for (unsigned int i = 0; i < 85; ++i) delete tabTuiles[i];
    for (unsigned int i = 0; i < 15; ++i) delete tabCartesMarquage[i];
}

// Singleton getter
ControleurGeneral& ControleurGeneral::getInstance() {
    if (instancePtr == nullptr) {
        lock_guard<mutex> lock(mtx);
        if (instancePtr == nullptr) {
            instancePtr = new ControleurGeneral();
        }
    }
    return *instancePtr;
}

// Méthodes utilitaires
Tuile* ControleurGeneral::getTuile() {
    return tabTuiles[distTuiles(gen)];
}

JetonFaune* ControleurGeneral::getJetonFaune() {
    return tabJetons[distJetons(gen)];
}

CarteMarquageFaune* ControleurGeneral::getCarteMarquageFaune() {
    return tabCartesMarquage[distCartes(gen)];
}

void ControleurGeneral::afficher(std::ostream& f) const {
    f << "Le jeu peut commencer.\n";
}