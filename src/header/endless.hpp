#ifndef ENDLESS_HPP
#define ENDLESS_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <set>
#include "state.hpp"
#include "setting_ingame.hpp"
#include "lane.hpp"
#include "stuff.hpp"
#include "player.hpp"
#include "lose.hpp"
#include "lane.hpp"
#include "win.hpp"
#include "weather.hpp"
#include "countDown.hpp"

class Player;
class Lose;
class Win;
enum class laneType;
class Bridge;
class Weather;
class Setting;

class Endless : public State
{
    public:
        sf::View* view = nullptr;
        sf::Time Time;
        sf::Clock Clock;
        int windowTranslateY;
        bool isAddNewLane = 0;
        Endless(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music);
        Endless(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int a);
        ~Endless();
        void initShape();
        void handleEvent();
        void update();
        void render();
        void playerCollision(std::vector<Stuff*> stuffVector);
        void eatCredit();
        void increaseScore(int offset);
        void gameOver();
        void notBridge();
        void saveToFile(std::string fileName);
        void rainy();

        // LOAD GAME
        void loadSkinFromFile(std::string fileName);
        void loadPositionFromFile(std::string fileName);
        void loadLane(std::string fileName);
        void clearDataLoadGame();
        void updateHighScore(std::string fileName);
        void setup();

    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        sf::Music& music;
        Player* player;
        int choice;
        int level;
        std::vector <Stuff*> stuffVector;
        Setting* setting = nullptr;
        std::vector <Lane*> laneVector;
        int desert = 0, garden = 0, snow = 0;
        int cont_path = 0, cont_road = 0;
        int points = 0;
        bool railed = false, rivered = false, iced = false;
        Lane* desertLane();
        Lane* gardenLane();
        Lane* snowLane();
        Weather* weather;

        sf::Texture scoreBoardTexture;
        sf::Sprite scoreBoardImage;
        sf::IntRect scoreBoardRect;

        sf::SoundBuffer gameOverBuffer;
        sf::Sound gameOverSound; 

        sf::Time increaseSpeedTime;
        sf::Clock increaseSpeedClock;
        float speedCoe = 1.0;

        bool isGameOver = 0;
        bool isRaining = false;
        sf::Clock Rain;

        int score;
        bool save = true;
        sf::Font font;
        sf::Text scoreText;  
        int count = 0;
        sf::SoundBuffer coinEatenBuffer;
        sf::Sound coinEaten; 

        bool countedDown = false;
        bool die = false;
        bool initialMusicStatus = music.getStatus() == sf::SoundSource::Status::Playing;
};

#endif
