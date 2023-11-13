#ifndef SETTINGMENU_HPP
#define SETTINGMENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <stack>
#include "state.hpp"

class SettingMenu: public State {
    public :
        SettingMenu(sf::RenderWindow* window, std::stack<State*>* states, sf::Music& music);
        void initShape();
        void handleEvent();
        void update();
        void render();
        void updateButtonTextures();

    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;

        bool isSoundOn = true;
        sf::Music& music;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;

        sf::Texture soundTitleTexture;
        sf::Sprite soundTitleImage;

        sf::Texture soundButtonTexture;
        sf::Sprite soundButtonImage;
        sf::IntRect soundButtonRect;
        
        sf::Texture backButtonTexture;
        sf::Sprite backButtonImage;
        sf::IntRect backButtonRect;
};

#endif

class SoundSettings {
private:
    static bool isSoundOn;
    SoundSettings() {}

public:
    static bool getIsSoundOn() {
        return isSoundOn;
    }

    static void setIsSoundOn(bool value) {
        isSoundOn = value;
    }
};