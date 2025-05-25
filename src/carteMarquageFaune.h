#pragma once
#include "enum.h"
#include "controleurGeneral.h"
#include "affichable.h"
class PlateauJoueur; // Déclaration anticipée

class CarteMarquageFaune : public affichable{
private:
    Animal animalCarte;
public:
    CarteMarquageFaune(Animal a);
    ~CarteMarquageFaune();
    Animal GetAnimalCarte() {return animalCarte;}
    void afficher(std::ostream& f=std::cout ) const override{
        switch(animalCarte){
            case Animal::Aigle:
            f << "";
            break;
            case Animal::Cerf: 
            f << "";
            break; 
            case Animal::Ours:
            f<< "";
            break;
            case Animal::Renard:
            f<< "";
            break;
            case Animal::Saumon:
            f<< "";
            break;


        }
    }
    int calculPoints(PlateauJoueur&);
};

class CarteMarquageFauneParMasque : public CarteMarquageFaune {
public:
    CarteMarquageFauneParMasque(Animal a);
    ~CarteMarquageFauneParMasque();
    int calculPoints(PlateauJoueur&);
};

class CarteMarquageFauneParDiversiteDeType : public CarteMarquageFaune {//Utile pour le renard
public:
    CarteMarquageFauneParDiversiteDeType(Animal a);
    ~CarteMarquageFauneParDiversiteDeType();
    int calculPoints(PlateauJoueur&);
};