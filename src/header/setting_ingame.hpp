#ifndef SETTING_INGAME_HPP
#define SETTING_INGAME_HPP

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "state.hpp"
#include "instruction.hpp"

class Setting : public sf::Drawable
{
    public:
        Setting(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void handleEvent(sf::Event event);
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Vector2i mousePosition;

        
        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;

        sf::Texture FAQButtonTexture;
        sf::Sprite FAQButtonImage;
        sf::IntRect FAQButtonRect;

        sf::Texture leaderboardButtonTexture;
        sf::Sprite leaderboardButtonImage;
        sf::IntRect leaderboardButtonRect;

        sf::Texture settingButtonTexture;
        sf::Sprite settingButtonImage;
        sf::IntRect settingButtonRect;

        sf::Texture pauseButtonTexture;
        sf::Sprite pauseButtonImage;
        sf::IntRect pauseButtonRect;
};

class LeaderboardIngame : public State
{
    public:
        LeaderboardIngame(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void handleEvent();
        void update();
        void render();
    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;

        sf::Texture backButtonTexture;
        sf::Sprite backButtonImage;
        sf::IntRect backButtonRect;
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

class FAQ : public State
{
    public:
        FAQ(sf::RenderWindow* window, std::stack <State*>* states);
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

class Pause : public State
{
    public:
        Pause(sf::RenderWindow* window, std::stack <State*>* states);
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