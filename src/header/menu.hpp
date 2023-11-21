#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stack>
#include "state.hpp"
#include "instruction.hpp"
#include "character.hpp"
#include "mode.hpp"
#include "highScore.hpp"
#include "setting_menu.hpp"
#include "game.hpp"

class Menu: public State {
    public :
        Menu(sf::RenderWindow* window, std::stack <State*>* states, sf::Music* music);
        void handleEvent();
        void update();
        void render();
        void initShape();

    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Music* music;

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

        sf::Texture backButtonTexture;
        sf::Sprite backButtonImage;
        sf::IntRect backButtonRect;
};

#endif