#include <SFML/Graphics.hpp>
#include <iostream>
#include "objets SFML.h"

// Constructeur
Button::Button(float x, float y, float width, float height,
               const std::string& buttonText, const sf::Font& font,
               sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->shape.setPosition(sf::Vector2f(x-width/2.0f, y-height/2.0f));
    this->shape.setSize(sf::Vector2f(width, height));
    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);

    this->font = font;
    this->text.setFont(this->font);
    this->text.setString(buttonText);
    this->text.setCharacterSize(20); // Taille du texte
    this->text.setFillColor(sf::Color::White);

    // Centrer le texte sur le bouton
    sf::FloatRect textBounds = this->text.getLocalBounds();
    this->text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                         textBounds.top + textBounds.height / 2.0f);
    this->text.setPosition(
        this->shape.getPosition().x + this->shape.getSize().x / 2.0f,
        this->shape.getPosition().y + this->shape.getSize().y / 2.0f
    );
}

// Vérifie si la souris survole le bouton
bool Button::isHovered(const sf::Vector2i& mousePos) const {
    return this->shape.getGlobalBounds().contains(sf::Vector2f(mousePos));
}

// Vérifie si le bouton est cliqué
bool Button::isClicked(const sf::Vector2i& mousePos, sf::Mouse::Button button) const {
    return isHovered(mousePos) && sf::Mouse::isButtonPressed(button);
}

// Mise à jour des couleurs du bouton selon l'état
void Button::update(const sf::Vector2i& mousePos) {
    if (isHovered(mousePos)) {
        this->shape.setFillColor(this->hoverColor);
    } else {
        this->shape.setFillColor(this->idleColor);
    }
}

// Dessine le bouton sur le rendu cible
void Button::render(sf::RenderTarget& target) {
    target.draw(this->shape);
    target.draw(this->text);
}
