#ifndef CLASSIC_HPP
#define CLASSIC_HPP

#include <SFML/Graphics.hpp>
#include <stack>
#include "state.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include "setting_ingame.hpp"
class Classic : public State
{
    public:
        Classic(sf::RenderWindow* window, std::stack <State*>* states);
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