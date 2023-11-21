#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "entry.hpp"

class Game {
    public :
        Game();
        ~Game();
        void run();
        void playMusic();
        void stopMusic();
        void pauseMusic();
        void toggleMusic();
        int getStatusMusic();

    private :
        const int widthWindow;
        const int heightWindow;
        sf::Event event;
        sf::RenderWindow* window;
        std::stack <State*> states;
        sf::Music music;

        void handleEvent();
        void update();
        void render();
};

#endif
