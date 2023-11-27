#include "header/player.hpp"

Player::Player(PlayerSkin initialSkin) : playerSkin(initialSkin) {
    initPlayer();
}

Player::~Player() {};

void Player::initPlayer() {
    std::string texturePath;
    switch (playerSkin) {
        case PlayerSkin::GREEN:
            texturePath = "../resource/Character1.png";
            break;
        case PlayerSkin::BLUE:
            texturePath = "../resource/Character2.png";
            break;
        case PlayerSkin::RED:
            texturePath = "../resource/Character3.png";
            break;
		case PlayerSkin::YELLOW:
            texturePath = "../resource/Character4.png";
            break;
		case PlayerSkin::BROWN:
            texturePath = "../resource/Character5.png";
            break;        
    }

	playerTexture.loadFromFile(texturePath);
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(sf::Vector2f(622.0f, 412.0f));
}

void Player::reset(){
	playerSprite.setPosition(638, 807);
}

sf::Sprite Player::getPlayerSprite(){
	return playerSprite;
}

void Player::move(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		playerSprite.move(movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		playerSprite.move(movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		playerSprite.move(0.f, movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		playerSprite.move(0.f, -movementSpeed);
	}
}

void Player::update(){
	
}

void Player::changeSkinRight() {
    int skinIndex = static_cast<int>(playerSkin);
    skinIndex = (skinIndex + 1) % static_cast<int>(PlayerSkin::NUM_SKINS);
    playerSkin = static_cast<PlayerSkin>(skinIndex);
	updatePlayerTexture(skinIndex);
}

void Player::changeSkinLeft() {
    int skinIndex = static_cast<int>(playerSkin);
    skinIndex = (skinIndex - 1 + static_cast<int>(PlayerSkin::NUM_SKINS)) % static_cast<int>(PlayerSkin::NUM_SKINS);
    playerSkin = static_cast<PlayerSkin>(skinIndex);
    updatePlayerTexture(skinIndex);
}

void Player::updatePlayerTexture(int index){
	playerTexture.loadFromFile("../resource/Character" + std::to_string(index+1) + ".png");
	playerSprite.setTexture(playerTexture);
}

void Player::updateWindowBoundsCollision(const sf::RenderWindow& window){
	if (this->playerSprite.getGlobalBounds().left <= 0.f)
		this->playerSprite.setPosition(0.f, this->playerSprite.getGlobalBounds().top);
	
	if (this->playerSprite.getGlobalBounds().left + this->playerSprite.getGlobalBounds().width >= window.getSize().x)
		this->playerSprite.setPosition(window.getSize().x - this->playerSprite.getGlobalBounds().width, this->playerSprite.getGlobalBounds().top);

	if (this->playerSprite.getGlobalBounds().top <= 0.f)
		this->playerSprite.setPosition(this->playerSprite.getGlobalBounds().left, 0.f);
	
	if (this->playerSprite.getGlobalBounds().top + this->playerSprite.getGlobalBounds().height >= window.getSize().y)
		this->playerSprite.setPosition(this->playerSprite.getGlobalBounds().left, window.getSize().y - this->playerSprite.getGlobalBounds().height);
}

const sf::Vector2f& Player::getPosition() const {
    return playerSprite.getPosition();
}
