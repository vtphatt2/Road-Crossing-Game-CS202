#pragma once
#include"SFML/Graphics.hpp"
//Edit here!
#define blueUFOPath ""
#define brownUFOPath ""
#define pinkUFOPath ""
#define greenUFOPath ""

#define leftCoinPath ""
#define rightCoinPath ""

#define movingAnt1Path ""
#define movingAnt2Path ""
#define inRestAntPath ""

#define bird1Path ""
#define bird2Path ""

#define movingBat1Path "" 
#define movingBat2Path ""
#define inRestBatPath ""

#define movingWormPath ""
#define inRestWormPath ""

#define movingMonster1Path ""
#define movingMonster2Path ""
#define inRestMonsterPath ""

#define slime1Path ""
#define slime2Path ""
#define slime3Path ""

#define movingSnailPath ""
#define inRestSnailPath ""

#define movingGhost1Path "" 
#define movingGhost2Path "" 
#define inRestGhostPath "" 

#define defaultSpeed 0.01

//UFO
enum class UFOColor {
	blue, brown, pink, green
};
class UFO: public sf::Drawable
{
public:
	UFO();
	UFO(UFOColor color);
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

//coin
enum class CoinType {
	left, right
};
class Coin: public sf::Drawable
{
public:
	Coin();
	Coin(CoinType type);
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	void run();
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

//Ant
class Ant: public sf::Drawable
{
public:
	Ant();
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

//Bird
class Bird: public sf::Drawable
{
public:
	Bird();
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
private:
	sf::Texture texture[2];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

//Bat
class Bat: public sf::Drawable
{
public:
	Bat();
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

//Worm
class Worm: public sf::Drawable
{
public:
	Worm();
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
private:
	sf::Texture texture[2];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

//Monster
class Monster: public sf::Drawable
{
public:
	Monster();
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

//Slime
class Slime: public sf::Drawable
{
public:
	Slime();
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
	bool hidden;
};

//Snail
class Snail : public sf::Drawable
{
public:
	Snail();
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
private:
	sf::Texture texture[2];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

//Ghost
class Ghost : public sf::Drawable
{
public:
	Ghost();
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};