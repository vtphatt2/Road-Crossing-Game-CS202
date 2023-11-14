#include "header/stuff.hpp"
#include<iostream>
//UFO 
UFO::UFO() {
	texture.loadFromFile(blueUFOPath);
	sprite.setTexture(texture);
}
UFO::UFO(UFOColor color) {
	switch (color) {
	case UFOColor::blue:
		texture.loadFromFile(blueUFOPath);
		break;
	case UFOColor::brown:
		texture.loadFromFile(brownUFOPath);
		break;
	case UFOColor::green:
		texture.loadFromFile(greenUFOPath);
		break;
	case UFOColor::pink:
		texture.loadFromFile(pinkUFOPath);
		break;
	}
	sprite.setTexture(texture);
}
sf::Vector2f UFO::getPosition() {
	return sprite.getPosition();
}
void UFO::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void UFO::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect UFO::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float UFO::getSpeed() {
	return speed;
}
void UFO::setSpeed(float speed) {
	this->speed = speed;
}
void UFO::run() {
	if (isRunning) {
		if (numOfMoves < limit) {
			sprite.move(speed, speed);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.move(speed, -speed);
		}
		else {
			numOfMoves = 0;
		}
		numOfMoves++;
	}
}
void UFO::stop() {
	isRunning = 0;
}
void UFO::resume() {
	isRunning = 1;
}
void UFO::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Coin
Coin::Coin() {
	texture.loadFromFile(leftCoinPath);
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}
Coin::Coin(CoinType type) {
	switch (type)
	{
	case CoinType::left:
		texture.loadFromFile(leftCoinPath);
		break;
	case CoinType::right:
		texture.loadFromFile(rightCoinPath);
		break;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}
sf::Vector2f Coin::getPosition() {
	return sprite.getPosition();
}
void Coin::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position.x + sprite.getGlobalBounds().width / 2, position.y + sprite.getGlobalBounds().height / 2);
}
void Coin::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x + sprite.getGlobalBounds().width / 2, y + sprite.getGlobalBounds().height / 2));
}
sf::FloatRect Coin::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
void Coin::run() {
	sprite.rotate(0.01);

}
void Coin::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Ant
Ant::Ant() {
	texture[0].loadFromFile(movingAnt1Path);
	texture[1].loadFromFile(movingAnt2Path);
	texture[2].loadFromFile(inRestAntPath);
	sprite.setTexture(texture[0]);
}
sf::Vector2f Ant::getPosition() {
	return sprite.getPosition();
}
void Ant::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Ant::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Ant::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Ant::getSpeed() {
	return speed;
}
void Ant::setSpeed(float speed) {
	this->speed = speed;
}
void Ant::run() {
	if (isRunning) {
		if (numOfMoves < limit) {
			sprite.setTexture(texture[0]);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.setTexture(texture[1]);
		}
		else {
			numOfMoves = 0;
		}
		sprite.move(-speed, 0);
		numOfMoves++;
	}
	else {
		sprite.setTexture(texture[2]);
	}

}
void Ant::stop() {
	isRunning = 0;
}
void Ant::resume() {
	isRunning = 1;
}
void Ant::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Bird
Bird::Bird() {
	texture[0].loadFromFile(bird1Path);
	texture[1].loadFromFile(bird2Path);
	sprite.setTexture(texture[0]);
}
sf::Vector2f Bird::getPosition() {
	return sprite.getPosition();
}
void Bird::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Bird::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Bird::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Bird::getSpeed() {
	return speed;
}
void Bird::setSpeed(float speed) {
	this->speed = speed;
}
void Bird::run() {
	if (numOfMoves < limit) {
		sprite.setTexture(texture[0]);
	}
	else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
		sprite.setTexture(texture[1]);
	}
	else {
		numOfMoves = 0;
	}
	numOfMoves++;
	if (isRunning) {
		sprite.move(-speed, 0);
	}
}
void Bird::stop() {
	isRunning = 0;
}
void Bird::resume() {
	isRunning = 1;
}
void Bird::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Bat
Bat::Bat() {
	texture[0].loadFromFile(movingBat1Path);
	texture[1].loadFromFile(movingBat2Path);
	texture[2].loadFromFile(inRestBatPath);
	sprite.setTexture(texture[0]);
}
sf::Vector2f Bat::getPosition() {
	return sprite.getPosition();
}
void Bat::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Bat::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Bat::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Bat::getSpeed() {
	return speed;
}
void Bat::setSpeed(float speed) {
	this->speed = speed;
}
void Bat::run() {

	if (isRunning) {
		if (numOfMoves < limit) {
			sprite.setTexture(texture[0]);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.setTexture(texture[1]);
		}
		else if (numOfMoves >= 2 * limit && numOfMoves < 3 * limit) {
			sprite.setTexture(texture[2]);
		}
		else {
			numOfMoves = 0;
		}
		sprite.move(-speed, 0);
		numOfMoves++;
	}
	else {
		sprite.setTexture(texture[2]);
	}


}
void Bat::stop() {
	isRunning = 0;
}
void Bat::resume() {
	isRunning = 1;
}
void Bat::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Worm
Worm::Worm() {
	texture[0].loadFromFile(movingWormPath);
	texture[1].loadFromFile(inRestWormPath);
	sprite.setTexture(texture[0]);
}
sf::Vector2f Worm::getPosition() {
	return sprite.getPosition();
}
void Worm::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Worm::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Worm::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Worm::getSpeed() {
	return speed;
}
void Worm::setSpeed(float speed) {
	this->speed = speed;
}
void Worm::run() {

	if (isRunning) {
		sprite.setTexture(texture[0]);
		if (numOfMoves < limit) {
			sprite.scale(0.9999, 1);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.scale(1 / 0.9999, 1);
		}
		else {
			numOfMoves = 0;
		}
		numOfMoves++;
		sprite.move(-speed, 0);
	}
	else {
		sprite.setTexture(texture[1]);
	}
}
void Worm::stop() {
	isRunning = 0;
}
void Worm::resume() {
	isRunning = 1;
}
void Worm::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Monster
Monster::Monster() {
	texture[0].loadFromFile(movingMonster1Path);
	texture[1].loadFromFile(movingMonster2Path);
	texture[2].loadFromFile(inRestMonsterPath);
	sprite.setTexture(texture[0]);
}
sf::Vector2f Monster::getPosition() {
	return sprite.getPosition();
}
void Monster::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Monster::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Monster::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Monster::getSpeed() {
	return speed;
}
void Monster::setSpeed(float speed) {
	this->speed = speed;
}
void Monster::run() {
	if (isRunning) {
		if (numOfMoves < limit) {
			sprite.setTexture(texture[0]);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.setTexture(texture[1]);
		}
		else {
			numOfMoves = 0;
		}
		(toTheRight ? sprite.move(speed, 0) : sprite.move(-speed, 0));
		numOfMoves++;
	}
	else {
		sprite.setTexture(texture[2]);
	}
}
void Monster::stop() {
	isRunning = 0;
	toTheRight = !toTheRight;
}
void Monster::resume() {
	isRunning = 1;
}
void Monster::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Slime
Slime::Slime() {
	texture[0].loadFromFile(slime1Path);
	texture[1].loadFromFile(slime2Path);
	texture[2].loadFromFile(slime3Path);
	sprite.setTexture(texture[0]);
	hidden = false;
}
sf::Vector2f Slime::getPosition() {
	return sprite.getPosition();
}
void Slime::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Slime::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Slime::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Slime::getSpeed() {
	return speed;
}
void Slime::setSpeed(float speed) {
	this->speed = speed;
}
void Slime::run() {
	if (isRunning) {
		if (numOfMoves < limit) {
			sprite.setTexture(texture[0]);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.setTexture(texture[1]);
		}
		else if (numOfMoves >= 2 * limit && numOfMoves < 3 * limit) {
			sprite.setTexture(texture[2]);
		}
		else if (numOfMoves >= 3 * limit && numOfMoves < 4 * limit) {
			sprite.setTexture(texture[1]);
		}
		else if (numOfMoves >= 4 * limit && numOfMoves < 5 * limit) {
			sprite.setTexture(texture[0]);
		}
		else if (numOfMoves >= 5 * limit && numOfMoves < 6 * limit) {
			hidden = true;
		}
		else {
			numOfMoves = 0;
			hidden = false;
		}
		sprite.move(-speed, 0);
		numOfMoves++;
	}
}
void Slime::stop() {
	isRunning = 0;
}
void Slime::resume() {
	isRunning = 1;
}
void Slime::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (!hidden) {
		target.draw(sprite);
	}

}

