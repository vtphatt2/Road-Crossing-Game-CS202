#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <stack>
#include "state.hpp"
#include "instruction.hpp"
#include "character.hpp"
#include "mode.hpp"

class Menu: public State {
    public :
        Menu(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void handleEvent();
        void update();
        void render();

    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;

        sf::Event event;

        sf::Vector2i mousePosition;

        int choice;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;
        sf::IntRect backgroundRect;

        sf::Texture menuBarTexture;
        sf::Sprite menuBarImage;

        sf::Texture menuSquareTexture;
        sf::Sprite menuSquareImage;

        sf::Texture newGameButtonTexture;
        sf::Sprite newGameButtonImage;
        sf::IntRect newGameButtonRect;

        sf::Texture loadGameButtonTexture;
        sf::Sprite loadGameButtonImage;
        sf::IntRect loadGameButtonRect;

        sf::Texture highScoreButtonTexture;
        sf::Sprite highScoreButtonImage;
        sf::IntRect highScoreButtonRect;

        sf::Texture settingsButtonTexture;
        sf::Sprite settingsButtonImage;
        sf::IntRect settingsButtonRect;

        sf::Texture instructionButtonTexture;
        sf::Sprite instructionButtonImage;
        sf::IntRect instructionButtonRect;
};

#endif