#include "header/character.hpp"

Character::Character(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();
    initCharacter();
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

    backButtonTexture.loadFromFile("../resource/Back.png");
    backButtonImage.setTexture(backButtonTexture);
    backButtonImage.setPosition(27, 27);
    backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    backButtonRect.left = 27;  
    backButtonRect.top = 27;   
    backButtonRect.width = 115;
    backButtonRect.height = 116;
}

void Character::initCharacter(){
    // Load textures for all characters
    for (int i = 0; i < NUM_CHARACTERS; ++i) {
        characterTextures[i].loadFromFile("../resource/Character" + std::to_string(i + 1) + ".png");
        characterImages[i].setTexture(characterTextures[i]);
    }

    // Set the initial character
    currentCharacterIndex = 0;
    CharacterImage = characterImages[currentCharacterIndex];
    CharacterImage.setPosition(622, 412);

}

int Character::getCurrentCharacterIndex() const {
    return currentCharacterIndex;
}

void Character::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::KeyPressed) {
            // press left arrow key to turn back the previous window
            if (event.key.code == sf::Keyboard::Left) {
                states->pop();
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
    characterImages[currentCharacterIndex].setPosition(622, 412); // Adjust the coordinates accordingly
    CharacterImage = characterImages[currentCharacterIndex];

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
}

void Character::render() {
    window->draw(backgroundImage);
    window->draw(playGameButtonImage);
    window->draw(rightArrowButtonImage);
    window->draw(leftArrowButtonImage);
    window->draw(characterImages[currentCharacterIndex]);
}
