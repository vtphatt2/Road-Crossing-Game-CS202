#include "header/lose.hpp"

Lose::Lose(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, sf::Texture background, Player* player, int level, int score) : window(window), states(states), music(music), background(background), player(player), currentLevel(level), score(score) {
    window->setView(window->getDefaultView());
    initShape();
}

void Lose::initShape() {
    backgroundImage.setTexture(background);
    backgroundImage.setPosition(0, 0); 
    backgroundImage.setColor(sf::Color(255, 255, 255, 90));

    boardTexture.loadFromFile("../resource/lose/Board.png");
    boardImage.setTexture(boardTexture);
    boardImage.setPosition(367, 216);  

    loseTexture.loadFromFile("../resource/lose/lose.png");
    loseImage.setTexture(loseTexture);
    loseImage.setPosition(318, 44); 

    scoreTitleTexture.loadFromFile("../resource/lose/scoreTitle.png");
    scoreTitleImage.setTexture(scoreTitleTexture);
    scoreTitleImage.setPosition(609, 315);
    
    restartButtonTexture.loadFromFile("../resource/lose/restart.png");
    restartButtonImage.setTexture(restartButtonTexture);
    restartButtonImage.setPosition(579, 677);
    restartButtonImage.setColor(sf::Color(255, 255, 255, 220));
    restartButtonRect.left = restartButtonImage.getPosition().x;  
    restartButtonRect.top = restartButtonImage.getPosition().y;  
    restartButtonRect.width = restartButtonImage.getGlobalBounds().width;
    restartButtonRect.height = restartButtonImage.getGlobalBounds().height;

    menuButtonTexture.loadFromFile("../resource/lose/menu.png");
    menuButtonImage.setTexture(menuButtonTexture);
    menuButtonImage.setPosition(719, 677);
    menuButtonImage.setColor(sf::Color(255, 255, 255, 220));
    menuButtonRect.left = menuButtonImage.getPosition().x;    
    menuButtonRect.top = menuButtonImage.getPosition().y;  
    menuButtonRect.width = menuButtonImage.getGlobalBounds().width;
    menuButtonRect.height = menuButtonImage.getGlobalBounds().height;

    font.loadFromFile("../resource/Inter-Bold.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(64);
    scoreText.setFillColor(sf::Color(0xD6, 0xB0, 0x8D));
    scoreText.setOutlineThickness(4);
    scoreText.setOutlineColor(sf::Color(0x37, 0x00, 0x00));
    scoreText.setString(std::to_string(score));

    scoreText.setOrigin(scoreText.getLocalBounds().left + scoreText.getLocalBounds().width / 2.0f, scoreText.getLocalBounds().top + scoreText.getLocalBounds().height / 2.0f);
    scoreText.setPosition(window->getSize().x / 2.0f, 480);
}

void Lose::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (menuButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                while (!states->empty()) states->pop();
                states->push(new Menu(window, states, music, player));
            }
            if (restartButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                while (!states->empty()) states->pop();
                if(currentLevel == 0)
                    states->push(new Endless(window, states, player, music));
                else if(currentLevel == 1)
                    states->push(new Level_1(window, states, player, music, 1));
                else if(currentLevel == 2)
                    states->push(new Level_2(window, states, player, music, 2));
                else if(currentLevel == 3)
                    states->push(new Level_3(window, states, player, music, 3));
                else if(currentLevel == 4)
                    states->push(new Level_4(window, states, player, music, 4));
                else if(currentLevel == 5)
                    states->push(new Level_5(window, states, player, music, 5));
                else if(currentLevel == 6)
                    states->push(new Level_6(window, states, player, music, 6));
                else if(currentLevel == 7)
                    states->push(new Level_7(window, states, player, music, 7));
                else if(currentLevel == 8)
                    states->push(new Level_8(window, states, player, music, 8));
                else if(currentLevel == 9)
                    states->push(new Level_9(window, states, player, music, 9));
                else if(currentLevel == 10)
                    states->push(new Level_10(window, states, player, music, 10));
                // else if(currentLevel == 11)
                //     states->push(new Level_11(window, states, player, music, 11));
                // else if(currentLevel == 12)
                //     states->push(new Level_12(window, states, player, music, 12));
            }
        }
    }
}

void Lose::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if (restartButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        restartButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        restartButtonImage.setColor(sf::Color(255, 255, 255, 150));

    if (menuButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        menuButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        menuButtonImage.setColor(sf::Color(255, 255, 255, 200));
}

void Lose::render() {
    window->draw(backgroundImage);
    window->draw(boardImage);
    window->draw(loseImage);
    window->draw(restartButtonImage);
    window->draw(menuButtonImage);
    window->draw(scoreTitleImage);
    window->draw(scoreText);
}