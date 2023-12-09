#include "header/win.hpp"
#include<iostream>
Win::Win(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, sf::Texture background, int level) : window(window), states(states), music(music), 
background(background), currentLevel(level), player(player) {
    window->setView(window->getDefaultView());
    initShape();
    player->setMovementSpeed(10.0f);
}

void Win::initShape() {
    backgroundImage.setTexture(background);
    backgroundImage.setPosition(0, 0); 
    backgroundImage.setColor(sf::Color(255, 255, 255, 90));

    boardTexture.loadFromFile("../resource/lose/Board.png");
    boardImage.setTexture(boardTexture);
    boardImage.setPosition(367, 216);  

    winTexture.loadFromFile("../resource/lose/win.png");
    winImage.setTexture(winTexture);
    winImage.setPosition(318, 44); 

    starTexture.loadFromFile("../resource/lose/star.png");
    starImage.setTexture(starTexture);
    starImage.setPosition(window->getSize().x / 2.0f - starImage.getGlobalBounds().width / 2.0f, 423); 

    nextButtonTexture.loadFromFile("../resource/lose/next.png");
    nextButtonImage.setTexture(nextButtonTexture);
    nextButtonImage.setPosition(579, 677);
    nextButtonImage.setColor(sf::Color(255, 255, 255, 220));
    nextButtonRect.left = nextButtonImage.getPosition().x;  
    nextButtonRect.top = nextButtonImage.getPosition().y;  
    nextButtonRect.width = nextButtonImage.getGlobalBounds().width;
    nextButtonRect.height = nextButtonImage.getGlobalBounds().height;

    menuButtonTexture.loadFromFile("../resource/lose/menu.png");
    menuButtonImage.setTexture(menuButtonTexture);
    menuButtonImage.setPosition(719, 677);
    menuButtonImage.setColor(sf::Color(255, 255, 255, 220));
    menuButtonRect.left = menuButtonImage.getPosition().x;    
    menuButtonRect.top = menuButtonImage.getPosition().y;  
    menuButtonRect.width = menuButtonImage.getGlobalBounds().width;
    menuButtonRect.height = menuButtonImage.getGlobalBounds().height;

    if (!font.loadFromFile("../resource/Inter-Bold.ttf")) {
        cout << "Error" <<endl;
    }

    level.setFont(font);
    level.setString("Level " + to_string(currentLevel));
    level.setCharacterSize(70);
    level.setFillColor(sf::Color(214, 176, 141)); // #D6B08D in RGB
    level.setStyle(sf::Text::Bold);
    float outlineThickness = 3.0f;
    level.setOutlineColor(sf::Color(174, 118, 64));
    level.setOutlineThickness(outlineThickness);    

    sf::FloatRect textBounds = level.getLocalBounds();
    float centerX = window->getSize().x / 2.0f - textBounds.width / 2.0f;
    level.setPosition(centerX, 315);
}

void Win::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (menuButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Menu(window, states, music));
            }
            if (nextButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                pushNewLevel();
            }
        }
    }
}

void Win::pushNewLevel(){
    if (currentLevel == 1) states->push(new Level_2(window, states, player, music));
    if (currentLevel == 2) states->push(new Level_3(window, states, player, music));
    if (currentLevel == 3) states->push(new Level_4(window, states, player, music));
    if (currentLevel == 4) states->push(new Level_5(window, states, player, music));
    if (currentLevel == 5) states->push(new Level_6(window, states, player, music));
    // if (currentLevel == 6) states->push(new Level_7(window, states, player, music));
    // if (currentLevel == 7) states->push(new Level_8(window, states, player, music));
    // if (currentLevel == 8) states->push(new Level_9(window, states, player, music));
    // if (currentLevel == 9) states->push(new Level_10(window, states, player, music));
    // if (currentLevel == 10) states->push(new Level_11(window, states, player, music));
}



void Win::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if (nextButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        nextButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        nextButtonImage.setColor(sf::Color(255, 255, 255, 150));

    if (menuButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        menuButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        menuButtonImage.setColor(sf::Color(255, 255, 255, 200));
}

void Win::render() {
    window->draw(backgroundImage);
    window->draw(boardImage);
    window->draw(winImage);
    window->draw(starImage);
    window->draw(nextButtonImage);
    window->draw(menuButtonImage);
    window->draw(level);
}