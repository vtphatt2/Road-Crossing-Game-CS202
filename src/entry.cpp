#include "header/entry.hpp"
#include <iostream>

entry::entry(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    backgroundTexture.loadFromFile("../resource/Splash_Screen.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, -70);

    playButtonTexture.loadFromFile("../resource/Play_Button.png");
    playButtonImage.setTexture(playButtonTexture);
    playButtonImage.setPosition(673, 636);
    playButtonImage.setColor(sf::Color(255, 255, 255, 220));
    playButtonRect.left = 673;  
    playButtonRect.top = 636;   
    playButtonRect.width = 84;
    playButtonRect.height = 84;
}

void entry::handleEvent() {
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed :
                window->close();
                break ;
                
            case sf::Event::MouseButtonPressed :
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
                    if (playButtonRect.contains(mousePosition)) {
                        states->push(new Menu(window, states));
                    }
                }
                
            default :
                break ;
        }
    }
}

void entry::update() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    if (playButtonRect.contains(mousePosition)) {
        playButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } 
    else {
        playButtonImage.setColor(sf::Color(255, 255, 255, 200));
    }
    return ;
}

void entry::render() {
    window->draw(backgroundImage);
    window->draw(playButtonImage);
}