//Snail
Snail::Snail() {
	texture[0].loadFromFile(movingSnailPath);
	texture[1].loadFromFile(inRestSnailPath);
	sprite.setTexture(texture[0]);
}
sf::Vector2f Snail::getPosition() {
	return sprite.getPosition();
}
void Snail::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Snail::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Snail::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Snail::getSpeed() {
	return speed;
}
void Snail::setSpeed(float speed) {
	this->speed = speed;
}
void Snail::run() {

	if (isRunning) {
		sprite.setTexture(texture[0], true);
		if (numOfMoves < limit) {
			sprite.scale(0.9999, 1);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.scale(1 / 0.9999, 1);
		}
		else {
			numOfMoves = 0;
		}
		numOfMoves++;
		sprite.move(-speed, 0);
	}
	else {
		sprite.setTexture(texture[1], true);
	}
}
void Snail::stop() {
	isRunning = 0;
}
void Snail::resume() {
	isRunning = 1;
}
void Snail::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Ghost
Ghost::Ghost() {
	texture[0].loadFromFile(movingGhost1Path);
	texture[1].loadFromFile(movingGhost2Path);
	texture[2].loadFromFile(inRestGhostPath);
	sprite.setTexture(texture[0]);
}
sf::Vector2f Ghost::getPosition() {
	return sprite.getPosition();
}
void Ghost::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Ghost::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Ghost::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Ghost::getSpeed() {
	return speed;
}
void Ghost::setSpeed(float speed) {
	this->speed = speed;
}
void Ghost::run() {
	if (isRunning) {
		if (numOfMoves < limit) {
			sprite.setTexture(texture[0]);
			sprite.move(-speed, speed);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.setTexture(texture[1]);
			sprite.move(-speed, -speed);
		}
		else {
			numOfMoves = 0;
		}
		sprite.move(-speed, 0);
		numOfMoves++;
	}
	else {
		sprite.setTexture(texture[2]);
	}
}
void Ghost::stop() {
	isRunning = 0;
}
void Ghost::resume() {
	isRunning = 1;
}
void Ghost::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);

}

