#include "header/game.hpp"

Game::Game() : widthWindow(1430),  heightWindow(990) {
    level = 1;
    highScore = 0;
    score = 0;
    currentState = GameState::Entry;
    window.create(sf::VideoMode(widthWindow, heightWindow), "ROAD CROSSING");
}

void Game::run() {
    while (window.isOpen()) {
        if (currentState == GameState::Entry) {
            runEntry();
        }
        else if (currentState == GameState::Menu) {
            runMenu();
        }
    }
}

void Game::runEntry() {
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("../resource/Splash_Screen.png");
    sf::Sprite backgroundImage(backgroundTexture);
    backgroundImage.setPosition(0, -70);

    sf::Texture playButtonTexture;
    playButtonTexture.loadFromFile("../resource/Play_Button.png");
    sf::Sprite playButtonImage(playButtonTexture);
    playButtonImage.setPosition(673, 636);
    playButtonImage.setColor(sf::Color(255, 255, 255, 220));
    sf::IntRect playButtonRect(673, 636, 84, 84);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                
                case sf::Event::MouseButtonPressed :
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                        if (playButtonRect.contains(mousePosition)) {
                            currentState = GameState::Menu;
                            return ;
                        }
                    }
                    break;
    
                default :
                    break;
            }
        }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        if (playButtonRect.contains(mousePosition)) {
            playButtonImage.setColor(sf::Color(255, 255, 255, 255));
        } 
        else {
            playButtonImage.setColor(sf::Color(255, 255, 255, 200));
        }

        window.clear();
        window.draw(backgroundImage);
        window.draw(playButtonImage);
        window.display();
    }
}

void Game::runMenu() {
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("../resource/Menu.png");
    sf::Sprite backgroundImage(backgroundTexture);
    backgroundImage.setPosition(0, -125);

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