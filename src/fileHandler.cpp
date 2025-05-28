#include "fileHandler.h"

using namespace std;

bool FileHandler::loadGame(bool debug, const string& filename) { return true; }
bool FileHandler::saveGame(bool debug, const string& filename) { return true; }
static bool saveToFile(const string filename) {
    ofstream fichier(filename, ios::out); // Ouvre le fichier en �criture
    if (!fichier.is_open()) {
        cerr << "[Erreur] Impossible d'ouvrir le fichier '" << filename << "' pour l'�criture.\n";
        return false;
    }

    try {
        //!! Pour l'instant un traitement basique
        fichier << "ICI on mettra les Donn�e du programme (?)\n";
        fichier << "ICI on mettra les Donn�e du programme (?)\n";
        fichier << "ICI on mettra les Donn�e du programme (?)\n";

        if (fichier.fail()) {
            throw ios_base::failure("�chec lors de l'�criture dans le fichier.");
        }

        fichier.close();
        return true;
    }
    catch (const ios_base::failure& e) {
        cerr << "[Exception] " << e.what() << "\n";
        fichier.close();
        return false;
    }
}

static bool loadFromFile(const string filename) {
    ifstream fichier(filename, ios::in); // Ouvre le fichier en lecture
    if (!fichier.is_open()) {
        cerr << "[Erreur] Impossible d'ouvrir le fichier '" << filename << "' pour la lecture.\n";
        return false;
    }

    try {
        string ligne;
        while (getline(fichier, ligne)) {
            // Pour l'instant un traitement basique
            cout << "[Lecture] " << ligne << "\n";
        }

        if (fichier.bad()) {
            throw ios_base::failure("�chec critique lors de la lecture du fichier.");
        }

        fichier.close();
        return true;
    }
    catch (const ios_base::failure& e) {
        cerr << "[Exception] " << e.what() << "\n";
        fichier.close();
        return false;
    }
}