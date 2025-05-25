#pragma once
#include <string>
#include "partie.h"
#include "joueur.h"
#include "carteMarquageFaune.h"
#include "enum.h"
#include "affichable.h"

class TuileDepart {
public:
    TuilePlacee* tuiles[3];
    TuileDepart();
    TuileDepart(const TuileDepart& other);
    ~TuileDepart();
    TuilePlacee* getTuile(int i) const { return tuiles[i]; }
};

class JetonFaune: public affichable{
    Animal ani;
public:
    JetonFaune(Animal a) : ani(a){}
    ~JetonFaune() = default;
    //méthodes et accesseurs en lecture 
    Animal getAnimal() const{return ani;}
    void afficher(std::ostream& f=std::cout ) const override{
        switch(ani){
            case Animal::Ours: 
            f << "L'animal est un ours. \n";
            break;
            case Animal::Cerf: 
            f <<"L'animal s'agit d'un cerf.\n";
            break; 
            case Animal::Saumon: 
            f <<"L'animal s'agit d'un saumon.\n";
            break;
            case Animal::Aigle: 
            f <<"L'animal s'agit d'un aigle.\n";
            break;
            case Animal::Renard: 
            f <<"L'animal s'agit d'un renard.\n";
            break;
        }
    }
};

class jetonNature : public affichable{
    void afficher(std::ostream& f=std::cout ) const{
        f << "Vous disposez d'un jeton nature. Vous pouvez remplacer le fonctionnement classique en choisissant séparément la tuile et le jeton, supprimer des jetons de la pioche.\n";
    }

};


class ControleurGeneral: public affichable{
    private:
    int nbTuilesHabitat; 
    int nbJetonFaune; 
    int nbJetonsNature; 
    int nbCartesMarquageFaune; 
    JetonFaune* tabJetons[100]; 
    Tuile* tabTuiles[85]; 
    public: 
    ControleurGeneral();
    ~ControleurGeneral();
    void afficher(std::ostream& f=std::cout ) const{
        f << "Le jeu peut commencer. \n";
    }
};

/*class ControleurGeneral { // Singleton
private:
    int nbTuiles;
    int nbCartesRegles;
    int nbTuilesDepart;
    Tuile** tuiles;
    CarteMarquageFaune** cartesRegles;
    TuileDepart** tuilesDepart;
    ControleurGeneral();
    ~ControleurGeneral();
public:
    ControleurGeneral(const ControleurGeneral&) = delete;
    ControleurGeneral& operator=(const ControleurGeneral&) = delete;
    static ControleurGeneral& getInstance() {
        static ControleurGeneral instance;
        return instance;
    }
    CarteMarquageFaune* getCarteRegleAleatoire();
    TuileDepart* getTuilesDepartAleatoires(); // retourne un pointeur vers tableau de 3 tuiles
};*/