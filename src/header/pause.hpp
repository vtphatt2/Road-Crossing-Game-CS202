#ifndef PAUSE_HPP
#define PAUSE_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "setting_ingame.hpp"
#include "player.hpp"
#include "stuff.hpp"
#include "lane.hpp"
#include "countDown.hpp"

class Player;

class Pause : public State {
    public :
        Pause(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player, std::vector<Stuff*> &stuffVector, std::vector<Lane*> &laneVector, sf::View* view, int currentLevel);
        void initShape();
        void handleEvent();
        void update();
        void render();
        ~Pause();

    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        sf::Music &music;
        Player* player;
        sf::View* view;
        std::vector<Stuff*> &stuffVector;
        std::vector<Lane*> &laneVector;
        int level;

        sf::RectangleShape blurLayer;
 
        sf::Texture boardTexture;
        sf::Sprite boardImage;

        sf::Texture messageTexture;
        sf::Sprite messageImage;

        sf::Texture pauseTexture;
        sf::Sprite pauseImage;

        sf::IntRect restartRect;
        sf::Texture restartTexture;
        sf::Sprite restartImage;

        sf::Texture continueTexture;
        sf::Sprite continueImage;

        sf::Texture menuTexture;
        sf::Sprite menuImage;
};

#endif