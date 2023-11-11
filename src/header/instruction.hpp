#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "state.hpp"

class Instruction: public State {
    public :
        Instruction(sf::RenderWindow* window, std::stack <State*>* states);
        void initShape();
        void handleEvent();
        void update();
        void render();

    private :
        sf::RenderWindow* window;
        std::stack <State*>* states;
        sf::Event event;
        sf::Vector2i mousePosition;


        sf::Texture backgroundTexture;
        sf::Sprite backgroundImage;

        sf::Font font;
        sf::Text text[5];
        std::string message[5];
        bool finishPrint[5];
        sf::Clock clock;
        const float delay ;
        float elapsedTime;
        std::size_t charIndex;
        std::string displayedText;

        sf::Texture backButtonTexture;
        sf::Sprite backButtonImage;
        sf::IntRect backButtonRect;
};

#endif