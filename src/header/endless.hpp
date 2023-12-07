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
#include "player.hpp"
#include "lose.hpp"

class Player;
class Lose;
class Endless : public State
{
    public:
        sf::View *view;
        sf::Time Time;
        sf::Clock Clock;
        int windowTranslateY;
        bool isAddNewLane = 0;
        Endless(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music);
        void initShape();
        void handleEvent();
        void update();
        void render();
        void playerCollision(std::vector<Stuff*> stuffVector);
        
    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        sf::Music& music;
        Player* player;
        int choice;
        std::vector<Stuff*> stuffVector;
        Setting* setting;
        std::vector<Lane*> laneVector;
        int desert = 0, garden = 0, snow = 0;
        int cont_path = 0, cont_road = 0;
        int points = 0;
        bool railed = false, rivered = false, iced = false;
        Lane* desertLane();
        Lane* gardenLane();
        Lane* snowLane();
        sf::SoundBuffer gameOverBuffer;
        sf::Sound gameOverSound;
        sf::RenderTexture renderTexture;
        sf::Shader blurShader;
        sf::Clock gameOverClock; 
};

#endif