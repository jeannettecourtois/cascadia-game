#pragma once
#include "enum.h"
#include "controleurGeneral.h"
#include "affichable.h"
class PlateauJoueur; // Déclaration anticipée

class CarteMarquageFaune : public affichable{
private:
    Animal animalCarte;
public:
    CarteMarquageFaune(Animal a) : animalCarte(a){};
    ~CarteMarquageFaune();
    Animal GetAnimalCarte() {return animalCarte;}
    void afficher(std::ostream& f=std::cout ) const override{
        switch(animalCarte){
            case Animal::Aigle:
            f << "Les buses marquent des points individuellement, en paire, ou par ligne de vue (champ de vision) selon leur position et les autres buses visibles ou absentes.\n";
            break;
            case Animal::Cerf: 
            f << "Les wapitis marquent des points en formant des groupes selon des formes précises illustrées, et un même wapiti ne peut servir qu’un seul groupe à la fois.\n";
            break; 
            case Animal::Ours:
            f<< "Les ours rapportent des points si vous formez des groupes de taille exacte selon les cartes, sans qu’ils soient adjacents entre eux.\n";
            break;
            case Animal::Renard:
            f<< "Les renards marquent des points selon les types, les paires ou les quantités d’animaux différents (hors renards) directement adjacents à eux.";
            break;
            case Animal::Saumon:
            f<< "Les saumons marquent des points en formant des migrations de 1 à 7 saumons, où chaque saumon est adjacent à un ou deux autres maximum.\n";
            break;

            default: 
            f<<"Carte famille\n";


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