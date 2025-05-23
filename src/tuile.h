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
    virtual void associationJeton() const {}   // méthode virtuelle pour être substituée
    int getNbAnimaux() const {return nbAnimaux;}
    int getNbHabitat() const {return nbHabitat;}
    animal** getListeAnimaux() const {return listeAnimaux;}
    habitat** getListeHabitat() const {return listeHabitat;}
};

class Keystone : public Tuile {
public:
    Keystone();
    ~Keystone() override;
    // Donne un jeton keyStone à joueur si pose animal sur bonne case keyStone
    void associationJeton() const override; // Où mettre joueur ?
    // on peut mettre dans ActionPlacerJeton car dernière action du tour
};