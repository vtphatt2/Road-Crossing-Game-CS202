#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "state.hpp"
#include "character.hpp"
#include <unordered_map>
#include <memory>

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
        void reset(); 
        void move(); 
        void update();
        void updateWindowBoundsCollision(const sf::RenderWindow& window); 
        const sf::Vector2f& getPosition() const;
        void changeSkinLeft();
        void changeSkinRight();
        void updatePlayerTexture(int skinIndex);
        sf::Sprite getPlayerSprite();

    private: 
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        PlayerSkin playerSkin; 
        
        const float movementSpeed = 50.f; 
};
#endif