#ifndef ENDLESS_HPP
#define ENDLESS_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "setting_ingame.hpp"
#include "lane.hpp"
#include "stuff.hpp"
#include "player.hpp"
#include "lose.hpp"
#include "lane.hpp"
#include "win.hpp"

class Player;
class Lose;
class Win;
enum class laneType;
class Bridge;
class Endless : public State
{
    public:
        sf::View *view;
        sf::Time Time;
        sf::Clock Clock;
        int windowTranslateY;
        bool isAddNewLane = 0;
        Endless(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music);
        ~Endless();
        void initShape();
        void handleEvent();
        void update();
        void render();
        void playerCollision(std::vector<Stuff*> stuffVector);
        void eatCredit();
        void gameOver();
        void notBridge();
        
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

        sf::Texture scoreBoardTexture;
        sf::Sprite scoreBoardImage;
        sf::IntRect scoreBoardRect;

        sf::SoundBuffer gameOverBuffer;
        sf::Sound gameOverSound; 

        sf::Time increaseSpeedTime;
        sf::Clock increaseSpeedClock;
        float speedCoe = 1.0;

        bool isGameOver = 0;
};

#endif