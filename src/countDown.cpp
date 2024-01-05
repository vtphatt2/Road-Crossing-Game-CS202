#include "header/countDown.hpp"

CountDown::CountDown(sf::RenderWindow* window, std::stack <State*>* states, std::vector <Lane*> &laneVector, std::vector <Stuff*> &stuffVector, Player* player, sf::View* view) 
        : window(window), states(states), laneVector(laneVector), stuffVector(stuffVector), player(player), view(view)
{
    initShape();
}

void CountDown::initShape() {
    font.loadFromFile("../resource/Inter-Bold.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color(0xD6, 0xB0, 0x8D));
    text.setOutlineThickness(4);
    text.setOutlineColor(sf::Color(0x37, 0x00, 0x00));
    blurLayer.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    blurLayer.setFillColor(sf::Color(255, 255, 255, 100));

    countDownBuffer.loadFromFile("../resource/audio/count-down.wav");
    countDownSound.setBuffer(countDownBuffer);
    countDownSound.play();
}

void CountDown::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void CountDown::update() {
    blurLayer.setPosition(view->getCenter().x - window->getSize().x / 2, view->getCenter().y - window->getSize().y / 2);
    text.setString(std::to_string(count));
    text.setPosition(view->getCenter().x - text.getLocalBounds().width/2, view->getCenter().y - text.getLocalBounds().height/2 - 50);

    text.setCharacterSize(sizeIncrease);
    sizeIncrease += 7;
    if (sizeIncrease > 300) {
        sizeIncrease = 0;
        --count;
    }

    if (count == 0) {
        delete states->top();
        states->pop();
    }
}

void CountDown::render() {
    for (int i = 0 ; i < laneVector.size() ; ++i) {
        window->draw(*laneVector[i]);
    }
    for (int i = 0 ; i < stuffVector.size() ; ++i) {
        window->draw(*stuffVector[i]);
    }
    window->draw(player->getPlayerSprite());
    window->draw(blurLayer);
    window->draw(text);
}