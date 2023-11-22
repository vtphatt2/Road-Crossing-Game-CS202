#include "header/endless.hpp"
#include<iostream>
Endless::Endless(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    setting = new Setting(window, states);

    initShape();
}

void Endless::initShape() {
    view = new sf::View;
    view->setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    view->setCenter(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
    windowTranslateY = 0;
    
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        laneVector.push_back(new Lane(randomLaneType()));
        laneVector[i]->setPosition(0, 990 - landHeight * (i + 1));
    }
}

void Endless::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::A)) {
            int translateY = landHeight / 15; // replace by the actual playerSpeed
            view->move(sf::Vector2f(0, -translateY));
            windowTranslateY -= translateY;
            setting->moveUp(-translateY);
            if (-windowTranslateY % landHeight == 0) {
                isAddNewLane = 1;
            }
        }
        setting->handleEvent(event);
    }
}

void Endless::update() {
    setting->update();
    if (isAddNewLane) {
        int i = laneVector.size();
        laneVector.push_back(new Lane(randomLaneType()));
        laneVector[laneVector.size() - 1]->setPosition(0, 990 - landHeight * (i + 1));
        isAddNewLane = 0;
    }

}

void Endless::render() {
    window->setView(*view);
    for (int i = 0; i < laneVector.size(); i++) {
        window->draw(*laneVector[i]);
    }
    window->draw(*setting);
}