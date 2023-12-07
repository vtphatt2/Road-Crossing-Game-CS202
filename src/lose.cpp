#include "header/lose.hpp"
#include<iostream>
Lose::Lose(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music) : window(window), states(states), music(music) {
    window->setView(window->getDefaultView());
    initShape();
}

void Lose::initShape() {
    boardTexture.loadFromFile("../resource/lose/Board.png");
    boardImage.setTexture(boardTexture);
    boardImage.setPosition(367, 216);  

    loseTexture.loadFromFile("../resource/lose/lose.png");
    loseImage.setTexture(loseTexture);
    loseImage.setPosition(318, 44);   
    
    restartButtonTexture.loadFromFile("../resource/lose/restart.png");
    restartButtonImage.setTexture(restartButtonTexture);
    restartButtonImage.setPosition(554, 677);
    restartButtonImage.setColor(sf::Color(255, 255, 255, 220));
    restartButtonRect.left = restartButtonImage.getPosition().x;  
    restartButtonRect.top = restartButtonImage.getPosition().y;  
    restartButtonRect.width = restartButtonImage.getGlobalBounds().width;
    restartButtonRect.height = restartButtonImage.getGlobalBounds().height;

    menuButtonTexture.loadFromFile("../resource/lose/menu.png");
    menuButtonImage.setTexture(menuButtonTexture);
    menuButtonImage.setPosition(707, 677);
    menuButtonImage.setColor(sf::Color(255, 255, 255, 220));
    menuButtonRect.left = menuButtonImage.getPosition().x;    
    menuButtonRect.top = menuButtonImage.getPosition().y;  
    menuButtonRect.width = menuButtonImage.getGlobalBounds().width;
    menuButtonRect.height = menuButtonImage.getGlobalBounds().height;
}

void Lose::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (menuButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Menu(window, states, music));
            }
            if (restartButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Character(window, states, music));
            }
        }
    }
}

void Lose::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if (restartButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        restartButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        restartButtonImage.setColor(sf::Color(255, 255, 255, 150));

    if (menuButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        menuButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        menuButtonImage.setColor(sf::Color(255, 255, 255, 200));
}

void Lose::render() {
    window->draw(boardImage);
    window->draw(loseImage);
    window->draw(restartButtonImage);
    window->draw(menuButtonImage);
}