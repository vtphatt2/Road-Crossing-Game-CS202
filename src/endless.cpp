#include "header/endless.hpp"

Endless::Endless(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    setting = new Setting(window, states);
    initShape();
}

void Endless::initShape() {
    
    backgroundTexture.loadFromFile("../resource/Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);
    

}

void Endless::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
        setting->handleEvent(event);
    }
}

void Endless::update() {
    setting->update();
}

void Endless::render() {
    window->draw(backgroundImage);
    window->draw(*setting);
}