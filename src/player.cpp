#include "header/player.hpp"

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
		case PlayerSkin::NUM_SKINS:   
			break;
    }

	playerTexture.loadFromFile(texturePath);
    playerSprite.setTexture(playerTexture);	
	playerSprite.setTextureRect(sf::IntRect(0,0,playerTexture.getSize().x, playerTexture.getSize().y));
	playerSprite.setPosition(622, 412);
}

void Player::resetPos(){
	playerSprite.setPosition(668, 816);
}

void Player::renderInGame(){
	std::string texturePath;
    switch (playerSkin) {
        case PlayerSkin::GREEN:
            texturePath = "../resource/player/MovingGreen.png";
            break;
        case PlayerSkin::BLUE:
            texturePath = "../resource/player/MovingBlue.png";
            break;
        case PlayerSkin::RED:
            texturePath = "../resource/player/MovingRed.png";
            break;
		case PlayerSkin::YELLOW:
            texturePath = "../resource/player/MovingYellow.png";
            break;
		case PlayerSkin::BROWN:
            texturePath = "../resource/player/MovingBeige.png";
            break; 
		case PlayerSkin::NUM_SKINS:   
			break;       
    }
	playerTexture.loadFromFile(texturePath);
    playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0,0,width, height));
	playerSprite.setPosition(668, 816);
}

sf::Sprite Player::getPlayerSprite(){
	return playerSprite;
}

std::string Player::getPlayerSkin() {
	switch (playerSkin) {
	case PlayerSkin::GREEN:
		return "GREEN";
	case PlayerSkin::BLUE:
		return "BLUE";
	case PlayerSkin::RED:
		return "RED";
	case PlayerSkin::YELLOW:
		return "YELLOW";
	case PlayerSkin::BROWN:
		return "BROWN";
	case PlayerSkin::NUM_SKINS:
		break;
	}
	return "";
}

void Player::move(Direction direction) {
    sf::Vector2f movement(0.f, 0.f);

    switch (static_cast<int>(direction)) {
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
			movement.x += 0.f;
            movement.y -= 0.f;
            isMoving = false;
            turnLeft = false;
			isUp = false;
            break;
    }

    playerSprite.move(movement.x, movement.y);
}

void Player::updateAnimation(Direction direction){
	if (aniTime.getElapsedTime().asSeconds() >= 0.2f){
		if (moveNum >= 3) moveNum = 1;
		if (isMoving == true && !isUp){
			preHeight = 193.f;
			width = 70.f;
			switch (moveNum)
			{
			case 1: preWidth = 0.f;
				break;
			case 2: preWidth = 78.f;
				break;
			default:
				break;
			}
			moveNum++;
		}
		else if (isUp == true){
			preHeight = 95.f;
			width = 70.f;
			switch (moveNum){
			case 1: preWidth = 0.f;
				break;
			case 2: preWidth = 78.f;
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
		else if (isUp && !isMoving){
			currentFrame = sf::IntRect(preWidth, preHeight, width, height);
		}
		else if (!isUp && !isMoving) currentFrame = sf::IntRect(0,0,70, height);
		
		playerSprite.setOrigin(0, 0);
		playerSprite.setTextureRect(currentFrame);
		aniTime.restart();
	}
}

void Player::update(Direction direction){
	move(direction);
	updateAnimation(direction);
}

void Player::initMoveVariable(){
	movementSpeed = 10.f;
	preWidth = 0.f;
	preHeight = 0.f;
	width = 70.f;
	height = 92.f;
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

void Player::updateWindowBoundsCollision(const sf::RenderWindow* window, int translateY){
	//Top edge
    if (this->playerSprite.getGlobalBounds().top <= translateY) {
		this->playerSprite.setPosition(
			this->playerSprite.getPosition().x,
			translateY
		);
	}

	//Right edge
    if (this->playerSprite.getGlobalBounds().left + this->playerSprite.getGlobalBounds().width >= window->getSize().x){
        this->playerSprite.setPosition(
            window->getSize().x - this->playerSprite.getGlobalBounds().width,
            this->playerSprite.getPosition().y
        );
	}

	//Left edge
    if (this->playerSprite.getGlobalBounds().left <= 0.f){
        this->playerSprite.setPosition(
            0.f,
            this->playerSprite.getPosition().y
        );
	}

	// Bottom edge
	if (this->playerSprite.getGlobalBounds().top + this->playerSprite.getGlobalBounds().height >= int(window->getSize().y) + translateY) {
		this->playerSprite.setPosition(
			this->playerSprite.getPosition().x,
			window->getSize().y - this->playerSprite.getGlobalBounds().height + translateY
		);
	}
}

const sf::Vector2f& Player::getPosition() const {
    return playerSprite.getPosition();
}

void Player::setPosition(int posX, int posY) {
	playerSprite.setPosition(posX, posY);
}

void Player::setMovementSpeed(float speed){
	movementSpeed = speed;
}

bool Player::isCollisionWithMargin(const sf::FloatRect stuffGlobalBound, float margin) {
    sf::FloatRect bounds1 = playerSprite.getGlobalBounds();
    sf::FloatRect bounds2 = stuffGlobalBound;

    bounds1.left -= margin;
    bounds1.top -= margin;
    bounds1.width += 2 * margin;
    bounds1.height += 2 * margin;

    return bounds1.intersects(bounds2);
}

void Player::updatePlayerDrown(){
	std::string texturePath;
	switch (playerSkin) {
        case PlayerSkin::GREEN:
            texturePath = "../resource/player/alienGreen_duck.png";
            break;
        case PlayerSkin::BLUE:
            texturePath = "../resource/player/alienBlue_duck.png";
            break;
        case PlayerSkin::RED:
            texturePath = "../resource/player/alienPink_duck.png";
            break;
		case PlayerSkin::YELLOW:
            texturePath = "../resource/player/alienYellow_duck.png";
            break;
		case PlayerSkin::BROWN:
            texturePath = "../resource/player/alienBeige_duck.png";
            break;  
		case PlayerSkin::NUM_SKINS:   
			break;      
    }
	playerTexture.loadFromFile(texturePath);
    playerSprite.setTexture(playerTexture, true);
}

void Player::setPlayerSkin(PlayerSkin skin) {
	playerSkin = skin;
}

void Player::updatePlayerDie(){
	std::string texturePath;
	switch (playerSkin) {
        case PlayerSkin::GREEN:
            texturePath = "../resource/player/DieGreen.png";
            break;
        case PlayerSkin::BLUE:
            texturePath = "../resource/player/DieBlue.png";
            break;
        case PlayerSkin::RED:
            texturePath = "../resource/player/DiePink.png";
            break;
		case PlayerSkin::YELLOW:
            texturePath = "../resource/player/DieYellow.png";
            break;
		case PlayerSkin::BROWN:
            texturePath = "../resource/player/DieBeige.png";
            break;  
		case PlayerSkin::NUM_SKINS:   
			break;      
    }
	playerTexture.loadFromFile(texturePath);
    playerSprite.setTexture(playerTexture, true);
}
