#ifndef SETTING_INGAME_HPP
#define SETTING_INGAME_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "instruction.hpp"
#include "player.hpp"
#include "pause.hpp"
#include "stuff.hpp"
#include "lane.hpp"

class Setting : public sf::Drawable
{
    public:
        Setting(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player, std::vector<Stuff*> &stuffVector, std::vector<Lane*> &laneVector, sf::View *view);
        Setting(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player, std::vector<Stuff*>& stuffVector, std::vector<Lane*>& laneVector, sf::View *view, int currentLevel);
        void initShape();
        void handleEvent(sf::Event event);
        void update();
        void move(int translateY);
        std::string positionComponents();
        void setPositionComponents(int x, int y);
    private:
        sf::View *view;
        
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Vector2i mousePosition;
        sf::Music &music;
        Player* player;
        std::vector<Stuff*> &stuffVector; 
        std::vector<Lane*> &laneVector;
        int level;

        sf::Texture pauseButtonTexture;
        sf::Sprite pauseButtonImage;
        sf::IntRect pauseButtonRect;
};

class SettingIngame : public State
{
    public:
        SettingIngame(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void handleEvent();
        void update();
        void render();
        void updateButtonTextures();
    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        
        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;
};

#endif