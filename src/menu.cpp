#include "header/menu.hpp"

Menu::Menu(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    backgroundTexture.loadFromFile("../resource/Menu.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, -125);
    this->initRectChoice();
}

void Menu::initRectChoice() {
    for (int i = 0 ; i < 5 ; ++i) {
        rectChoices[i].setOutlineThickness(2);
        rectChoices[i].setOutlineColor(sf::Color::Red);
        rectChoices[i].setFillColor(sf::Color::Transparent);  
        rectChoices[i].setSize(sf::Vector2f(465, 85));      
    }

    rectChoices[0].setPosition(483, 207);
    rectChoices[1].setPosition(483, 309);
    rectChoices[2].setPosition(483, 411);
    rectChoices[3].setPosition(483, 513);
    rectChoices[4].setPosition(483, 615);
}

void Menu::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
            for (int i = 0 ; i < 5 ; ++i) {
                if (rectChoices[i].getGlobalBounds().contains(sf::Vector2f(mousePosition))) 
                    rectChoice = rectChoices[i];
            }
        }
    }
}

void Menu::update() {
}

void Menu::render() {
    window->draw(backgroundImage);
    window->draw(rectChoice);
}
