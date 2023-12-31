#pragma once
#ifndef ENTRY_HPP
#define ENTRY_HPP

#include "state.hpp"
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "menu.hpp"
#include "player.hpp"

class Player;

class Game;

class Entry : public State {
    public :
        Entry(sf::RenderWindow* window, std::stack <State*>* states, sf::Music &music, Player* player);
        void initShape();
        void handleEvent();
        void update();
        void render();
        
    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;

        sf::Event event;
        sf::Vector2i mousePosition;
        sf::Music& music;
        Player* player;

        // material
        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;
        sf::Texture playButtonTexture;
        sf::Sprite playButtonImage;
        sf::IntRect playButtonRect;
};

#endif
