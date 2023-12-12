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

class Level : public State
{
    public:
        Level(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);
        virtual void initShape();
        void handleEvent();
        virtual void update();
        virtual void render();
        virtual int getLevel();
        virtual void playerCollision(std::vector<Stuff*> stuffVector);
        virtual void gameOver();
        virtual void notBridge();
        virtual void win();
        
    protected:
        sf::View *view;
        sf::Time Time;
        sf::Clock Clock;
        int windowTranslateY;
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        sf::Music& music;
        Player* player;
        std::vector<Stuff*> stuffVector;
        Setting* setting;
        std::vector<Lane*> laneVector;
        int level;

        sf::SoundBuffer gameOverBuffer;
        sf::Sound gameOverSound;

        sf::Time increaseSpeedTime;
        sf::Time increaseSpeedClock;
        float speedCoe = 1.0;
};

class Level_1 : public Level
{
    public:
        Level_1(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);
};


class Level_2 : public Level
{
    public:
        Level_2(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);
};

class Level_3 : public Level
{
    public:
        Level_3(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);
};

class Level_4 : public Level
{
    public:
        Level_4(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);
};

class Level_5 : public Level
{
    public:
        Level_5(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);
};

class Level_6 : public Level
{
    public:
        Level_6(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);
};

class Level_7 : public Level
{
    public:
        Level_7(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);
};

class Level_8 : public Level
{
    public:
        Level_8(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);
};

class Level_9 : public Level
{
    public:
        Level_9(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);

};

class Level_10 : public Level
{
    public:
        Level_10(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);

};

class Level_11 : public Level
{
    public:
        Level_11(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);

};

class Level_12 : public Level
{
    public:
        Level_12(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level);

};

#endif