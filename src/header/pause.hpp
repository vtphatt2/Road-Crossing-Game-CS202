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

class Player;

class Pause : public State {
    public :
        Pause(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player, std::vector<Stuff*> &stuffVector, std::vector<Lane*> &laneVector);
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
        std::vector<Stuff*> &stuffVector;
        std::vector<Lane*> &laneVector;

        sf::RectangleShape blurLayer;

        sf::Texture boardTexture;
        sf::Sprite boardImage;
};

#endif