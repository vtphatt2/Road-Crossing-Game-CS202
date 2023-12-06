#ifndef LOSE_HPP
#define LOSE_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "setting_ingame.hpp"
#include "lane.hpp"
#include"stuff.hpp"
#include "player.hpp"

class Lose{
    public:
        Lose(sf::RenderWindow* window, std::stack <State*>* states, Player* player);

    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        Player* player;

};

#endif 