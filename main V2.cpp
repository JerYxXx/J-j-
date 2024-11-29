#include "grille.h"
#include "jeu.h"
#include <iostream>
using namespace std;

void menuPrincipal() {
    int largeur, hauteur, iterations;
    double proba;
    char choix;
    grille maGrille(0, 0);

    cout << "Bienvenue dans le Jeu de la Vie !" << endl;

    cout << "Souhaitez-vous :\n"
         << "1. Une configuration aléatoire\n"
         << "2. Importer une configuration depuis un fichier\n"
         << "Votre choix (1/2) : ";
    cin >> choix;

    if (choix == '1') {
        cout << "Entrez la largeur de la grille : ";
        cin >> largeur;
        cout << "Entrez la hauteur de la grille : ";
        cin >> hauteur;

        maGrille = grille(largeur, hauteur);

        cout << "Entrez la probabilité d'une cellule vivante (entre 0 et 1) : ";
        cin >> proba;
        maGrille.configurationAleatoire(proba);
    } else if (choix == '2') {
        string nomFichier;
        cout << "Entrez le nom du fichier (ex: grille.txt) : ";
        cin >> nomFichier;

        //maGrille.importerDepuisFichier(nomFichier);
        //largeur = maGrille.getLargeur();
        //hauteur = maGrille.getHauteur();
    } else {
        cerr << "Choix invalide !" << endl;
        return;
    }

    cout << "Entrez le nombre d'itérations : ";
    cin >> iterations;

    jeu monJeu;
    monJeu.jouer(maGrille, iterations);
}

int main() {
    system("chcp 1252");
    srand(time(0));
    menuPrincipal();
    return 0;
}
