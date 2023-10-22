#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Road Crossing Game");

    sf::Font font;
    if (!font.loadFromFile("../Resource/Arial.ttf")) {
        return -1;
    }
    sf::Text text("CS202 - Programming System", font, 30);
    text.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.draw(text);
        window.display();
    }
    return 0;
}
