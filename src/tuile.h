#pragma once
#include "enum.h"


class Tuile {
private:
    const int nbAnimaux;
    const int nbHabitat;
    animal** listeAnimaux;
    habitat** listeHabitat;
public:
    Tuile();
    ~Tuile();
    void AssociationJeton() const {}
    int GetNbAnimaux() const {return nbAnimaux;}
    int GetNbHabitat() const {return nbHabitat;}
    animal** GetListeAnimaux() const {return listeAnimaux;}
    habitat** GetListeHabitat() const {return listeHabitat;}
};

class Keystone : public Tuile {
public:
    void AssociationJeton() const; //Est-ce qu'on met joueur en paramètre ?
};