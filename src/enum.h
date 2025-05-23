#pragma once
#include <initialize_list>
//Mieux d'utiliser "Animal" que "animal"
//Même chose pour "Habitat" que "habitat"
enum class animal {
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