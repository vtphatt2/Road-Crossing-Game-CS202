#ifndef LOSE_HPP
#define LOSE_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "setting_ingame.hpp"
#include "player.hpp"
#include "menu.hpp"

class Player;
class Menu;
class Lose: public State{
    public:
        Lose(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, sf::Texture background, Player* player);
        void handleEvent();
        void update();
        void render();
        void initShape();

    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        sf::Music& music;
        Player* player;
        sf::Texture background;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;

        sf::Texture boardTexture;
        sf::Sprite boardImage;

        sf::Texture loseTexture;
        sf::Sprite loseImage;

        sf::Texture scoreTitleTexture;
        sf::Sprite scoreTitleImage;

        sf::Texture restartButtonTexture;
        sf::Sprite restartButtonImage;
        sf::IntRect restartButtonRect;

        sf::Texture menuButtonTexture;
        sf::Sprite menuButtonImage;
        sf::IntRect menuButtonRect;

};

#endif 