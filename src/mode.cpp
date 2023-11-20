#include "header/mode.hpp"

Mode::Mode(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();

}

void Mode::initShape() {
    backgroundTexture.loadFromFile("../resource/Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    ClassicButtonTexture.loadFromFile("../resource/Classic_Board.png");
    ClassicButtonImage.setTexture(ClassicButtonTexture);
    ClassicButtonImage.setPosition(440, 260);
    ClassicButtonImage.setColor(sf::Color(255, 255, 255, 220));
    ClassicButtonRect.left = 440;
    ClassicButtonRect.top = 260;
    ClassicButtonRect.width = ClassicButtonImage.getGlobalBounds().width;
    ClassicButtonRect.height = ClassicButtonImage.getGlobalBounds().height;

    EndlessButtonTexture.loadFromFile("../resource/Endless_Board.png");
    EndlessButtonImage.setTexture(EndlessButtonTexture);
    EndlessButtonImage.setPosition(440, 550);
    EndlessButtonImage.setColor(sf::Color(255, 255, 255, 220));
    EndlessButtonRect.left = 440;
    EndlessButtonRect.top = 550;
    EndlessButtonRect.width = EndlessButtonImage.getGlobalBounds().width;
    EndlessButtonRect.height = EndlessButtonImage.getGlobalBounds().height;

    backButtonTexture.loadFromFile("../resource/Back_Button.png");
    backButtonImage.setTexture(backButtonTexture);
    backButtonImage.setPosition(window->getSize().x - 1410, window->getSize().y - 970);
    backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    backButtonRect.left = backButtonImage.getPosition().x;
    backButtonRect.top = backButtonImage.getPosition().y;
    backButtonRect.width = backButtonImage.getGlobalBounds().width;
    backButtonRect.height = backButtonImage.getGlobalBounds().height;
}

void Mode::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
      
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }

        if (event.type == sf::Event::KeyPressed) {
            // press left arrow key to turn back the previous window
            if (event.key.code == sf::Keyboard::Left) {
                states->pop();
            }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            // Check if the classic button is clicked
            if (ClassicButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Classic(window, states));
            }

            // Check if the endless button is clicked
            if (EndlessButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Endless(window, states));
            }
            if (backButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->pop();
            }
        }
    }
}

void Mode::update() {
    if (ClassicButtonRect.contains(sf::Mouse::getPosition(*window))) {
        ClassicButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        ClassicButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }

    if (EndlessButtonRect.contains(sf::Mouse::getPosition(*window))) {
        EndlessButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        EndlessButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if (backButtonRect.contains(sf::Mouse::getPosition(*window))) {
        backButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
}

void Mode::render() {
    window->draw(backgroundImage);
    window->draw(ClassicButtonImage);
    window->draw(EndlessButtonImage);
    window->draw(backButtonImage);
}