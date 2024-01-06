#ifndef SETTINGMENU_HPP
#define SETTINGMENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <stack>
#include "state.hpp"
#include "game.hpp"

class Game;
class SettingMenu: public State {
    public :
        SettingMenu(sf::RenderWindow* window, std::stack <State*>* states, sf::Music &music);
        void initShape();
        void handleEvent();
        void update();
        void render();
        void updateButtonTextures();
        void updateVolumeText();
        void stopMusic();
        void pauseMusic();
        void toggleMusic();
        int getStatusMusic();
        void setMusicVolume(float volume);
        float getMusicVolume() const;
        float increaseVolume();
        float decreaseVolume();
        void restartGame();

    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        sf::Font font;
        sf::Text volumeText;
        sf::Music& music;
        float musicVolume = 50.f;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;

        sf::Texture soundTitleTexture;
        sf::Sprite soundTitleImage;

        sf::Texture volumeTitleTexture;
        sf::Sprite volumeTitleImage;

        sf::Texture soundButtonTexture;
        sf::Sprite soundButtonImage;
        sf::IntRect soundButtonRect;

        sf::Texture upButtonTexture;
        sf::Sprite upButtonImage;
        sf::IntRect upButtonRect;

        sf::Texture downButtonTexture;
        sf::Sprite downButtonImage;
        sf::IntRect downButtonRect;
        
        sf::Texture backButtonTexture;
        sf::Sprite backButtonImage;
        sf::IntRect backButtonRect;

        sf::Texture restartButtonTexture;
        sf::Sprite restartButtonImage;
        sf::IntRect restartButtonRect;
};

#endif