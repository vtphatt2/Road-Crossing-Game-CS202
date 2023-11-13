<<<<<<< Updated upstream
﻿#pragma once
#include"SFML/Graphics.hpp"
//Edit here!
#define blueUFOPath "../resource/blueUFO.png"
#define brownUFOPath "../resource/brownUFO.png"
#define pinkUFOPath "../resource/pinkUFO.png"
#define greenUFOPath "../resource/greenUFO.png"

#define leftCoinPath "../resource/leftCoin.png"
#define rightCoinPath "../resource/rightCoin.png"

#define movingAnt1Path "../resource/movingAnt1.png"
#define movingAnt2Path "../resource/movingAnt2.png"
#define inRestAntPath "../resource/inRestAnt.png"

#define bird1Path "../resource/bird1.png"
#define bird2Path "../resource/bird2.png"

#define movingBat1Path "../resource/movingBat1.png" 
#define movingBat2Path "../resource/movingBat2.png"
#define inRestBatPath "../resource/inRestBat.png"

#define movingWormPath "../resource/movingWorm.png"
#define inRestWormPath "../resource/inRestWorm.png"

#define movingMonster1Path "../resource/movingMonster1.png"
#define movingMonster2Path "../resource/movingMonster2.png"
#define inRestMonsterPath "../resource/inRestMonster.png"

#define slime1Path "../resource/slime1.png"
#define slime2Path "../resource/slime2.png"
#define slime3Path "../resource/slime3.png"

#define movingSnailPath "../resource/movingSnail.png"
#define inRestSnailPath "../resource/inRestSnail.png"

#define movingGhost1Path "../resource/movingGhost1.png" 
#define movingGhost2Path "../resource/movingGhost2.png" 
#define inRestGhostPath "../resource/inRestGhost.png" 

#define frog1Path "../resource/frog1.png"
#define frog2Path "../resource/frog2.png"
#define frog3Path "../resource/frog3.png"

#define movingMouse1Path "../resource/movingMouse1.png"
#define movingMouse2Path "../resource/movingMouse2.png"
#define inRestMousePath "../resource/inRestMouse.png"

#define movingMoon1Path "../resource/movingMoon1.png"
#define movingMoon2Path "../resource/movingMoon2.png"
#define inRestMoonPath "../resource/inRestMoon.png"

#define movingSeaWheet1Path "../resource/movingSeaWheet1.png"
#define movingSeaWheet2Path "../resource/movingSeaWheet2.png"
#define inRestSeaWheetPath "../resource/inRestSeaWheet.png"

#define blueFishPath "../resource/blueFish.png"
#define pinkFishPath "../resource/pinkFish.png"

#define defaultSpeed 0.01 * 60;



