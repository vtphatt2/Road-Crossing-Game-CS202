#include "header/classic.hpp"

Classic::Classic(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();
}

void Classic::initShape() {
    backgroundTexture.loadFromFile("../resource/Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);
}

void Classic::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
    }
}

void Classic::update() {

}

void Classic::render() {
    window->draw(backgroundImage);
}