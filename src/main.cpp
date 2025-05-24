#include <iostream>
#include "carteMarquageFaune.h"

using namespace std;
int main() {
     
    cout<<"Bienvenu sur notre jeu Cascadia! \n";
    cout<<"Entrez votre choix 0, 1, 2 pour commencer: \n";
    cout<<"Choix 0: Commencer le  jeu. \n";
    cout<<"Choix 1: Sortir du jeu. \n";
    int monChoix;
    cout<<"Votre choix: \n";
    cin>>monChoix;

    switch(monChoix){
        case 0:
        "Démarrage du jeu.\n";
        break;
        case 1: 
        "Fin du jeu.\n";
        break;
    }
    return 0;
}