//Frog
Frog::Frog() {
	texture[0].loadFromFile(frog1Path);
	texture[1].loadFromFile(frog2Path);
	texture[2].loadFromFile(frog3Path);
	sprite.setTexture(texture[0]);
}
sf::Vector2f Frog::getPosition() {
	return sprite.getPosition();
}
void Frog::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Frog::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Frog::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Frog::getSpeed() {
	return speed;
}
void Frog::setSpeed(float speed) {
	this->speed = speed;
}
void Frog::run() {
	if (isRunning) {
		if (numOfMoves < 2 * limit) {
			sprite.setTexture(texture[0]);

		}
		else if (numOfMoves >= 2 * limit && numOfMoves < 3 * limit) {
			sprite.setTexture(texture[1]);
			sprite.move(-speed * 3, -speed);
		}
		else if (numOfMoves >= 3 * limit && numOfMoves < 3.5 * limit) {
			sprite.setTexture(texture[2]);
			sprite.move(-speed * 3, speed * 2);
			sprite.rotate(-speed);
		}
		else {
			numOfMoves = 0;
			sprite.move(0, 0);
			sprite.rotate((speed / 2) * limit);
		}
		numOfMoves++;
	}
	else {
		sprite.setTexture(texture[0]);
	}
}
void Frog::stop() {
	isRunning = 0;
}
void Frog::resume() {
	isRunning = 1;
}
void Frog::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Mouse
Mouse::Mouse() {
	texture[0].loadFromFile(movingMouse1Path);
	texture[1].loadFromFile(movingMouse2Path);
	texture[2].loadFromFile(inRestMousePath);
	sprite.setTexture(texture[0]);
}
sf::Vector2f Mouse::getPosition() {
	return sprite.getPosition();
}
void Mouse::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Mouse::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Mouse::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Mouse::getSpeed() {
	return speed;
}
void Mouse::setSpeed(float speed) {
	this->speed = speed;
}
void Mouse::run() {

	if (isRunning) {

		if (numOfMoves < limit) {
			sprite.setTexture(texture[0]);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.setTexture(texture[1]);
		}
		else {
			numOfMoves = 0;
		}
		numOfMoves++;
		sprite.move(-speed, 0);
	}
	else {
		sprite.setTexture(texture[2]);
	}
}
void Mouse::stop() {
	isRunning = 0;
}
void Mouse::resume() {
	isRunning = 1;
}
void Mouse::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Moon
Moon::Moon() {
	texture[0].loadFromFile(movingMoon1Path);
	texture[1].loadFromFile(movingMoon2Path);
	texture[2].loadFromFile(inRestMoonPath);
	sprite.setTexture(texture[0]);
}
sf::Vector2f Moon::getPosition() {
	return sprite.getPosition();
}
void Moon::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Moon::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Moon::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Moon::getSpeed() {
	return speed;
}
void Moon::setSpeed(float speed) {
	this->speed = speed;
}
void Moon::run() {

	if (isRunning) {
		if (numOfMoves < limit) {
			sprite.setTexture(texture[0]);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.setTexture(texture[1]);
		}
		else {
			numOfMoves = 0;
		}
		numOfMoves++;
		(toRight ? sprite.move(speed, 0) : sprite.move(-speed, 0));
	}
	else {
		sprite.setTexture(texture[2]);
	}
}
void Moon::stop() {
	isRunning = 0;
	toRight = !toRight;
}
void Moon::resume() {
	isRunning = 1;
}
void Moon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//SeaWheet
SeaWheet::SeaWheet() {
	texture[0].loadFromFile(movingSeaWheet1Path);
	texture[1].loadFromFile(movingSeaWheet2Path);
	texture[2].loadFromFile(inRestSeaWheetPath);
	sprite.setTexture(texture[0]);
}
sf::Vector2f SeaWheet::getPosition() {
	return sprite.getPosition();
}
void SeaWheet::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void SeaWheet::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect SeaWheet::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float SeaWheet::getSpeed() {
	return speed;
}
void SeaWheet::setSpeed(float speed) {
	this->speed = speed;
}
void SeaWheet::run() {

	if (isRunning) {
		if (numOfMoves < limit) {
			sprite.setTexture(texture[0]);
		}
		else if (numOfMoves >= limit && numOfMoves < 2 * limit) {
			sprite.setTexture(texture[1]);
		}
		else {
			numOfMoves = 0;
		}
		numOfMoves++;
		(toRight ? sprite.move(speed, 0) : sprite.move(-speed, 0));
	}
	else {
		sprite.setTexture(texture[2]);
	}
}
void SeaWheet::stop() {
	isRunning = 0;
	toRight = !toRight;
}
void SeaWheet::resume() {
	isRunning = 1;
}
void SeaWheet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

