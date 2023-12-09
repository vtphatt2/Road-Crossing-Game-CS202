#include "header/character.hpp"
#include "header/player.hpp"

class Player;

Character::Character(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player) : window(window), states(states), player(player), music(music){
    initShape();
    player->initPlayer();
}

void Character::initShape() {
    backgroundTexture.loadFromFile("../resource/BackgroundCharacter.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    playGameButtonTexture.loadFromFile("../resource/Play_Game_Button.png");
    playGameButtonImage.setTexture(playGameButtonTexture);
    playGameButtonImage.setPosition(1278, 856);
    playGameButtonImage.setColor(sf::Color(255, 255, 255, 220));
    playGameButtonRect.left = 1278;  
    playGameButtonRect.top = 856;   
    playGameButtonRect.width = 113;
    playGameButtonRect.height = 113;

    rightArrowButtonTexture.loadFromFile("../resource/Right_Arrow.png");
    rightArrowButtonImage.setTexture(rightArrowButtonTexture);
    rightArrowButtonImage.setPosition(941, 565);
    rightArrowButtonImage.setColor(sf::Color(255, 255, 255, 220));
    rightArrowButtonRect.left = 941;  
    rightArrowButtonRect.top = 565;   
    rightArrowButtonRect.width = 58;
    rightArrowButtonRect.height = 58;

    leftArrowButtonTexture.loadFromFile("../resource/Left_Arrow.png");
    leftArrowButtonImage.setTexture(leftArrowButtonTexture);
    leftArrowButtonImage.setPosition(438, 565);
    leftArrowButtonImage.setColor(sf::Color(255, 255, 255, 220));
    leftArrowButtonRect.left = 438;  
    leftArrowButtonRect.top = 565;   
    leftArrowButtonRect.width = 58;
    leftArrowButtonRect.height = 58;

    backButtonTexture.loadFromFile("../resource/Back_Button.png");
    backButtonImage.setTexture(backButtonTexture);
    backButtonImage.setPosition(27, 27);
    backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    backButtonRect.left = 27;  
    backButtonRect.top = 27;   
    backButtonRect.width = 115;
    backButtonRect.height = 116;
}

void Character::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (rightArrowButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                player->changeSkinRight();
            }
            else if (leftArrowButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                player->changeSkinLeft();
            }
            else if (playGameButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Mode(window, states, player, music));
            }
            else if (backButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->pop();
            }
        }
    }
}

void Character::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if (rightArrowButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        rightArrowButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        rightArrowButtonImage.setColor(sf::Color(255, 255, 255, 150));

    if (leftArrowButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        leftArrowButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        leftArrowButtonImage.setColor(sf::Color(255, 255, 255, 150));

    if (playGameButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        playGameButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        playGameButtonImage.setColor(sf::Color(255, 255, 255, 200));
    
    if (backButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        backButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        backButtonImage.setColor(sf::Color(255, 255, 255, 200));
}

void Character::render() {
    window->draw(backgroundImage);
    window->draw(playGameButtonImage);
    window->draw(rightArrowButtonImage);
    window->draw(leftArrowButtonImage);
    window->draw(player->getPlayerSprite());
    window->draw(backButtonImage);
}
