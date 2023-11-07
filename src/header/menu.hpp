#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include <stack>

class Menu: public State {
    public :
        Menu(sf::RenderWindow* window, std::stack <State*>* states);
        void initRectChoice();
        void handleEvent();
        void update();
        void render();

    private :
        sf::RenderWindow* window;
        sf::Event event;
        std::stack <State*>* states;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;
        sf::RectangleShape rectChoice;

        sf::RectangleShape rectChoices[5];
};

#endif