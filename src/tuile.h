#pragma once
#include <iostream>
#include <string>
#include "enum.h"
#include "affichable.h"
#include <random>



class Tuile {
private:
    unsigned int nbAnimaux;
    unsigned int nbHabitat;
    Animal** listeAnimaux;
    Habitat** listeHabitat;

public:
    Tuile() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist3(1, 3);
        std::uniform_int_distribution<> dist5(0, 4);

        nbHabitat = dist3(gen);
        nbAnimaux = dist3(gen);

        listeAnimaux = new Animal*[nbAnimaux];
        listeHabitat = new Habitat*[nbHabitat];

        for (unsigned int i = 0; i < nbAnimaux; ++i) {
            unsigned int unAnimal = dist5(gen);
            listeAnimaux[i] = new Animal(*(std::next(animaux.begin(), unAnimal)));
        }

        for (unsigned int i = 0; i < nbHabitat; ++i) {
            unsigned int unHabitat = dist5(gen);
            listeHabitat[i] = new Habitat(*(std::next(habitats.begin(), unHabitat)));
        }
    }

    ~Tuile();

    bool contientAnimal(const Animal& a) const;

    int getNbHabitat() const { return nbHabitat; }
    int getNbAnimaux() const { return nbAnimaux; }
    void afficherTuile(std::ostream& f = std::cout) const {
        f << "Tuile avec " << nbAnimaux << " animaux et " << nbHabitat << " habitats.\n";
        f << "Animaux : ";
        for (unsigned int i = 0; i < nbAnimaux; ++i) {
            f << listeAnimaux[i] << " ";
        }
        f << "\nHabitats : ";
        for (unsigned int i = 0; i < nbHabitat; ++i) {
            f << listeHabitat[i] << " ";
        }
        f << std::endl;
    }

    bool contientAnimal(const std::string& animal) const;
};





/*class Keystone : public Tuile {
public:
    Keystone();
    ~Keystone() override;
    // Donne un jeton keyStone à joueur si pose animal sur bonne case keyStone
    void associationJeton() const override; // Où mettre joueur ?
    // on peut mettre dans ActionPlacerJeton car dernière action du tour
};*/