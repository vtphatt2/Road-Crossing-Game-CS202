#include "header/pause.hpp"

Pause::Pause(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player, std::vector<Stuff*> &stuffVector, std::vector<Lane*> &laneVector)
    : window(window), states(states), music(music), player(player), stuffVector(stuffVector), laneVector(laneVector)
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
    boardImage.setPosition(367, 216);  
}

void Pause::handleEvent() {
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void Pause::update() {

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
}