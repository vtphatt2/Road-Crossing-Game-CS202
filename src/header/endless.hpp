#ifndef ENDLESS_HPP
#define ENDLESS_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "setting_ingame.hpp"

class Endless : public State
{
    public:
        Endless(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void handleEvent();
        void update();
        void render();
        Setting* setting;
    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        int choice;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;

};

#endif