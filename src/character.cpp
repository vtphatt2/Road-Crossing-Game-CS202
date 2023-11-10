#include "header/character.hpp"

Character::Character(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();
}

void Character::initShape() {
    backgroundTexture.loadFromFile("../resource/BackgroundCharacter.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, -125);

    playGameButtonTexture.loadFromFile("../resource/Play_Game_Button.png");
    playGameButtonImage.setTexture(playGameButtonTexture);
    playGameButtonImage.setPosition(1278, 650);
    playGameButtonImage.setColor(sf::Color(255, 255, 255, 220));
    playGameButtonRect.left = 1278;  
    playGameButtonRect.top = 650;   
    playGameButtonRect.width = 113;
    playGameButtonRect.height = 113;

    rightArrowButtonTexture.loadFromFile("../resource/Right_Arrow.png");
    rightArrowButtonImage.setTexture(rightArrowButtonTexture);
    rightArrowButtonImage.setPosition(941, 430);
    rightArrowButtonImage.setColor(sf::Color(255, 255, 255, 220));
    rightArrowButtonRect.left = 941;  
    rightArrowButtonRect.top = 430;   
    rightArrowButtonRect.width = 58;
    rightArrowButtonRect.height = 58;

    leftArrowButtonTexture.loadFromFile("../resource/Left_Arrow.png");
    leftArrowButtonImage.setTexture(leftArrowButtonTexture);
    leftArrowButtonImage.setPosition(438, 430);
    leftArrowButtonImage.setColor(sf::Color(255, 255, 255, 220));
    leftArrowButtonRect.left = 438;  
    leftArrowButtonRect.top = 430;   
    leftArrowButtonRect.width = 58;
    leftArrowButtonRect.height = 58;

    // Load textures for all characters
    for (int i = 0; i < NUM_CHARACTERS; ++i) {
        characterTextures[i].loadFromFile("../resource/Character" + std::to_string(i + 1) + ".png");
        characterImages[i].setTexture(characterTextures[i]);
    }

    // Set the initial character
    currentCharacterIndex = 0;
    CharacterImage = characterImages[currentCharacterIndex];
    CharacterImage.setPosition(622, 300);

}

void Character::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
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
    characterImages[currentCharacterIndex].setPosition(622, 300); // Adjust the coordinates accordingly
    CharacterImage = characterImages[currentCharacterIndex];
}

void Character::render() {
    window->draw(backgroundImage);
    window->draw(playGameButtonImage);
    window->draw(rightArrowButtonImage);
    window->draw(leftArrowButtonImage);
    window->draw(characterImages[currentCharacterIndex]);
}
