#include "header/pause.hpp"

Pause::Pause(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player, std::vector<Stuff*> &stuffVector, std::vector<Lane*> &laneVector, sf::View* view)
    : window(window), states(states), music(music), player(player), stuffVector(stuffVector), laneVector(laneVector), view(view)
{
    music.stop();
    initShape();
}

Pause::~Pause() {
    music.play();
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
                states->push(new Endless(window, states, player, music));
            }
            else if (continueImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y - window->getSize().y / 2 + view->getCenter().y)) {
                music.play();
                states->pop();
            }
            else if (menuImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y - window->getSize().y / 2 + view->getCenter().y)) {
                while (!states->empty()) states->pop();
                music.play();
                window->setView(window->getDefaultView());
                states->push(new Menu(window, states, music, player));
            }
        }
    }
}

void Pause::update() {
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