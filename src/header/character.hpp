#ifndef CHARACTER_HPP
#define CHARACTER_HPP
const int NUM_CHARACTERS = 5;

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "state.hpp"
#include "../header/mode.hpp"

class Character: public State {
    public :
        Character(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void initCharacter();
        void handleEvent();
        void update();
        void render();
        void changeCharacterRight();
        void changeCharacterLeft();
        int getCurrentCharacterIndex() const;

    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;


        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;

        sf::Texture playGameButtonTexture;
        sf::Sprite playGameButtonImage;
        sf::IntRect playGameButtonRect;

        sf::Texture rightArrowButtonTexture;
        sf::Sprite rightArrowButtonImage;
        sf::IntRect rightArrowButtonRect;

        sf::Texture leftArrowButtonTexture;
        sf::Sprite leftArrowButtonImage;
        sf::IntRect leftArrowButtonRect;

        sf::Texture backButtonTexture;
        sf::Sprite backButtonImage;
        sf::IntRect backButtonRect;

        sf::Texture CharacterTextture;
        sf::Sprite CharacterImage;

        int currentCharacterIndex;  
        sf::Texture characterTextures[NUM_CHARACTERS];  
        sf::Sprite characterImages[NUM_CHARACTERS];   
        
};

#endif