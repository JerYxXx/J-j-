//Travaille de Jérôme :

/* void grille::isTrue(int x,int y) {
        if (x >= 0 && x < grille.size() && y >= 0 && y < grille[0].size()){ //ici je dis juste de bien regarder dans le champs de la grille et pas au dela
            if (grille[x][y])//C'est un bool donc juste si grille x,y = true donc 1 donc vivante bah on push back les coords
            CellulesVivante.push_back({x,y});
        }
            
    }*/

//Ici je scan tout autour de la cellule considéré, puis j'appelle la fonction is true pour savoir si la cellule est vivante.
/*void grille::scanCellule(int x,int y) {
    for (int X=x-1;X<=x+1 ;X++) {
        for (int Y=y-1;Y<=y+1;Y++) {
            if (X < 0 || X >= grille.size() || Y < 0 || Y >= grille[0].size()) { //ça permet de gérer les bordures. là j'avoue j'ai utiliser le frérot
                continue;
            }
            if (X==x && Y == y) continue;
                isTrue(X,Y);
        }
    }
}*/

//Fonction pour changer l'etat d'une cellule, je pense que c'est dans cette fonction qu'on peut rajouter les règles du jeu, j'aimerais en discuter avec vous avant de le faire.

//*************************CPP GRILLE*******************************
#include "grille.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

//Travail Jérôme
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
//Travail Elsa
void grille::configurationAleatoire(double proba) {
    for (int x = 0; x < largeur; x++) {
        for (int y = 0; y < hauteur; y++) {
            cellules[x][y] = ((double)rand() / RAND_MAX) < proba;
        }
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

void grille::affichage() const {
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            cout << (cellules[x][y] ? 'O' : '.');
        }
        cout << endl;
    }
}

//************************CPP JEU*************************
//Travail Elsa
#include "jeu.h"
#include <iostream>
using namespace std;

jeu::jeu() : generation(0) {}

void jeu::jouer(grille &grille1, int iterations) {
    for (int i = 0; i < iterations; i++) {
        cout << "Génération : " << generation << endl;
        grille1.affichage();
        historique.push_back(grille1);
        grille1 = grille1.generationsuivante();
        generation++;
        cout << endl;
    }
}

int jeu::population(const grille &grille1) const {
    int nbVivantes = 0;
    for (int x = 0; x < grille1.getLargeur(); x++) {
        for (int y = 0; y < grille1.getHauteur(); y++) {
            if (grille1.isTrue(x, y)) {
                nbVivantes++;
            }
        }
    }
    return nbVivantes;
}

void jeu::retour() {
    if (!historique.empty()) {
        cout << "Grille précédente : " << endl;
        historique.back().affichage();
    } else {
        cout << "Pas de grille précédente disponible." << endl;
    }
}
