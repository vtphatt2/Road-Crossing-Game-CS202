#include "header/classic.hpp"

Levels::Levels(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music) : window(window), states(states), player(player), music(music) 
{
    initShape();
    if (!gameOverBuffer.loadFromFile("../resource/audio/gameOver.wav")) {
        cout << "Cannot load soundfile" << endl;
    }
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
}

void Levels::initShape()
{
    backgroundTexture.loadFromFile("../resource/Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    backButtonTexture.loadFromFile("../resource/Back_Button.png");
    backButtonImage.setTexture(backButtonTexture);
    backButtonImage.setPosition(27, 27);
    backButtonRect.left = backButtonImage.getPosition().x;
    backButtonRect.top = backButtonImage.getPosition().y;
    backButtonRect.width = backButtonTexture.getSize().x;
    backButtonRect.height = backButtonTexture.getSize().y;

    levelBarTexture.loadFromFile("../resource/classic/level_bar.png");
    levelBarImage.setTexture(levelBarTexture);
    levelBarImage.setPosition(396, 37);

    levelsBoxTexture.loadFromFile("../resource/classic/levels_box.png");
    levelsBoxImage.setTexture(levelsBoxTexture);
    levelsBoxImage.setPosition(222, 253);

    level1ButtonTexture.loadFromFile("../resource/classic/level1_box.png");
    level1ButtonImage.setTexture(level1ButtonTexture);
    level1ButtonImage.setPosition(300, 311);
    level1ButtonRect.left = level1ButtonImage.getPosition().x;
    level1ButtonRect.top = level1ButtonImage.getPosition().y;
    level1ButtonRect.width = level1ButtonTexture.getSize().x;
    level1ButtonRect.height = level1ButtonTexture.getSize().y;

    level2ButtonTexture.loadFromFile("../resource/classic/level2_box.png");
    level2ButtonImage.setTexture(level2ButtonTexture);
    level2ButtonImage.setPosition(514, 311);
    level2ButtonRect.left = level2ButtonImage.getPosition().x;
    level2ButtonRect.top = level2ButtonImage.getPosition().y;
    level2ButtonRect.width = level2ButtonTexture.getSize().x;
    level2ButtonRect.height = level2ButtonTexture.getSize().y;

    level3ButtonTexture.loadFromFile("../resource/classic/level3_box.png");
    level3ButtonImage.setTexture(level3ButtonTexture);
    level3ButtonImage.setPosition(743, 311);
    level3ButtonRect.left = level3ButtonImage.getPosition().x;
    level3ButtonRect.top = level3ButtonImage.getPosition().y;
    level3ButtonRect.width = level3ButtonTexture.getSize().x;
    level3ButtonRect.height = level3ButtonTexture.getSize().y;

    level4ButtonTexture.loadFromFile("../resource/classic/level4_box.png");
    level4ButtonImage.setTexture(level4ButtonTexture);
    level4ButtonImage.setPosition(974, 311);
    level4ButtonRect.left = level4ButtonImage.getPosition().x;
    level4ButtonRect.top = level4ButtonImage.getPosition().y;
    level4ButtonRect.width = level4ButtonTexture.getSize().x;
    level4ButtonRect.height = level4ButtonTexture.getSize().y;

    level5ButtonTexture.loadFromFile("../resource/classic/level5_box.png");
    level5ButtonImage.setTexture(level5ButtonTexture);
    level5ButtonImage.setPosition(300, 517);
    level5ButtonRect.left = level5ButtonImage.getPosition().x;
    level5ButtonRect.top = level5ButtonImage.getPosition().y;
    level5ButtonRect.width = level5ButtonTexture.getSize().x;
    level5ButtonRect.height = level5ButtonTexture.getSize().y;

    level6ButtonTexture.loadFromFile("../resource/classic/level6_box.png");
    level6ButtonImage.setTexture(level6ButtonTexture);
    level6ButtonImage.setPosition(514, 517);
    level6ButtonRect.left = level6ButtonImage.getPosition().x;
    level6ButtonRect.top = level6ButtonImage.getPosition().y;
    level6ButtonRect.width = level6ButtonTexture.getSize().x;
    level6ButtonRect.height = level6ButtonTexture.getSize().y;

    level7ButtonTexture.loadFromFile("../resource/classic/level7_box.png");
    level7ButtonImage.setTexture(level7ButtonTexture);
    level7ButtonImage.setPosition(743, 517);
    level7ButtonRect.left = level7ButtonImage.getPosition().x;
    level7ButtonRect.top = level7ButtonImage.getPosition().y;
    level7ButtonRect.width = level7ButtonTexture.getSize().x;
    level7ButtonRect.height = level7ButtonTexture.getSize().y;

    level8ButtonTexture.loadFromFile("../resource/classic/level8_box.png");
    level8ButtonImage.setTexture(level8ButtonTexture);
    level8ButtonImage.setPosition(974, 517);
    level8ButtonRect.left = level8ButtonImage.getPosition().x;
    level8ButtonRect.top = level8ButtonImage.getPosition().y;
    level8ButtonRect.width = level8ButtonTexture.getSize().x;
    level8ButtonRect.height = level8ButtonTexture.getSize().y;

    level9ButtonTexture.loadFromFile("../resource/classic/level9_box.png");
    level9ButtonImage.setTexture(level9ButtonTexture);
    level9ButtonImage.setPosition(300, 723);
    level9ButtonRect.left = level9ButtonImage.getPosition().x;
    level9ButtonRect.top = level9ButtonImage.getPosition().y;
    level9ButtonRect.width = level9ButtonTexture.getSize().x;
    level9ButtonRect.height = level9ButtonTexture.getSize().y;

    level10ButtonTexture.loadFromFile("../resource/classic/level10_box.png");
    level10ButtonImage.setTexture(level10ButtonTexture);
    level10ButtonImage.setPosition(514, 723);
    level10ButtonRect.left = level10ButtonImage.getPosition().x;
    level10ButtonRect.top = level10ButtonImage.getPosition().y;
    level10ButtonRect.width = level10ButtonTexture.getSize().x;
    level10ButtonRect.height = level10ButtonTexture.getSize().y;

    level11ButtonTexture.loadFromFile("../resource/classic/level11_box.png");
    level11ButtonImage.setTexture(level11ButtonTexture);
    level11ButtonImage.setPosition(743, 723);
    level11ButtonRect.left = level11ButtonImage.getPosition().x;
    level11ButtonRect.top = level11ButtonImage.getPosition().y;
    level11ButtonRect.width = level11ButtonTexture.getSize().x;
    level11ButtonRect.height = level11ButtonTexture.getSize().y;

    level12ButtonTexture.loadFromFile("../resource/classic/level12_box.png");
    level12ButtonImage.setTexture(level12ButtonTexture);
    level12ButtonImage.setPosition(974, 723);
    level12ButtonRect.left = level12ButtonImage.getPosition().x;
    level12ButtonRect.top = level12ButtonImage.getPosition().y;
    level12ButtonRect.width = level12ButtonTexture.getSize().x;
    level12ButtonRect.height = level12ButtonTexture.getSize().y;
}

void Levels::handleEvent()
{
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (backButtonRect.contains(sf::Mouse::getPosition(*window))) {
                states->pop();
            }
            // if (level1ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level1(window, states));
            // }
            // if (level2ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level2(window, states));
            // }
            // if (level3ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level3(window, states));
            // }
            // if (level4ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level4(window, states));
            // }
            // if (level5ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level5(window, states));
            // }
            // if (level6ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level6(window, states));
            // }
            // if (level7ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level7(window, states));
            // }
            // if (level8ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level8(window, states));
            // }
            // if (level9ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level9(window, states));
            // }
            // if (level10ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level10(window, states));
            // }
            // if (level11ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level11(window, states));
            // }
            // if (level12ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            //     states->push(new Level12(window, states));
            // }
        }
    }
}

void Levels::update()
{
    if(backButtonRect.contains(sf::Mouse::getPosition(*window))) {
        backButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level1ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level1ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level1ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level2ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level2ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level2ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level3ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level3ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level3ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level4ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level4ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level4ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level5ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level5ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level5ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level6ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level6ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level6ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level7ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level7ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level7ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level8ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level8ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level8ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level9ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level9ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level9ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level10ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level10ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level10ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level11ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level11ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level11ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(level12ButtonRect.contains(sf::Mouse::getPosition(*window))) {
        level12ButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        level12ButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
}

void Levels::render()
{
    window->draw(backgroundImage);
    window->draw(backButtonImage);
    window->draw(levelBarImage);
    window->draw(levelsBoxImage);
    window->draw(level1ButtonImage);
    window->draw(level2ButtonImage);
    window->draw(level3ButtonImage);
    window->draw(level4ButtonImage);
    window->draw(level5ButtonImage);
    window->draw(level6ButtonImage);
    window->draw(level7ButtonImage);
    window->draw(level8ButtonImage);
    window->draw(level9ButtonImage);
    window->draw(level10ButtonImage);
    window->draw(level11ButtonImage);
    window->draw(level12ButtonImage);
}