#include "header/player.hpp"
#include <cmath>

Player::Player(PlayerSkin initialSkin) : playerSkin(initialSkin) {
    initPlayer();
	initMoveVariable();
	aniTime.restart();
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
	playerSprite.setPosition(622, 412);
}

void Player::resetPos(){
	playerSprite.setPosition(668, 816);
}

void Player::renderInGame(){
	std::string texturePath;
    switch (playerSkin) {
        case PlayerSkin::GREEN:
            texturePath = "../resource/player/movingGreen.png";
            break;
        case PlayerSkin::BLUE:
            texturePath = "../resource/player/movingBlue.png";
            break;
        case PlayerSkin::RED:
            texturePath = "../resource/player/alienPink.png";
            break;
		case PlayerSkin::YELLOW:
            texturePath = "../resource/player/alienYellow.png";
            break;
		case PlayerSkin::BROWN:
            texturePath = "../resource/player/alienBeige.png";
            break;        
    }
	playerTexture.loadFromFile("../resource/player/movingBlue.png");
    playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(5,0,65.2,91.8));
	playerSprite.setPosition(668, 816);
}

sf::Sprite Player::getPlayerSprite(){
	return playerSprite;
}
/*
void Player::move() {
	sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		//playerSprite.move(-movementSpeed, 0.f);
		movement.x -= movementSpeed;
		isMoving = true;
		turnLeft = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			playerSprite.move(0.f, -movementSpeed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			playerSprite.move(0.f, movementSpeed);
		}

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		playerSprite.move(movementSpeed, 0.f);
		isMoving = true;
		turnLeft = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			playerSprite.move(0.f, -movementSpeed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			playerSprite.move(0.f, movementSpeed);
		}
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		playerSprite.move(0.f, movementSpeed);
		isMoving = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		playerSprite.move(0.f, -movementSpeed);
		isMoving = true;
    } else {
        isMoving = false;
    }
}
*/

void Player::move(int direction) {
    sf::Vector2f movement(0.f, 0.f);

    switch (direction) {
        case 1: // Up
            movement.y -= movementSpeed;
            isMoving = false;
			isUp = true;
            break;
        case 2: // Down
            movement.y += movementSpeed;
            isMoving = false;
			isUp = true;
            break;
        case 3: // A (left)
            movement.x -= movementSpeed;
            isMoving = true;
            turnLeft = true;
			isUp = false;
            break;
        case 4: // D (right)
			movement.x += movementSpeed;
            isMoving = true;
            turnLeft = false;
			isUp = false;
            break;
        default:
			movement.x = 0.f;
            movement.y = 0.f;
            isMoving = false;
            turnLeft = false;
			isUp = false;
            break;
    }

    playerSprite.move(movement.x, movement.y);
}

void Player::updateAnimation(int direction){
	if (aniTime.getElapsedTime().asSeconds() >= 0.2f){
		if (moveNum >= 3) moveNum = 1;
		if (isMoving == false && isUp == false){
			moveNum = 1;
			preHeight = 0.f;
			width = 65.f;
			preWidth = 5.f;
		}
		else if (isMoving == true){
			preHeight = 190.f;
			width = 66.f;
			switch (this->moveNum)
			{
			case 1: preWidth = 1.f;
				break;
			case 2: preWidth = 71.f;
				break;
			default:
				break;
			}
			moveNum++;
		}
		else if (isUp == true){
			preHeight = 95.f;
			width = 65.2f;
			switch (this->moveNum){
			case 1: preWidth = 5.f;
				break;
			case 2: preWidth = 73.f;
				break;
			default:
				break;
			}
			moveNum++;
		}
		if (turnLeft == false && isMoving){
			currentFrame = sf::IntRect(preWidth, preHeight, width, height);
		}
		else if (turnLeft == true && isMoving){
			currentFrame = sf::IntRect(preWidth + width, preHeight, -width, height);
			playerSprite.setOrigin(width, 0);
		}
		else if (isUp){
			currentFrame = sf::IntRect(preWidth, preHeight, width, height);
		}
		else currentFrame = sf::IntRect(0,0, width, height);
		playerSprite.setOrigin(0, 0);
		playerSprite.setTextureRect(currentFrame);
		aniTime.restart();
	}
}



void Player::update(int direction){
	move(direction);
	updateAnimation(direction);
}

void Player::initMoveVariable(){
	movementSpeed = 10.f;
	preWidth = 1.f;
	preHeight = 0.f;
	width = 65.f;
	height = 94.f;
	isMoving = false;
	standNum = 1;
	moveNum = 1;
	turnLeft = false;
	isUp = false;

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

void Player::updateWindowBoundsCollision(const sf::RenderWindow* window){
	if (this->playerSprite.getGlobalBounds().left <= 0.f)
		this->playerSprite.setPosition(0.f, this->playerSprite.getGlobalBounds().top);
	
	if (this->playerSprite.getGlobalBounds().left + this->playerSprite.getGlobalBounds().width >= window->getSize().x)
		this->playerSprite.setPosition(window->getSize().x - this->playerSprite.getGlobalBounds().width, this->playerSprite.getGlobalBounds().top);

	if (this->playerSprite.getGlobalBounds().top <= 0.f)
		this->playerSprite.setPosition(this->playerSprite.getGlobalBounds().left, 0.f);
	
	if (this->playerSprite.getGlobalBounds().top + this->playerSprite.getGlobalBounds().height >= window->getSize().y)
		this->playerSprite.setPosition(this->playerSprite.getGlobalBounds().left, window->getSize().y - this->playerSprite.getGlobalBounds().height);
}

const sf::Vector2f& Player::getPosition() const {
    return playerSprite.getPosition();
}