//Fish
Fish::Fish() {
	texture.loadFromFile(blueFishPath);
	sprite.setTexture(texture);
}
Fish::Fish(fishColor color) {
	switch (color) {
	case fishColor::blue:
		texture.loadFromFile(blueFishPath);
		break;
	case fishColor::pink:
		texture.loadFromFile(pinkFishPath);
		break;
	}
	sprite.setTexture(texture);
}
sf::Vector2f Fish::getPosition() {
	return sprite.getPosition();
}
void Fish::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Fish::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect Fish::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float Fish::getSpeed() {
	return speed;
}
void Fish::setSpeed(float speed) {
	this->speed = speed;
}
void Fish::run() {
	if (isRunning && !isJumping) {
		if (numOfMoves < limit) {
			sprite.move(-speed, 0);
		}
		else {
			numOfMoves = 0;
		}
		numOfMoves++;
	}
	if (isJumping) {
		if (numOfMoves < 4 * limit) {
			sprite.move(-speed, -speed * 2);
			sprite.rotate(speed / 4.0);
		}
		else if (numOfMoves >= 4 * limit && numOfMoves < 8 * limit) {
			sprite.move(-speed, speed * 2);
			sprite.rotate(-speed / 4.0);
		}
		else {
			isJumping = 0;
			numOfMoves = 0;
		}
		numOfMoves++;
	}
}
void Fish::stop() {
	isRunning = 0;
}
void Fish::resume() {
	isRunning = 1;
	numOfMoves = 0;
}
void Fish::jump() {
	isJumping = 1;
}
void Fish::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

TraficLight::TraficLight() {
	texture[0].loadFromFile(greenLightPath);
	texture[1].loadFromFile(yellowLightPath);
	texture[2].loadFromFile(redLightPath);
	sprite.setTexture(texture[0]);
}
sf::Vector2f TraficLight::getPosition() {
	return sprite.getPosition();
}
void TraficLight::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void TraficLight::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}
sf::FloatRect TraficLight::getGlobalBounds() {
	return sprite.getGlobalBounds();
}
float TraficLight::getSpeed() {
	return speed;
}
void TraficLight::setSpeed(float speed) {
	this->speed = speed;
}
void TraficLight::run() {
	if (numOfMoves < limit) {
		sprite.setTexture(texture[0]);
	}
	else if (numOfMoves >= limit && numOfMoves < 1.1 * limit) {
		sprite.setTexture(texture[1]);
	}
	else if (numOfMoves >= 1.1 * limit && numOfMoves < 1.4 * limit) {
		sprite.setTexture(texture[2]);
	}
	else {
		numOfMoves = 0;
	}
	numOfMoves++;

}
void TraficLight::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}