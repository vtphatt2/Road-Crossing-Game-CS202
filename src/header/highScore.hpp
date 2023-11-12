#ifndef HIGH_SCRORE_HPP
#define HIGH_SCRORE_HPP

#include <SFML/Graphics.hpp>
#include <stack>
#include <cstring>
#include <fstream>
#include <queue>
#include "state.hpp"

class highScore : public State {
    public :
        highScore(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void loadScore();
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
        sf::Texture backButtonTexture;
        sf::Sprite backButtonImage;

        sf::Font font;
        sf::Text text[3];

        sf::Texture goldTexture;
        sf::Sprite goldImage;
        sf::Texture silverTexture;
        sf::Sprite silverImage;
        sf::Texture bronzeTexture;
        sf::Sprite bronzeImage;
};

#endif
