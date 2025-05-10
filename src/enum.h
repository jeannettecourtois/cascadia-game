#pragma once

enum class animal {
    Ours = 1,
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

enum class habitat {
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