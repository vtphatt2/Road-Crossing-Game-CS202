#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "entry.hpp"
#include "lose.hpp"

class Game {
    public :
        Game();
        ~Game();
        void run();

    private :
        const int widthWindow;
        const int heightWindow;
        sf::Event event;
        sf::RenderWindow* window;
        std::stack <State*> states;
        sf::Music music;
        Player* player;

        void setup();
        
        void handleEvent();
        void update();
        void render();
};

#endif
