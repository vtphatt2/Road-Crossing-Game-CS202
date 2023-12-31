#include "header/highScore.hpp"

highScore::highScore(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    font.loadFromFile("../resource/Inter-Bold.ttf");
    initShape();
}

void highScore::initShape() {
    backgroundTexture.loadFromFile("../resource/HighScore_Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    backButtonTexture.loadFromFile("../resource/Back_Button.png");
    backButtonImage.setTexture(backButtonTexture);
    backButtonImage.setPosition(60, 25);

    goldTexture.loadFromFile("../resource/highscore/gold.png");
    goldImage.setTexture(goldTexture);
    goldImage.setPosition(550, 533);

    silverTexture.loadFromFile("../resource/highscore/silver.png");
    silverImage.setTexture(silverTexture);
    silverImage.setPosition(550, 626);

    bronzeTexture.loadFromFile("../resource/highscore/bronze.png");
    bronzeImage.setTexture(bronzeTexture);
    bronzeImage.setPosition(550, 719);

    for (int i = 0 ; i < 3 ; ++i) {
        text[i].setFont(font);
        text[i].setCharacterSize(64);
        text[i].setFillColor(sf::Color(0xD6, 0xB0, 0x8D));
        text[i].setOutlineThickness(4);
        text[i].setOutlineColor(sf::Color(0x37, 0x00, 0x00));
    }

    loadScore();
    
    text[0].setPosition(680, 533);
    text[1].setPosition(680, 626);
    text[2].setPosition(680, 719);
}

void highScore::loadScore() {
    int first, second, third;
    std::ifstream fin("../data/score.txt");
    fin >> first >> second >> third;
    fin.close();

    text[0].setString(std::to_string(first));
    text[1].setString(std::to_string(second));
    text[2].setString(std::to_string(third));
}

void highScore::handleEvent() {
    while (window->pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed) 
            window->close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) 
                states->pop();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                mousePosition = sf::Mouse::getPosition(*window);
                if (backButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
                    states->pop();
            }
        }
    }
}

void highScore::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if (backButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
       backButtonImage.setColor(sf::Color(255, 255, 255, 255)) ;  
    else   
        backButtonImage.setColor(sf::Color(255, 255, 255, 200));
}

void highScore::render() {
    window->draw(backgroundImage);
    window->draw(backButtonImage);
    window->draw(goldImage);
    window->draw(silverImage);
    window->draw(bronzeImage);
    window->draw(text[0]);
    window->draw(text[1]);
    window->draw(text[2]);
}