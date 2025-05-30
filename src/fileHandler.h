#pragma once

#include <string>
#include <iostream>
#include <fstream>  // pour la gestion des fichiers

/* Pour l'instant g�re un ajout tr�s simple de donn�es dans un txt :
    - Pourrait valoir le coup de passer � un csv ou json*/

using namespace std;

class FileHandler {
public:
    bool loadGame(bool debug, const string& filename = "save.txt");
    bool saveGame(bool debug, const string& filename = "save.txt");
    bool saveToFile(const string& filename = "save.txt");
    bool loadFromFile(const string& filename = "save.txt");
};

static string askFilename() {
    return "save.txt";
}

bool askLoadGame() {
    string input;
    while (true) {
        cout << "Voulez-vous charger une partie sauvegard�e ? (y/n) : ";
        cin >> input;
        if (input == "y" || input == "Y") return true;
        else if (input == "n" || input == "N") return false;
        else cout << "R�ponse invalide, veuillez entrer 'y' ou 'n'." << endl;
    }
}

static int askNumberOfPlayers() {
    int nbPlayers = -1;
    while (nbPlayers < 0 || nbPlayers > 4) {
        cout << "Combien de joueurs ? (1 � 4) : ";
        cin >> nbPlayers;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Entr�e invalide, veuillez entrer un nombre entre 1 et 4 inclus." << endl;
            nbPlayers = -1;
        }
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // nettoyage buffer
    return nbPlayers;
}