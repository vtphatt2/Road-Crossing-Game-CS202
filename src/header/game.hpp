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
        void playMusic();
        void stopMusic();
        void pauseMusic();
        void toggleMusic();
        int getStatusMusic();
        void setMusicVolume(float volume);
        float getMusicVolume() const;
        float increaseVolume();
        float decreaseVolume();

    private :
        const int widthWindow;
        const int heightWindow;
        sf::Event event;
        sf::RenderWindow* window;
        std::stack <State*> states;
        sf::Music music;
        Player* player;
        float musicVolume = 50.0f;


        void setup();
        void handleEvent();
        void update();
        void render();
};

#endif
