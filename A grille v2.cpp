#include "grille.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <utility>
#include <cmath>


grille::grille(int largeur, int hauteur)
    : largeur(largeur), hauteur(hauteur) {
    cellules.resize(largeur, vector<bool>(hauteur, false));
}
grille grille::generationsuivante() {
    grille nouvelleGrille(largeur, hauteur); // Nouvelle grille qui sera retournée

    // Parcourir la grille actuelle
    for (int x = 0; x < cellules.size(); x++) {
        for (int y = 0; y < cellules[0].size(); y++) {
            int voisinsVivants = 0;

            // Parcours des voisins
            for (int X = x - 1; X <= x + 1; X++) {
                for (int Y = y - 1; Y <= y + 1; Y++) {
                    if (X >= 0 && X < cellules.size() && Y >= 0 && Y < cellules[0].size() && !(X == x && Y == y)) {
                        if (cellules[X][Y]) { // Vérifie si la cellule est vivante
                            voisinsVivants++;
                        }
                    }
                }
            }

            // Application des règles du jeu
            if (cellules[x][y]) { // Si la cellule est vivante
                if (voisinsVivants == 2 || voisinsVivants == 3) {
                    nouvelleGrille.cellules[x][y] = true; // La cellule reste vivante
                }
            } else { // Si la cellule est morte
                if (voisinsVivants == 3) {
                    nouvelleGrille.cellules[x][y] = true; // La cellule devient vivante
                }
            }
        }
    }

    return nouvelleGrille;
}

void grille::configurationAleatoire(double proba) {
    for (int x = 0; x < largeur; x++) {
        for (int y = 0; y < hauteur; y++) {
            cellules[x][y] = ((double)rand() / RAND_MAX) < proba;
        }
    }
}

void grille::importerDepuisFichier(const string &nomFichier) {
    ifstream f(nomFichier);
    if (f.good()) {
        vector<vector<bool>> nouvelleGrille;
        string ligne;

        while (getline(f, ligne)) {
            vector<bool> rangee;
            for (char c : ligne) {
                if (c == '0') rangee.push_back(false);
                else if (c == '1') rangee.push_back(true);
                else {
                    cerr << "Caractère invalide détecté dans le fichier : '" << c << "'" << endl;
                    return;
                }
            }
            if (!rangee.empty()) nouvelleGrille.push_back(rangee);
        }

        if (nouvelleGrille.empty()) {
            cerr << "Erreur : Fichier vide ou mal formaté." << endl;
            return;
        }

        // Mise à jour des dimensions et de la grille
        hauteur = nouvelleGrille.size();
        largeur = nouvelleGrille[0].size();
        cellules = nouvelleGrille;

        cout << "Configuration importée avec succès depuis " << nomFichier << " !" << endl;
    } else {
        cerr << "Problème de lecture de " << nomFichier << endl;
    }
}


bool grille::isTrue(int x, int y) const {
    return cellules[x][y];
}

void grille::changeEtat(int x, int y) {
    if (cellules[x][y]) {
        cellules[x][y] = false;
    } else cellules[x][y] = true;
}

void grille::affichage(sf::RenderWindow& window,sf::Color color) const {
    sf::Image image;
    image.create(window.getSize().x, window.getSize().y, sf::Color::Black); // Initialiser avec du noir (que des cellules mortes par exemple

    // coloriage
    for (int y = 0; y < hauteur; y++) { // Parcours des lignes (hauteur)
        for (int x = 0; x < largeur; x++) { // Parcours des colonnes (largeur)
        if (cellules[x][y] == 1 ){image.setPixel(x, y, color);}}

    // Créer une texture et un sprite pour afficher l'image (ca c'est chat gpt qui me l'a fait aussi)
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);

    // Dessiner
    window.clear();
    window.draw(sprite);
    window.display();


}}












