#pragma once
#include <initializer_list>
#include <iostream>
//Mieux d'utiliser "Animal" que "animal"
//Même chose pour "Habitat" que "habitat"
enum class Animal {
    Ours,
    Cerf,
    Saumon,
    Aigle,
    Renard
};

enum class animalOuPas {
    Vide = 0,
    Ours = 1,
    Cerf, 
    Saumon,
    Aigle,
    Renard
};

std::ostream& operator<<(std::ostream& f, const animalOuPas& animal) {
    switch (animal) {
    case animalOuPas::Vide: f << "Vide"; break;
    case animalOuPas::Ours: f << "Ours"; break;
    case animalOuPas::Cerf: f << "Cerf"; break;
    case animalOuPas::Saumon: f << "Saumon"; break;
    case animalOuPas::Aigle: f << "Aigle"; break;
    case animalOuPas::Renard: f << "Renard";break;
    }
    return f;
}

enum class Habitat {
    Montagne,
    Foret,
    Prairie,
    Marais,
    Fleuve
};

enum class presenceAnimal {
    PasRenard = -5,
    PasAigle,
    PasSaumon,
    PasCerf,
    PasOurs,
    Ours = 1,
    Cerf,
    Saumon,
    Aigle,
    Renard
};


//Quelques listes à devoirs utiliser pour

const std::initializer_list<Animal> animaux = {Animal::Aigle, Animal::Cerf, Animal::Ours, Animal::Renard, Animal::Saumon};
const std::initializer_list<Habitat> habitats = {Habitat::Fleuve, Habitat::Foret, Habitat::Marais, Habitat::Montagne, Habitat::Prairie};
