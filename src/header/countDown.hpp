#ifndef COUNT_DOWN_HPP
#define COUNT_DOWN_HPP

#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>
#include <cstring>
#include "state.hpp"
#include "stuff.hpp"
#include "lane.hpp"
#include "player.hpp"

class Player;

class CountDown : public State {
    public :
        CountDown(sf::RenderWindow* window, std::stack <State*>* states, std::vector <Lane*> &laneVector, std::vector <Stuff*> &stuffVector, Player* player, sf::View* view);
        void initShape();
        void handleEvent();
        void update();
        void render();
    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::View* view;
        sf::RectangleShape blurLayer;
        std::vector <Stuff*> stuffVector;
        std::vector <Lane*> laneVector;
        Player* player;
        sf::Font font;
        sf::Text text;
        int count = 3;
        int time = 0;
};

#endif