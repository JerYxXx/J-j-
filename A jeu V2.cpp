#include "jeu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

jeu::jeu() : generation(0) {}


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

void jeu::jouer(grille &grille1, int iterations) {
    sf::RenderWindow window(sf::VideoMode(grille1.getLargeur(), grille1.getHauteur()), "Animation de Pixels");

    for (int i = 0; i < iterations; i++) {
        if (!window.isOpen()) {
            break;  // Si la fenêtre est fermée avant la fin des itérations, on quitte la boucle
        }

        cout << "Génération : " << generation << endl;
        sf::Clock clock; // Horloge pour gérer le temps
        clock.restart();

        // Boucle principale pour gérer les événements et afficher les pixels
        while (clock.getElapsedTime().asMilliseconds() < 50 && window.isOpen()) {
            sf::Event event;
            // Traitement des événements
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();  // Ferme la fenêtre si l'événement de fermeture est détecté
                }
            }
        }

        // Affichage des pixels après l'attente de 50 ms
        grille1.affichage(window, sf::Color::Red);

        // Afficher le nombre de cellules vivantes
        cout << "Nombre de cellules vivantes : " << population(grille1);

        // Mettre à jour l'historique des générations
        historique.push_back(grille1);

        // Calculer la génération suivante
        grille1 = grille1.generationsuivante();
        generation++;

        // Rafraîchir la fenêtre
        window.display();

        cout << endl;
    }
}


/*
void jeu::retour() {
    if (!historique.empty()) {
        cout << "Grille précédente : " << endl;
        historique.back().affichage();
    } else {
        cout << "Il n'y a pas de grille précédente disponible." << endl;
    }
}*/
