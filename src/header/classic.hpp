#ifndef CLASSIC_HPP
#define CLASSIC_HPP

#include <SFML/Graphics.hpp>
#include <stack>
#include "state.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include "setting_ingame.hpp"
#include "player.hpp"
#include "lane.hpp"
#include"stuff.hpp"
#include "player.hpp"
#include "lose.hpp"
#include "lane.hpp"

class Player;

class Levels : public State
{
    public:
        Levels(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music);
        void initShape();
        void handleEvent();
        void update();
        void render();
    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        sf::Music& music;
        Player* player;
        
        sf::SoundBuffer gameOverBuffer;
        sf::Sound gameOverSound; 

        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;

        sf::Texture backButtonTexture;
        sf::Sprite backButtonImage;
        sf::IntRect backButtonRect;

        sf::Texture levelBarTexture;
        sf::Sprite levelBarImage;

        sf::Texture levelsBoxTexture;
        sf::Sprite levelsBoxImage;

        sf::Texture level1ButtonTexture;
        sf::Sprite level1ButtonImage;
        sf::IntRect level1ButtonRect;

        sf::Texture level2ButtonTexture;
        sf::Sprite level2ButtonImage;
        sf::IntRect level2ButtonRect;

        sf::Texture level3ButtonTexture;
        sf::Sprite level3ButtonImage;
        sf::IntRect level3ButtonRect;

        sf::Texture level4ButtonTexture;
        sf::Sprite level4ButtonImage;
        sf::IntRect level4ButtonRect;

        sf::Texture level5ButtonTexture;
        sf::Sprite level5ButtonImage;
        sf::IntRect level5ButtonRect;

        sf::Texture level6ButtonTexture;
        sf::Sprite level6ButtonImage;
        sf::IntRect level6ButtonRect;

        sf::Texture level7ButtonTexture;
        sf::Sprite level7ButtonImage;
        sf::IntRect level7ButtonRect;

        sf::Texture level8ButtonTexture;
        sf::Sprite level8ButtonImage;
        sf::IntRect level8ButtonRect;

        sf::Texture level9ButtonTexture;
        sf::Sprite level9ButtonImage;
        sf::IntRect level9ButtonRect;

        sf::Texture level10ButtonTexture;
        sf::Sprite level10ButtonImage;
        sf::IntRect level10ButtonRect;

        sf::Texture level11ButtonTexture;
        sf::Sprite level11ButtonImage;
        sf::IntRect level11ButtonRect;

        sf::Texture level12ButtonTexture;
        sf::Sprite level12ButtonImage;
        sf::IntRect level12ButtonRect;
};

class Level_1 : public State 
{
    public:
        sf::View *view;
        sf::Time Time;
        sf::Clock Clock;
        int windowTranslateY;
        Level_1(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music);
        void initShape();
        void handleEvent();
        void update();
        void render();
        void playerCollision(std::vector<Stuff*> stuffVector);
        void gameOver();
    
    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        sf::Music& music;
        Player* player;
        std::vector<Stuff*> stuffVector;
        Setting* setting;
        std::vector<Lane*> laneVector;

        sf::SoundBuffer gameOverBuffer;
        sf::Sound gameOverSound;

        sf::Time increaseSpeedTime;
        sf::Time increaseSpeedClock;
        float speedCoe = 1.0;
};

#endif