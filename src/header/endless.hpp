#ifndef ENDLESS_HPP
#define ENDLESS_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "setting_ingame.hpp"
#include "lane.hpp"
#include"stuff.hpp"
class Endless : public State
{
    public:
        sf::View *view;
        int windowTranslateY;
        bool isAddNewLane = 0;
        Endless(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void handleEvent();
        void update();
        void render();
        
    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        int choice;
        std::vector<Stuff*> stuffVector;
        Setting* setting;
        std::vector<Lane*> laneVector;
        int desert = 0, garden = 0, snow = 0;
        int num_rail = 0, cont_river = 0, cont_path = 0, cont_road = 0, cont_ice = 0;
        int points = 0;
        bool railed = false;

};

#endif