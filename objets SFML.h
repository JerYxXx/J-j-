#ifndef OBJETS_SFML_H_INCLUDED
#define OBJETS_SFML_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button(float x, float y, float width, float height,
           const std::string& buttonText, const sf::Font& font,
           sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

    bool isHovered(const sf::Vector2i& mousePos) const;
    bool isClicked(const sf::Vector2i& mousePos, sf::Mouse::Button button) const;
    void update(const sf::Vector2i& mousePos);
    void render(sf::RenderTarget& target);
};


#endif // OBJETS_SFML_H_INCLUDED
