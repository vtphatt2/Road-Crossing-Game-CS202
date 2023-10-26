#include "header/game.hpp"
#include <SFML/Graphics.hpp>

Game::Game() {
    widthWindow = 1430;
    heightWindow = 990;
    level = 1;
    highScore = 0;
    score = 0;
}

void Game::run() {
    sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow), "ROAD CROSSING");
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) 
                window.close();
        }
    }
}