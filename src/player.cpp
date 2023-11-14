#include "header/character.hpp"
#include "header/player.hpp"


Player::Player(sf::RenderWindow* window, std::stack <State*>* states) : Character(window, states) {
    initPlayer();
}

Player::~Player() {};

int Player::getChosenCharacterIndex() const {
    return Character::getCurrentCharacterIndex();
}

void Player::initPlayer() {
    //Character::initCharacter();
    int i = getChosenCharacterIndex();
    changeCharacter("../resource/Character" + std::to_string(i + 1) + ".png");       
    character.setPosition(sf::Vector2f(638.0f, 807.0f));
}

void Player::changeCharacter(const std::string& newCharacterTexture) {
    characterText.loadFromFile(newCharacterTexture);
    character.setTexture(characterText);
}

sf::Sprite Player::getCharacter() {
    return character;
}

void Player::reset(){
	character.setPosition(638, 807);
}

void Player::move(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		character.move(-movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		character.move(movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		character.move(0.f, movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		character.move(0.f, -movementSpeed);
	}
}

void Player::update(){
	// if (clock.getElapsedTime() > time){
	// 	update();
	// 	updateWindowBoundsCollision();
	// 	clock.restart();
	// }
}

void Player::render(){
	window->draw(character);
}

void Player::updateWindowBoundsCollision(){
	if (this->character.getGlobalBounds().left <= 0.f)
		this->character.setPosition(0.f, this->character.getGlobalBounds().top);
	
	if (this->character.getGlobalBounds().left + this->character.getGlobalBounds().width >= window->getSize().x)
		this->character.setPosition(window->getSize().x - this->character.getGlobalBounds().width, this->character.getGlobalBounds().top);

	if (this->character.getGlobalBounds().top <= 0.f)
		this->character.setPosition(this->character.getGlobalBounds().left, 0.f);
	
	if (this->character.getGlobalBounds().top + this->character.getGlobalBounds().height >= window->getSize().y)
		this->character.setPosition(this->character.getGlobalBounds().left, window->getSize().y - this->character.getGlobalBounds().height);
}

void Player::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}

