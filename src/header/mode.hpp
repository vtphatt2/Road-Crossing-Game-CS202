#ifndef MODE_HPP
#define MODE_HPP

#include <SFML/Graphics.hpp>
#include <stack>
#include "state.hpp"
#include "character.hpp"
#include "endless.hpp"
#include "classic.hpp"

class Mode : public State
{
    public:
        Mode(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void handleEvent();
        void update();
        void render();
    private:
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;
        int choice;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;

        sf::Texture ClassicButtonTexture;
        sf::Sprite ClassicButtonImage;
        sf::IntRect ClassicButtonRect;

        sf::Texture EndlessButtonTexture;
        sf::Sprite EndlessButtonImage;
        sf::IntRect EndlessButtonRect;

        sf::Texture SettingButtonTexture;
        sf::Sprite SettingButtonImage;
        sf::IntRect SettingButtonRect;

        sf::Texture backButtonTexture;
        sf::Sprite backButtonImage;
        sf::IntRect backButtonRect;
};

#endif