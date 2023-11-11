#include "header/character.hpp"

Character::Character(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();
}

void Character::initShape() {
    backgroundTexture.loadFromFile("../resource/BackgroundCharacter.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    playGameButtonTexture.loadFromFile("../resource/Play_Game_Button.png");
    playGameButtonImage.setTexture(playGameButtonTexture);
    playGameButtonImage.setPosition(1290, 850);
    playGameButtonImage.setColor(sf::Color(255, 255, 255, 220));
    playGameButtonRect.left = playGameButtonImage.getPosition().x; 
    playGameButtonRect.top = playGameButtonImage.getPosition().y;
    playGameButtonRect.width = playGameButtonImage.getGlobalBounds().width;
    playGameButtonRect.height = playGameButtonImage.getGlobalBounds().height;

    rightArrowButtonTexture.loadFromFile("../resource/Right_Arrow.png");
    rightArrowButtonImage.setTexture(rightArrowButtonTexture);
    rightArrowButtonImage.setPosition(940, 565);
    rightArrowButtonImage.setColor(sf::Color(255, 255, 255, 220));
    rightArrowButtonRect.left = rightArrowButtonImage.getPosition().x;  
    rightArrowButtonRect.top = rightArrowButtonImage.getPosition().y; 
    rightArrowButtonRect.width = rightArrowButtonImage.getGlobalBounds().width;
    rightArrowButtonRect.height = rightArrowButtonImage.getGlobalBounds().height;

    leftArrowButtonTexture.loadFromFile("../resource/Left_Arrow.png");
    leftArrowButtonImage.setTexture(leftArrowButtonTexture);
    leftArrowButtonImage.setPosition(460, 565);
    leftArrowButtonImage.setColor(sf::Color(255, 255, 255, 220));
    leftArrowButtonRect.left = leftArrowButtonImage.getPosition().x;  
    leftArrowButtonRect.top = leftArrowButtonImage.getPosition().y; 
    leftArrowButtonRect.width = leftArrowButtonImage.getGlobalBounds().width;
    leftArrowButtonRect.height = leftArrowButtonImage.getGlobalBounds().height;

    // Load textures for all characters
    for (int i = 0; i < NUM_CHARACTERS; ++i) {
        characterTextures[i].loadFromFile("../resource/Character" + std::to_string(i + 1) + ".png");
        characterImages[i].setTexture(characterTextures[i]);
    }

    // Set the initial character
    currentCharacterIndex = 0;
    CharacterImage = characterImages[currentCharacterIndex];
    CharacterImage.setPosition(620, 410);

    backButtonTexture.loadFromFile("../resource/Back_Button.png");
    backButtonImage.setTexture(backButtonTexture);
    backButtonImage.setPosition(20, 20);
    backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    backButtonRect.left = backButtonImage.getPosition().x;
    backButtonRect.top = backButtonImage.getPosition().y;
    backButtonRect.width = backButtonImage.getGlobalBounds().width;
    backButtonRect.height = backButtonImage.getGlobalBounds().height;
}

void Character::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window->close();
            }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            // Check if the right arrow button is clicked
            if (rightArrowButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                changeCharacterRight();
            }
            // Check if the left arrow button is clicked
            else if (leftArrowButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                changeCharacterLeft();
            }
            else if (playGameButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Mode(window, states));
            }
            else if (backButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->pop();
            }
        }
    }
}

void Character::changeCharacterRight() {
    currentCharacterIndex = (currentCharacterIndex + 1) % NUM_CHARACTERS;
    update();
}

void Character::changeCharacterLeft() {
    currentCharacterIndex = (currentCharacterIndex - 1 + NUM_CHARACTERS) % NUM_CHARACTERS;
    update();
}

void Character::update() {
    characterImages[currentCharacterIndex].setPosition(620, 410); // Adjust the coordinates accordingly
    CharacterImage = characterImages[currentCharacterIndex];

    if (rightArrowButtonRect.contains(sf::Mouse::getPosition(*window))) {
        rightArrowButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        rightArrowButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }

    if (leftArrowButtonRect.contains(sf::Mouse::getPosition(*window))) {
        leftArrowButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        leftArrowButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }

    if (playGameButtonRect.contains(sf::Mouse::getPosition(*window))) {
        playGameButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        playGameButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(backButtonRect.contains(sf::Mouse::getPosition(*window))){
        backButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
}

void Character::render() {
    window->draw(backgroundImage);
    window->draw(playGameButtonImage);
    window->draw(rightArrowButtonImage);
    window->draw(leftArrowButtonImage);
    window->draw(characterImages[currentCharacterIndex]);
    window->draw(backButtonImage);
}
