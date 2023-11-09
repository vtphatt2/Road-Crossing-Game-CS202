#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <stack>
#include "state.hpp"
#include "instruction.hpp"

class Menu: public State {
    public :
        Menu(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void initRectChoice();
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
        sf::RectangleShape rectChoice;
        sf::RectangleShape rectChoices[5];

};

#endif