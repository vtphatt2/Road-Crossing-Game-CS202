#include "header/menu.hpp"

Menu::Menu(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    backgroundTexture.loadFromFile("../resource/Menu.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, -125);
}

void Menu::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) 
            window->close();
        
    }
}

void Menu::update() {
    return ;
}

void Menu::render() {
    window->draw(backgroundImage);
}
