#ifndef GRILLE_H_INCLUDED
#define GRILLE_H_INCLUDED

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <utility>
#include <cmath>
using namespace std;

class grille {
private:
    int largeur, hauteur;
    vector<vector<bool>> cellules;

public:
    grille(int largeur, int hauteur);
    void configurationAleatoire(double proba);
    void importerDepuisFichier(const string &nomFichier);
    bool isTrue(int x, int y) const;
    void changeEtat(int x, int y);
    int scanCellule(int x, int y) const; // Compte les voisins vivants
    void affichage(sf::RenderWindow& window,sf::Color color) const;
    grille generationsuivante();
    int getLargeur() const { return largeur; }
    int getHauteur() const { return hauteur; }
};


#endif // GRILLE_H_INCLUDED
