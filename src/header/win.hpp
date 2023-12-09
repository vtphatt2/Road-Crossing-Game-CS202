#ifndef WIN_HPP
#define WIN_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "player.hpp"
#include "menu.hpp"

class Player;
class Menu;
class Win: public State{
    public:
        Win(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, sf::Texture background, int level);
        void handleEvent();
        void update();
        void render();
        void initShape();
        void pushNewLevel();

    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        sf::Music& music;
        sf::Texture background;
        int currentLevel;
        Player* player;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;

        sf::Texture boardTexture;
        sf::Sprite boardImage;

        sf::Texture winTexture;
        sf::Sprite winImage;

        sf::Texture starTexture;
        sf::Sprite starImage;

        sf::Text level;
        sf::Font font;

        sf::Texture nextButtonTexture;
        sf::Sprite nextButtonImage;
        sf::IntRect nextButtonRect;

        sf::Texture menuButtonTexture;
        sf::Sprite menuButtonImage;
        sf::IntRect menuButtonRect;

};

#endif 