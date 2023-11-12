#include "header/menu.hpp"

Menu::Menu(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states), choice(-1) {
    initShape();
}

void Menu::initShape() {
    backgroundTexture.loadFromFile("../resource/Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    menuSquareTexture.loadFromFile("../resource/menu/Menu_Square.png");
    menuSquareImage.setTexture(menuSquareTexture);
    menuSquareImage.setPosition(362, 280);

    int x = 500;
    int y = 280 + 80;

    menuBarTexture.loadFromFile("../resource/menu/Menu_Bar.png");
    menuBarImage.setTexture(menuBarTexture);
    menuBarImage.setPosition(362, 100);

    newGameButtonTexture.loadFromFile("../resource/menu/New_Game_Bar.png");
    newGameButtonImage.setTexture(newGameButtonTexture);
    newGameButtonImage.setPosition(539, y);
    newGameButtonRect.left = 539;
    newGameButtonRect.top = y;
    newGameButtonRect.width = newGameButtonTexture.getSize().x;
    newGameButtonRect.height = newGameButtonTexture.getSize().y;
    y += 100;

    loadGameButtonTexture.loadFromFile("../resource/menu/Load_Game_Bar.png");
    loadGameButtonImage.setTexture(loadGameButtonTexture);
    loadGameButtonImage.setPosition(534, y);
    loadGameButtonRect.left = 534;
    loadGameButtonRect.top = y;
    loadGameButtonRect.width = loadGameButtonTexture.getSize().x;
    loadGameButtonRect.height = loadGameButtonTexture.getSize().y;
    y += 100;

    highScoreButtonTexture.loadFromFile("../resource/menu/High_Score_Bar.png");
    highScoreButtonImage.setTexture(highScoreButtonTexture);
    highScoreButtonImage.setPosition(526, y);
    highScoreButtonRect.left = 526;
    highScoreButtonRect.top = y;
    highScoreButtonRect.width = highScoreButtonTexture.getSize().x;
    highScoreButtonRect.height = highScoreButtonTexture.getSize().y;
    y += 100;

    settingsButtonTexture.loadFromFile("../resource/menu/Settings_Bar.png");
    settingsButtonImage.setTexture(settingsButtonTexture);
    settingsButtonImage.setPosition(562, y);
    settingsButtonRect.left = 562;
    settingsButtonRect.top = y;
    settingsButtonRect.width = settingsButtonTexture.getSize().x;
    settingsButtonRect.height = settingsButtonTexture.getSize().y;
    y += 100;

    instructionButtonTexture.loadFromFile("../resource/menu/Instruction_Bar.png");
    instructionButtonImage.setTexture(instructionButtonTexture);
    instructionButtonImage.setPosition(502, y);
    instructionButtonRect.left = 502;
    instructionButtonRect.top = y;
    instructionButtonRect.width = instructionButtonTexture.getSize().x;
    instructionButtonRect.height = instructionButtonTexture.getSize().y;
    y += 100;

    backButtonTexture.loadFromFile("../resource/Back_Button.png");
    backButtonImage.setTexture(backButtonTexture);
    backButtonImage.setPosition(20, 20);
    backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    backButtonRect.left = backButtonImage.getPosition().x;
    backButtonRect.top = backButtonImage.getPosition().y;
    backButtonRect.width = backButtonImage.getGlobalBounds().width;
    backButtonRect.height = backButtonImage.getGlobalBounds().height;
}

void Menu::handleEvent() {
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed :
                window->close();
                break;

            case sf::Event::MouseMoved :
                mousePosition = sf::Mouse::getPosition(*window);
                break ;

            case sf::Event::KeyPressed :
                if (event.key.code == sf::Keyboard::Left) {
                    states->pop();
                }
                if (event.key.code == sf::Keyboard::Escape) {
                    window->close();
                }
                break;
            default :
                break;
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (newGameButtonRect.contains(mousePosition.x, mousePosition.y)) {
                states->push(new Character(window, states));
            }
            //else if (loadGameButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            //    states->push(new LoadGame(window, states));
            //}
            else if (highScoreButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
               states->push(new highScore(window, states));
            }
            else if (settingsButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
               states->push(new SettingMenu(window, states));
            }
            else if (instructionButtonRect.contains(mousePosition.x, mousePosition.y)) {
                states->push(new Instruction(window, states));
            }
            else if (backButtonRect.contains(mousePosition.x, mousePosition.y)) {
                states->pop();
            }
        }
    }
}

void Menu::update() {
    if (newGameButtonRect.contains(mousePosition.x, mousePosition.y)) {
        newGameButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        newGameButtonImage.setColor(sf::Color(255, 255, 255, 200));
    }

    if (loadGameButtonRect.contains(mousePosition.x, mousePosition.y)) {
        loadGameButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        loadGameButtonImage.setColor(sf::Color(255, 255, 255, 200));
    }

    if (highScoreButtonRect.contains(mousePosition.x, mousePosition.y)) {
        highScoreButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        highScoreButtonImage.setColor(sf::Color(255, 255, 255, 200));
    }

    if (settingsButtonRect.contains(mousePosition.x, mousePosition.y)) {
        settingsButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        settingsButtonImage.setColor(sf::Color(255, 255, 255, 200));
    }

    if (instructionButtonRect.contains(mousePosition.x, mousePosition.y)) {
        instructionButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        instructionButtonImage.setColor(sf::Color(255, 255, 255, 200));
    }
    if (backButtonRect.contains(mousePosition.x, mousePosition.y)) {
        backButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        backButtonImage.setColor(sf::Color(255, 255, 255, 200));
    }
}

void Menu::render() {
    window->draw(backgroundImage);
    window->draw(menuBarImage);
    window->draw(menuSquareImage);
    window->draw(newGameButtonImage);
    window->draw(loadGameButtonImage);
    window->draw(highScoreButtonImage);
    window->draw(settingsButtonImage);
    window->draw(instructionButtonImage);
    window->draw(backButtonImage);
}
