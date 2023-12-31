#include "header/instruction.hpp"

Instruction::Instruction(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states), delay(0.05f) {
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

    text[0].setPosition(130, 370);
    text[1].setPosition(130, 450);
    text[2].setPosition(110, 530);
    text[3].setPosition(130, 610);
    text[4].setPosition(130, 690);

    backButtonTexture.loadFromFile("../resource/Back_Button.png");
    backButtonImage.setTexture(backButtonTexture);
    backButtonImage.setPosition(20, 20);
    backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    backButtonRect.left = backButtonImage.getPosition().x;
    backButtonRect.top = backButtonImage.getPosition().y;
    backButtonRect.width = backButtonImage.getGlobalBounds().width;
    backButtonRect.height = backButtonImage.getGlobalBounds().height;

    buttonATexture.loadFromFile("../resource/instruction/A_Button.png");
    buttonSTexture.loadFromFile("../resource/instruction/S_Button.png");
    buttonDTexture.loadFromFile("../resource/instruction/D_Button.png");
    buttonWTexture.loadFromFile("../resource/instruction/W_Button.png");
    buttonPTexture.loadFromFile("../resource/instruction/P_Button.png");
    buttonAImage.setTexture(buttonATexture);
    buttonSImage.setTexture(buttonSTexture);
    buttonDImage.setTexture(buttonDTexture);
    buttonWImage.setTexture(buttonWTexture);
    buttonPImage.setTexture(buttonPTexture);
    buttonAImage.setPosition(854, 505);
    buttonSImage.setPosition(1018, 508);
    buttonDImage.setPosition(1189, 505);
    buttonWImage.setPosition(1021, 340);
    buttonPImage.setPosition(1255, 340);
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
                    case sf::Keyboard::Escape :
                        window->close();
                    default :
                        break ;
                }

            default :
                break;
        }
        if(backButtonRect.contains(sf::Mouse::getPosition(*window))) {
            backButtonImage.setColor(sf::Color(255, 255, 255, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    states->pop();
                }
            }
        } else {
            backButtonImage.setColor(sf::Color(255, 255, 255, 220));
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

    if (backButtonRect.contains(sf::Mouse::getPosition(*window))) 
        backButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else
        backButtonImage.setColor(sf::Color(255, 255, 255, 220));
}

void Instruction::render() {
    window->draw(backgroundImage);
    for (int i = 0 ; i < 5 ; ++i) {
        window->draw(text[i]);
    }
    if (finishPrint[0]) window->draw(buttonAImage);
    if (finishPrint[1]) window->draw(buttonSImage);
    if (finishPrint[2]) window->draw(buttonDImage);
    if (finishPrint[3]) window->draw(buttonWImage);
    if (finishPrint[4]) window->draw(buttonPImage);

    window->draw(backButtonImage);
}