#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "state.hpp"
#include "character.hpp"

class Player:public Character{
    public: 
        Player(sf::RenderWindow* window, std::stack <State*>* states);
        virtual ~Player(); 
        void initPlayer(int characterIndex);
        void reset(); 
        void move(); 
        void updateWindowBoundsCollision(); 
        void changeCharacter(const std::string& newCharacterTexture) {};
        void update();
        void render(); 
        void handleEvent();

        int getChosenCharacterIndex() const;
        sf::Sprite getCharacter();

    private: 
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;

        sf::Texture characterText;
        sf::Sprite character;
        
        sf::Time time = sf::seconds(0.05f); 
        sf::Clock clock;
        const float movementSpeed = 50.f; 
        void initPlayer();     

};
#endif