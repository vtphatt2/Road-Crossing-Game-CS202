#include "header/win.hpp"
#include<iostream>
Win::Win(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, sf::Texture background) : window(window), states(states), music(music), background(background) {
    window->setView(window->getDefaultView());
    initShape();
}

void Win::initShape() {
    backgroundImage.setTexture(background);
    backgroundImage.setPosition(0, 0); 
    backgroundImage.setColor(sf::Color(255, 255, 255, 90));

    boardTexture.loadFromFile("../resource/lose/Board.png");
    boardImage.setTexture(boardTexture);
    boardImage.setPosition(367, 216);  

    winTexture.loadFromFile("../resource/lose/win.png");
    winImage.setTexture(winTexture);
    winImage.setPosition(318, 44); 

    starTexture.loadFromFile("../resource/lose/star.png");
    starImage.setTexture(starTexture);
    starImage.setPosition(554, 423); 

    levelTitleTexture.loadFromFile("../resource/lose/scoreTitle.png");
    levelTitleImage.setTexture(levelTitleTexture);
    levelTitleImage.setPosition(609, 315);
    
    nextButtonTexture.loadFromFile("../resource/lose/next.png");
    nextButtonImage.setTexture(nextButtonTexture);
    nextButtonImage.setPosition(579, 677);
    nextButtonImage.setColor(sf::Color(255, 255, 255, 220));
    nextButtonRect.left = nextButtonImage.getPosition().x;  
    nextButtonRect.top = nextButtonImage.getPosition().y;  
    nextButtonRect.width = nextButtonImage.getGlobalBounds().width;
    nextButtonRect.height = nextButtonImage.getGlobalBounds().height;

    menuButtonTexture.loadFromFile("../resource/lose/menu.png");
    menuButtonImage.setTexture(menuButtonTexture);
    menuButtonImage.setPosition(719, 677);
    menuButtonImage.setColor(sf::Color(255, 255, 255, 220));
    menuButtonRect.left = menuButtonImage.getPosition().x;    
    menuButtonRect.top = menuButtonImage.getPosition().y;  
    menuButtonRect.width = menuButtonImage.getGlobalBounds().width;
    menuButtonRect.height = menuButtonImage.getGlobalBounds().height;
}

void Win::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (menuButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Menu(window, states, music));
            }
            if (nextButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                //states->push(new Character(Window, states, music));
            }
        }
    }
}

void Win::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if (nextButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        nextButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        nextButtonImage.setColor(sf::Color(255, 255, 255, 150));

    if (menuButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        menuButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        menuButtonImage.setColor(sf::Color(255, 255, 255, 200));
}

void Win::render() {
    window->draw(backgroundImage);
    window->draw(boardImage);
    window->draw(winImage);
    window->draw(starImage);
    window->draw(nextButtonImage);
    window->draw(menuButtonImage);
    window->draw(levelTitleImage);
}