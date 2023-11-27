#ifndef CHARACTER_HPP
#define CHARACTER_HPP
const int NUM_CHARACTERS = 5;

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "state.hpp"
#include "../header/mode.hpp"
#include "player.hpp"

class Player; // Forward declaration of Player class

class Character: public State {
    public :
        Character(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void handleEvent();
        void update();
        void render();

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

        Player* player;
};

#endif