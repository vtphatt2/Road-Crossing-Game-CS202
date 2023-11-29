#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "state.hpp"
#include "character.hpp"
#include <unordered_map>
#include <memory>

#define movingBlue "../resource/player/MovingBlue.png"
#define standingLeftBlue "../resource/player/StandingLeftBlue.png"
#define standingRightBlue "../resource/player/StandingRightBlue.png"
#define standingBlue "../resource/player/alienBlue.png"


using namespace std;

enum class PlayerSkin {
    GREEN,
    BLUE,
    RED,
    YELLOW,
    BROWN,
    NUM_SKINS,
};

class Player{
    public: 
        Player(PlayerSkin initialSkin);
        Player();
        ~Player(); 

        void initPlayer();
        void resetPos(); 
        void move(int direction); 
        void update(int direction);
        void updateWindowBoundsCollision(const sf::RenderWindow* window); 
        const sf::Vector2f& getPosition() const;
        sf::Sprite getPlayerSprite();
        void renderInGame();
        void move2();
        void initMoveVariable();
        void updateAnimation(int direction);

        //changing Skin
        void changeSkinLeft();
        void changeSkinRight();
        void updatePlayerTexture(int skinIndex);
        
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