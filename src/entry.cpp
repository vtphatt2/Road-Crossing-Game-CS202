#include "header/entry.hpp"
#include "header/game.hpp"


Entry::Entry(sf::RenderWindow* window, std::stack <State*>* states, sf::Music &music, Player* player) : window(window), states(states), music(music), player(player) {
    initShape();
}

void Entry::initShape() {
    backgroundTexture.loadFromFile("../resource/Entry_Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    playButtonTexture.loadFromFile("../resource/Play_Button.png");
    playButtonImage.setTexture(playButtonTexture);
    playButtonImage.setPosition(674, 620);
    playButtonImage.setColor(sf::Color(255, 255, 255, 220));
}

void Entry::handleEvent() {
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed :
                window->close();
                break ;
                
            case sf::Event::MouseButtonPressed :
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mousePosition = sf::Mouse::getPosition(*window);
                    if (playButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        states->push(new Menu(window, states, music, player));
                    }
                }
                break ;
            case sf::Event::KeyPressed :
                if (event.key.code == sf::Keyboard::Escape) {
                    window->close();
                }
                break ;
            default :
                break ;
        }
    }
}

void Entry::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if (playButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
        playButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } 
    else {
        playButtonImage.setColor(sf::Color(255, 255, 255, 200));
    }
}

void Entry::render() {
    window->draw(backgroundImage);
    window->draw(playButtonImage);
}