//UFO
enum class UFOColor {
	blue, brown, pink, green
=======
﻿#ifndef OBSTACLES_HPP
#define OBSTACLES_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
// Edit here!
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

// UFO
enum class UFOColor
{
	blue,
	brown,
	pink,
	green
>>>>>>> Stashed changes
};
class UFO : public sf::Drawable
{
public:
	UFO();
	UFO(UFOColor color);
	sf::Vector2f getPosition();
<<<<<<< Updated upstream
	void setPosition(const sf::Vector2f& position);
=======
	void setPosition(const sf::Vector2f &position);
>>>>>>> Stashed changes
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
<<<<<<< Updated upstream
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
=======

private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
>>>>>>> Stashed changes
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

<<<<<<< Updated upstream
//coin
enum class CoinType {
	left, right
=======
// coin
enum class CoinType
{
	left,
	right
>>>>>>> Stashed changes
};
class Coin : public sf::Drawable
{
public:
	Coin();
	Coin(CoinType type);
	sf::Vector2f getPosition();
<<<<<<< Updated upstream
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
=======
	void setPosition(const sf::Vector2f &position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	void run();

private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

// Ant
>>>>>>> Stashed changes
class Ant : public sf::Drawable
{
public:
	Ant();
	sf::Vector2f getPosition();
<<<<<<< Updated upstream
	void setPosition(const sf::Vector2f& position);
=======
	void setPosition(const sf::Vector2f &position);
>>>>>>> Stashed changes
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
<<<<<<< Updated upstream
private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
=======

private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
>>>>>>> Stashed changes
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

<<<<<<< Updated upstream
//Bird
=======
// Bird
>>>>>>> Stashed changes
class Bird : public sf::Drawable
{
public:
	Bird();
	sf::Vector2f getPosition();
<<<<<<< Updated upstream
	void setPosition(const sf::Vector2f& position);
=======
	void setPosition(const sf::Vector2f &position);
>>>>>>> Stashed changes
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
<<<<<<< Updated upstream
private:
	sf::Texture texture[2];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
=======

private:
	sf::Texture texture[2];
	sf::Sprite sprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
>>>>>>> Stashed changes
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

<<<<<<< Updated upstream
//Bat
=======
// Bat
>>>>>>> Stashed changes
class Bat : public sf::Drawable
{
public:
	Bat();
	sf::Vector2f getPosition();
<<<<<<< Updated upstream
	void setPosition(const sf::Vector2f& position);
=======
	void setPosition(const sf::Vector2f &position);
>>>>>>> Stashed changes
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
<<<<<<< Updated upstream
private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
=======

private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
>>>>>>> Stashed changes
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

<<<<<<< Updated upstream
//Worm
=======
// Worm
>>>>>>> Stashed changes
class Worm : public sf::Drawable
{
public:
	Worm();
	sf::Vector2f getPosition();
<<<<<<< Updated upstream
	void setPosition(const sf::Vector2f& position);
=======
	void setPosition(const sf::Vector2f &position);
>>>>>>> Stashed changes
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
<<<<<<< Updated upstream
private:
	sf::Texture texture[2];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
=======

private:
	sf::Texture texture[2];
	sf::Sprite sprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
>>>>>>> Stashed changes
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

<<<<<<< Updated upstream
//Monster
=======
// Monster
>>>>>>> Stashed changes
class Monster : public sf::Drawable
{
public:
	Monster();
	sf::Vector2f getPosition();
<<<<<<< Updated upstream
	void setPosition(const sf::Vector2f& position);
=======
	void setPosition(const sf::Vector2f &position);
>>>>>>> Stashed changes
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
<<<<<<< Updated upstream
private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
=======

private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
>>>>>>> Stashed changes
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
<<<<<<< Updated upstream
	bool toTheRight = true;
};

//Slime
=======
};

// Slime
>>>>>>> Stashed changes
class Slime : public sf::Drawable
{
public:
	Slime();
	sf::Vector2f getPosition();
<<<<<<< Updated upstream
	void setPosition(const sf::Vector2f& position);
=======
	void setPosition(const sf::Vector2f &position);
>>>>>>> Stashed changes
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
<<<<<<< Updated upstream
private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
=======

private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
>>>>>>> Stashed changes
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
	bool hidden;
};

<<<<<<< Updated upstream
//Snail
=======
// Snail
>>>>>>> Stashed changes
class Snail : public sf::Drawable
{
public:
	Snail();
	sf::Vector2f getPosition();
<<<<<<< Updated upstream
	void setPosition(const sf::Vector2f& position);
=======
	void setPosition(const sf::Vector2f &position);
>>>>>>> Stashed changes
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
<<<<<<< Updated upstream
private:
	sf::Texture texture[2];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
=======

private:
	sf::Texture texture[2];
	sf::Sprite sprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
>>>>>>> Stashed changes
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

<<<<<<< Updated upstream
//Ghost
=======
// Ghost
>>>>>>> Stashed changes
class Ghost : public sf::Drawable
{
public:
	Ghost();
	sf::Vector2f getPosition();
<<<<<<< Updated upstream
	void setPosition(const sf::Vector2f& position);
=======
	void setPosition(const sf::Vector2f &position);
>>>>>>> Stashed changes
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
<<<<<<< Updated upstream
private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
=======

private:
	sf::Texture texture[3];
	sf::Sprite sprite;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
>>>>>>> Stashed changes
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
};

<<<<<<< Updated upstream
//Frog
class Frog : public sf::Drawable
{
public:
	Frog();
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

//Mouse
class Mouse : public sf::Drawable
{
public:
	Mouse();
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
	int limit = 10 / speed;
};

//Moon
class Moon : public sf::Drawable
{
public:
	Moon();
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
	int limit = 5 / speed;
	bool toRight = 1;
};

//SeaWheet
class SeaWheet : public sf::Drawable
{
public:
	SeaWheet();
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
	bool toRight = true;
};

//Fish
enum class fishColor {
	blue, pink
};
class Fish : public sf::Drawable
{
public:
	Fish();
	Fish(fishColor color);
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	sf::FloatRect getGlobalBounds();
	float getSpeed();
	void setSpeed(float speed);
	void run();
	void stop();
	void resume();
	void jump();
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float speed = defaultSpeed;
	int numOfMoves = 0;
	bool isRunning = true;
	int limit = 20 / speed;
	bool isJumping = 0;
};

=======
#endif
>>>>>>> Stashed changes
