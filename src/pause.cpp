#include "header/pause.hpp"

Pause::Pause(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player, std::vector<Stuff*> &stuffVector, std::vector<Lane*> &laneVector, sf::View* view, int currentLevel)
    : window(window), states(states), music(music), player(player), stuffVector(stuffVector), laneVector(laneVector), view(view), level(currentLevel)
{
    music.stop();
    initShape();
}

Pause::~Pause() {
    while (!states->empty()) {
        State* tmp =  states->top();
        states->pop();
        delete tmp;
    }
    window->setView(window->getDefaultView());
    states->push(new Menu(window, states, music, player));
}

void Pause::initShape() {
    blurLayer.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    blurLayer.setFillColor(sf::Color(255, 255, 255, 100));

    boardTexture.loadFromFile("../resource/lose/Board.png");
    boardImage.setTexture(boardTexture);
    boardImage.setPosition(view->getCenter().x - boardImage.getLocalBounds().width/2 + 30, view->getCenter().y - boardImage.getLocalBounds().height/2 + 100);

    pauseTexture.loadFromFile("../resource/pause/pause.png");
    pauseImage.setTexture(pauseTexture);
    pauseImage.setPosition(boardImage.getPosition().x - 39, boardImage.getPosition().y - 172);

    messageTexture.loadFromFile("../resource/pause/drinkacupoftea.png");
    messageImage.setTexture(messageTexture);
    messageImage.setPosition(boardImage.getPosition().x + 113, boardImage.getPosition().y + 145);

    restartTexture.loadFromFile("../resource/lose/restart.png");
    restartImage.setTexture(restartTexture);
    restartImage.setPosition(boardImage.getPosition().x + 155, boardImage.getPosition().y + 461);

    continueTexture.loadFromFile("../resource/pause/continue.png");
    continueImage.setTexture(continueTexture);
    continueImage.setPosition(boardImage.getPosition().x + 292, boardImage.getPosition().y + 461);

    menuTexture.loadFromFile("../resource/lose/menu.png");
    menuImage.setTexture(menuTexture);
    menuImage.setPosition(boardImage.getPosition().x + 429, boardImage.getPosition().y + 461);
}

void Pause::handleEvent() {
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
        {
            mousePosition = sf::Mouse::getPosition(*window);
            if (restartImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y - window->getSize().y / 2 + view->getCenter().y)) {
                states->pop();
                states->pop();
                music.play();
                if (level == 0) states->push(new Endless(window, states, player, music));
                else if (level == 1) states->push(new Level_1(window, states, player, music, 1));
                else if (level == 2) states->push(new Level_2(window, states, player, music, 2));
                else if (level == 3) states->push(new Level_3(window, states, player, music, 3));
                else if (level == 4) states->push(new Level_4(window, states, player, music, 4));
                else if (level == 5) states->push(new Level_5(window, states, player, music, 5));
                else if (level == 6) states->push(new Level_6(window, states, player, music, 6));
                else if (level == 7) states->push(new Level_7(window, states, player, music, 7));
                else if (level == 8) states->push(new Level_8(window, states, player, music, 8));
                else if (level == 9) states->push(new Level_9(window, states, player, music, 9));
                else if (level == 10) states->push(new Level_10(window, states, player, music, 10));
                else if (level == 11) states->push(new Level_11(window, states, player, music, 11));
                else if (level == 12) states->push(new Level_12(window, states, player, music, 12));
            }
            else if (continueImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y - window->getSize().y / 2 + view->getCenter().y)) {
                music.play();
                states->pop();
                states->push(new CountDown(window, states, laneVector, stuffVector, player, view));
            }
            else if (menuImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y - window->getSize().y / 2 + view->getCenter().y)) {
                State* tmp = states->top();                
                states->pop();
                delete tmp;
            }
        }
    }
}

void Pause::update() {
    blurLayer.setPosition(view->getCenter().x - window->getSize().x / 2, view->getCenter().y - window->getSize().y / 2);
    mousePosition = sf::Mouse::getPosition(*window);

    if (restartImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y - window->getSize().y / 2 + view->getCenter().y))
        restartImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        restartImage.setColor(sf::Color(255, 255, 255, 150));

    if (continueImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y - window->getSize().y / 2 + view->getCenter().y)) 
        continueImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        continueImage.setColor(sf::Color(255, 255, 255, 150));

    if (menuImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y - window->getSize().y / 2 + view->getCenter().y)) 
        menuImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        menuImage.setColor(sf::Color(255, 255, 255, 150));
}

void Pause::render() {
    for (int i = 0; i < laneVector.size(); i++) {
        window->draw(*laneVector[i]);
    }
    for (int i = 0; i < stuffVector.size(); i++)
    {
        window->draw(*stuffVector[i]);
    }
    window->draw(player->getPlayerSprite());
    window->draw(blurLayer);
    window->draw(boardImage);
    window->draw(pauseImage);
    window->draw(messageImage);
    window->draw(restartImage);
    window->draw(continueImage);
    window->draw(menuImage);
}