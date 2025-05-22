#pragma once
#include <iostream>
#include <string>
#include "enum.h"


class Tuile {
private:
    const int nbAnimaux;
    const int nbHabitat;
    animal** listeAnimaux;
    habitat** listeHabitat;
public:
    Tuile();
    virtual ~Tuile();   // destructeur virtuel pour le polymorphisme
    virtual void AssociationJeton() const {}   // méthode virtuelle pour être substituée
    int GetNbAnimaux() const {return nbAnimaux;}
    int GetNbHabitat() const {return nbHabitat;}
    animal** GetListeAnimaux() const {return listeAnimaux;}
    habitat** GetListeHabitat() const {return listeHabitat;}
};

class Keystone : public Tuile {
public:
    Keystone();
    ~Keystone() override; // override rend explicite la substitution
    void AssociationJeton() const override; //Est-ce qu'on met joueur en paramètre ?
};