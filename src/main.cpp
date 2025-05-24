#include <iostream>
#include "carteMarquageFaune.h"

int main() {

    unsigned int monChoix;
    cout<<"Bienvenur à notre jeu Cascadia!\n";
    cout<<"Voici les choix: \n";
    cout<<"Choix 0: Démarrer le jeu.\n";
    cout<<"Choix 1: Arrêter le jeu.\n";
    cout<<"Quel est votre choix ?\n";
    cout<<"Voitre choix: \n";
    cin>>monChoix;
    switch(monChoix){
        case 0: 
        cout<<"Le jeu va démarrer!\n";
        int nbJoueurs;
        cout<<"Vous êtes combien de joueurs?\n";
        cin>>nbJoueurs;
        break;
        case 1: 
        cout<<"Arrêt du jeu\n";
        cout<<"Voici votre score: \n";
        break;
        default: 
        cout<<"Arrêt du jeu\n";
    }
    return 0;
}
