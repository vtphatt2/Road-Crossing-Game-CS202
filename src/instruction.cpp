#include "header/instruction.hpp"

Instruction::Instruction(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states), delay(0.1f) {
    initShape();

    elapsedTime = 0.0f;
    charIndex = 0;
    displayedText = "";

    message[0] = "A  : move left";
    message[1] = "D  : move right";
    message[2] = "W  : move forward";
    message[3] = "S  : move backward";
    message[4] = "P  : pause";
}

void Instruction::initShape() {
    font.loadFromFile("../resource/Inter-Bold.ttf");
    backgroundTexture.loadFromFile("../resource/Instruction.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    for (int i = 0 ; i < 5 ; ++i) {
        text[i].setFont(font);
        text[i].setCharacterSize(64);
        text[i].setFillColor(sf::Color(0xD6, 0xB0, 0x8D));
        text[i].setOutlineThickness(4);
        text[i].setOutlineColor(sf::Color(0x37, 0x00, 0x00));
        text[i].setString("");

        finishPrint[i] = false;
    }

    text[0].setPosition(130, 200);
    text[1].setPosition(130, 280);
    text[2].setPosition(110, 360);
    text[3].setPosition(130, 440);
    text[4].setPosition(130, 520);
}

void Instruction::handleEvent() {
    while (window->pollEvent(event)) {
        switch (event.type) 
        {
            case sf::Event::Closed :
                window->close();
                break;

            case sf::Event::KeyPressed :
                switch (event.key.code) {
                    case sf::Keyboard::Enter :
                        for (int i = 0 ; i < 5 ; ++i) {
                            finishPrint[i] = true;
                            text[i].setString(message[i]);
                        }
                        break;

                    case sf::Keyboard::Left :
                        states->pop();
                        break;

                    default :
                        break ;
                }

            default :
                break;
        }
    }
}

void Instruction::update() {
    for (int i = 0 ; i < 5 ; ++i) {
        if (finishPrint[i]) continue ;
        if (i >= 1 && !finishPrint[i - 1]) continue;

        elapsedTime += clock.restart().asSeconds();
        if (elapsedTime >= delay && charIndex < message[i].size()) {
            displayedText += message[i][charIndex];
            text[i].setString(displayedText);
            ++charIndex;
            elapsedTime = 0.0f;
        }
        else if (charIndex == message[i].size()) {
            finishPrint[i] = true;
            text[i].setString(message[i]);
            elapsedTime = 0.0f;
            charIndex = 0;
            displayedText = "";
        }
    }
}

void Instruction::render() {
    window->draw(backgroundImage);
    for (int i = 0 ; i < 5 ; ++i) {
        window->draw(text[i]);
    }
}