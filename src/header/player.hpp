#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stack>
#include <unordered_map>
#include <memory>
#include <cmath>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "state.hpp"
#include "character.hpp"

#define movingBlue "../resource/player/MovingBlue.png"
#define standingLeftBlue "../resource/player/StandingLeftBlue.png"
#define standingRightBlue "../resource/player/StandingRightBlue.png"
#define standingBlue "../resource/player/alienBlue.png"


enum class PlayerSkin {
    GREEN,
    BLUE,
    RED,
    YELLOW,
    BROWN,
    NUM_SKINS,
};

enum class Direction{
    None, Up, Down, Left, Right
};

class Player{
    public: 
        Player(PlayerSkin initialSkin);
        ~Player(); 

        void initPlayer();
        void resetPos(); 
        void move(Direction direction); 
        void update(Direction direction);
        void updateWindowBoundsCollision(const sf::RenderWindow* window, int translateY = 0); 
        const sf::Vector2f& getPosition() const;
        sf::Sprite getPlayerSprite();
        void renderInGame();
        void initMoveVariable();
        void updateAnimation(Direction direction);
        void setMovementSpeed(float speed);
        bool isCollisionWithMargin(const sf::FloatRect stuffGlobalBound, float margin);

        //changing Skin
        void changeSkinLeft();
        void changeSkinRight();
        void updatePlayerTexture(int skinIndex);
        void updatePlayerDrown();
        
    private: 
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        PlayerSkin playerSkin; 
        sf::IntRect currentFrame;

        float movementSpeed;
        float width;
        float height;
        float preWidth;
        float preHeight;

        bool isMoving;
        int standNum;
        int moveNum;
        bool turnLeft;
        bool isUp;

        sf::Clock aniTime;
};

#endif