#ifndef ENTRY_H
#define ENTRY_H

#include "state.hpp"
#include <stack>
#include <SFML/Graphics.hpp>
#include "menu.hpp"

class Entry : public State {
    public :
        Entry(sf::RenderWindow* window, std::stack <State*>* states);
        void handleEvent();
        void update();
        void render();
        
    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;
        sf::Texture playButtonTexture;
        sf::Sprite playButtonImage;
        sf::IntRect playButtonRect;
};

#endif
