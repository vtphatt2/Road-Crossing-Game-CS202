#include "header/game.hpp"

Game::Game() : widthWindow(1430),  heightWindow(990) {
    level = 1;
    highScore = 0;
    score = 0;
}

void Game::run() {
    sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow), "ROAD CROSSING");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("../resource/Splash_Screen.png");
    sf::Sprite backgroundImage(backgroundTexture);
    backgroundImage.setPosition(0, -50);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                
                default :
                    break;
            }
        }

        window.clear();
        window.draw(backgroundImage);
        window.display();
    }
}
