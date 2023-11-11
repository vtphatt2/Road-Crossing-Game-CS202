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

    SettingButtonTexture.loadFromFile("../resource/Setting.png");
    SettingButtonImage.setTexture(SettingButtonTexture);
    SettingButtonImage.setPosition(1300, 890);
    SettingButtonImage.setColor(sf::Color(255, 255, 255, 220));
    SettingButtonRect.left = 1300;
    SettingButtonRect.top = 890;
    SettingButtonRect.width = SettingButtonImage.getGlobalBounds().width;
    SettingButtonRect.height = SettingButtonImage.getGlobalBounds().height;

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
            if (SettingButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Setting(window, states));
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
    if (SettingButtonRect.contains(sf::Mouse::getPosition(*window))) {
        SettingButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        SettingButtonImage.setColor(sf::Color(255, 255, 255, 220));
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
    window->draw(SettingButtonImage);
    window->draw(backButtonImage);
}

Classic::Classic(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();
}

void Classic::initShape() {
    backgroundTexture.loadFromFile("../resource/Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    SettingButtonTexture.loadFromFile("../resource/Setting.png");
    SettingButtonImage.setTexture(SettingButtonTexture);
    SettingButtonImage.setPosition(1300, 890);
    SettingButtonImage.setColor(sf::Color(255, 255, 255, 220));
    SettingButtonRect.left = 1300;
    SettingButtonRect.top = 890;
    SettingButtonRect.width = SettingButtonImage.getGlobalBounds().width;
    SettingButtonRect.height = SettingButtonImage.getGlobalBounds().height;
}

void Classic::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
        if(event.type == sf::Event::MouseButtonPressed) {
            if (SettingButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Setting(window, states));
            }
        }
    }
}

void Classic::update() {
    if (SettingButtonRect.contains(sf::Mouse::getPosition(*window))) {
        SettingButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        SettingButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
}

void Classic::render() {
    window->draw(backgroundImage);
    window->draw(SettingButtonImage);
}

Endless::Endless(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();
}

void Endless::initShape() {
    backgroundTexture.loadFromFile("../resource/Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    SettingButtonTexture.loadFromFile("../resource/Setting.png");
    SettingButtonImage.setTexture(SettingButtonTexture);
    SettingButtonImage.setPosition(1300, 890);
    SettingButtonImage.setColor(sf::Color(255, 255, 255, 220));
    SettingButtonRect.left = 1300;
    SettingButtonRect.top = 890;
    SettingButtonRect.width = SettingButtonImage.getGlobalBounds().width;
    SettingButtonRect.height = SettingButtonImage.getGlobalBounds().height;
}

void Endless::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
        if(event.type == sf::Event::MouseButtonPressed) {
            if (SettingButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->push(new Setting(window, states));
            }
        }
    }
}

void Endless::update() {
    if (SettingButtonRect.contains(sf::Mouse::getPosition(*window))) {
        SettingButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        SettingButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
}

void Endless::render() {
    window->draw(backgroundImage);
    window->draw(SettingButtonImage);
}

Setting::Setting(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();
}

void Setting::initShape() {
    backgroundTexture.loadFromFile("../resource/Setting_Board.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);
}

void Setting::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
    }
}

void Setting::update() {

}

void Setting::render() {
    window->draw(backgroundImage);
}