//c'est la partie importante du code, ici comme j'arrive pas a utiliser vos fonctions j'ai demandé à chat GPT de me générer un tableau pour faire la démonstration,

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;


// Fonction pour générer les coordonnées selon une suite, ne pas mettre dans le propgramme final, c'est chat gpt qui l'a fait pour moi (jusqua ligne 27)
vector<pair<int, int>> generateSequence(int step, int windowWidth, int windowHeight) {
    vector<pair<int, int>> coordinates;

    // Exemple : Génération selon une spirale
    const int numPoints = 100; // Nombre de points générés par étape
    for (int i = 0; i < numPoints; ++i) {
        float angle = 0.1f * (i + step); // Augmentation de l'angle pour créer la spirale
        float radius = 5.0f * (i + step) / numPoints; // Rayonnement de la spirale
        int x = static_cast<int>(windowWidth / 2 + radius * std::cos(angle));
        int y = static_cast<int>(windowHeight / 2 + radius * std::sin(angle));

        // Ajouter les coordonnées seulement si elles sont dans la fenêtre
        if (x >= 0 && x < windowWidth && y >= 0 && y < windowHeight) {
            coordinates.emplace_back(x, y);
        }
    }
    return coordinates;
}

// Fonction pour afficher les pixels
void affiche(sf::RenderWindow& window, const std::vector<std::pair<int, int>>& coordonee, sf::Color color) {
    // Creer une image pour uilisier directement les pixels
    sf::Image image;
    image.create(window.getSize().x, window.getSize().y, sf::Color::Black); // Initialiser avec du noir (que des cellules mortes par exemple

    // coloriage
    for (const auto& coord : coordonee) {
        image.setPixel(coord.first, coord.second, color);
    }

    // Créer une texture et un sprite pour afficher l'image (ca c'est chat gpt qui me l'a fait aussi)
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);

    // Dessiner
    window.clear();
    window.draw(sprite);
    window.display();
}

int main() {
    // Dimensions de la fenêtre
    const int largeur = 1000;
    const int hauteur =1000;

    // Créer une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(largeur, hauteur), "Animation de Pixels");

    int step = 0; // Étape de l'itération de la suite
    sf::Clock clock; // Horloge pour gérer le temps

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Mise à jour de l'état toutes les 1ms
        if (clock.getElapsedTime().asMilliseconds() > 1) {
            // Générer les coordonnées selon la suite chat gpt !!!! important c'est la qu'on doit mettre la grille (les cellules vivantes)
            std::vector<std::pair<int, int>> coordonees = generateSequence(step, largeur, hauteur);

            // Afficher les pixels
            affiche(window, coordonees, sf::Color::Red);
            step++;
            clock.restart();
        }
    }

    return 0;
}
