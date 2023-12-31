#include "header/classic.hpp"

Levels::Levels(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music) : window(window), states(states), player(player), music(music) 
{
    initShape();
    
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
        if (level1ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_1(window, states, player, music, 1));
        }
        if (level2ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_2(window, states, player, music, 2));
        }
        if (level3ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_3(window, states, player, music, 3));
        }
        if (level4ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_4(window, states, player, music, 4));
        }
        if (level5ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_5(window, states, player, music, 5));
        }
        if (level6ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_6(window, states, player, music, 6));
        }
        if (level7ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_7(window, states, player, music, 7));
        }
        if (level8ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_8(window, states, player, music, 8));
        }
        if (level9ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_9(window, states, player, music, 9));
        }
        if (level10ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_10(window, states, player, music, 10));
        }
        if (level11ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_11(window, states, player, music, 11));
        }
        if (level12ButtonRect.contains(sf::Mouse::getPosition(*window))) {
            states->push(new Level_12(window, states, player, music, 12));
        }
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

Level::Level(sf::RenderWindow* window, std::stack<State*>* states, Player* player, sf::Music& music, int level)
    : window(window), states(states), player(player), music(music), level(level)
{
    weather = new Weather(window);
    if (!gameOverBuffer.loadFromFile("../resource/audio/gameOver.wav")) {
        std::cout << "Cannot load soundfile" << std::endl;
    }
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    player->setMovementSpeed(10.0f);
    initShape();
}

Level::~Level(){
    gameOverSound.stop();
    gameWinSound.stop();
    delete weather;
    weather = nullptr;
    delete view;
    view = nullptr;
}

void Level::initShape()
{
    view = new sf::View;
    view->setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    view->setCenter(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
    windowTranslateY = 0;

    Time = sf::Time::Zero;
    increaseSpeedTime = sf::Time::Zero;
    srand(time(0));

    int n = laneVector.size();
    for(int i = 0; i < n; i++)
    {
        laneVector[i]->setPosition(0, 990 - landHeight * (i + 1));
        for(int j = 0; j < laneVector[i]->getStuffVector().size(); j++)
        {
            stuffVector.push_back(laneVector[i]->getStuffVector()[j]);
        }
    }

    for (int i = 0 ; i < laneVector.size() ; ++i) {
        Coin* coins = laneVector[i]->getCoin();
        if (coins != nullptr) {
            coins[0].vanish();
            coins[1].vanish();
            coins[2].vanish();
        }
    }
}

void Level::handleEvent()
{
    const float movementSpeed = 10.0f; 
    int framesPerDirection = 2;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }        
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
        
        if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)) {
            player->update(static_cast<Direction>(1));
            player->updateWindowBoundsCollision(window, windowTranslateY);
        }
        else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)) {
            player->update(static_cast<Direction>(2));
            player->updateWindowBoundsCollision(window, windowTranslateY);
        }
        else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)){
            player->update(static_cast<Direction>(3));
            player->updateWindowBoundsCollision(window, windowTranslateY);
        }
        else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)){
            player->update(static_cast<Direction>(4));
            player->updateWindowBoundsCollision(window, windowTranslateY);
        }
        else {
            player->update(static_cast<Direction>(0));
        }
        setting->handleEvent(event);
    }
}

void Level::update()
{
    if (!countedDown) {
        countedDown = true;
        window->setView(*view);
        states->push(new CountDown(window, states, laneVector, stuffVector, player, view));
        return ;
    }
    
    if (isGameOver){
        weather->stopSound();
        gameOverSound.play();        
        player->setMovementSpeed(0);
        for (auto& stuff : stuffVector) {
            stuff->setSpeed(0);
        }

        sf::Texture backgroundTexture;
        backgroundTexture.create(window->getSize().x, window->getSize().y);
        backgroundTexture.update(*window);

        sf::Clock delayTimer;
        while (delayTimer.getElapsedTime().asSeconds() < 1.0f) {
            // Wait for 1 seconds
        }
        states->push(new Lose(window, states, music, backgroundTexture, player, getLevel(), 0));
    }
    setting->update();
    for (int i = 0; i < laneVector.size(); i++) laneVector[i]->update();
    bool gameRunning = true;
    Time = Clock.getElapsedTime();
    if (Time.asSeconds() >= 0.01) {
        view->move(0, -1);
        setting->move(-1);
        windowTranslateY += -1;
        player->updateWindowBoundsCollision(window, windowTranslateY);
        playerCollision(stuffVector); 
        if(level == 2 || level == 4) notBridge();
        rainy();
        Clock.restart();
    }

    for (const auto& lane : laneVector) {
        if (lane->type == laneType::snow_finish || lane->type == laneType::desert_finish || lane->type == laneType::garden_finish){
            float playerY = player->getPlayerSprite().getPosition().y;
            float laneY = lane->getPosition().y;
            float laneHeight = 165.f;
            if (playerY >= laneY && playerY <= laneY + laneHeight - 150){
                win();                
            }
        }
    }
}

void Level::render()
{
window->setView(*view);
    for (int i = 0; i < laneVector.size(); i++) {
        window->draw(*laneVector[i]);
    }
    window->draw(player->getPlayerSprite());
    for (int i = 0; i < stuffVector.size(); i++)
    {
        window->draw(*stuffVector[i]);
    }
    window->draw(*setting);
    if (isRaining){
        weather->drawRaindrops();
    }
}

int Level::getLevel() 
{
    return level;
}

void Level::win()
{
    if (!gameWinBuffer.loadFromFile("../resource/audio/gameWin.wav")) {
        std::cout << "Cannot load soundfile" << std::endl;
    }
    weather->stopSound();
    gameWinSound.setBuffer(gameWinBuffer);    
    gameWinSound.play();
    player->setMovementSpeed(0);
    for (auto& stuff : stuffVector) {
        stuff->setSpeed(0);
    }

    sf::Texture backgroundTexture;
    backgroundTexture.create(window->getSize().x, window->getSize().y);
    backgroundTexture.update(*window);

    sf::Clock delayTimer;
    while (delayTimer.getElapsedTime().asSeconds() < 2.0f) {
        // Wait for 2 seconds
    }
    states->push(new Win(window, states, player, music, backgroundTexture, getLevel()));
}

void Level::playerCollision(std::vector<Stuff*> stuffVector) 
{
    for (auto& stuff : stuffVector) {
        float negativeMargin = -5.0f;
        bool isCollision = player->isCollisionWithMargin(stuff->getGlobalBounds(), negativeMargin);
        if (isCollision) {
            die = 1;
            gameOver();
        }
    } 
}

void Level::gameOver() 
{
    isGameOver = 1;
    if (die) player->updatePlayerDie();
}

void Level::notBridge()
{
    laneType playerLaneType = laneType::river; 
    for (const auto& lane : laneVector) {
        if (player->getPlayerSprite().getPosition().y+92.f >= lane->getPosition().y && player->getPlayerSprite().getPosition().y +92.f < lane->getPosition().y + 165.f) {
            playerLaneType = lane->type;
            if (lane->type == laneType::river) {
                Bridge* bridges = lane->getBridge();
                sf::Vector2f bridge0 = bridges[0].getPosition();
                sf::Vector2f bridge1 = bridges[1].getPosition();
                sf::Vector2f playerB = player->getPlayerSprite().getPosition();
                if ((playerB.x >= bridge0.x && playerB.x <= bridge0.x + bridges[0].getGlobalBounds().width) || 
                (playerB.x >= bridge1.x && playerB.x <= bridge1.x + bridges[1].getGlobalBounds().width)){}
                else{
                    player->updatePlayerDrown();
                    sf::Vector2f pos = player->getPlayerSprite().getPosition();
                    player->getPlayerSprite().setPosition(pos);
                    gameOver();
                }
            }
        }
    }
}

void Level::rainy(){
    if (Rain.getElapsedTime().asSeconds() >= 20.0f){
        isRaining = rand() % 2; 
            if (isRaining==1){
            music.pause();
            weather->playSound();
            player->setMovementSpeed(5.0f);           
            Rain.restart();
        }
    }
    else if (isRaining && Rain.getElapsedTime().asSeconds() >= 5.0f) {
        isRaining = false;
        weather->stopSound();
        music.play();
        player->setMovementSpeed(10.0f);
    }

    if (isRaining){ 
        weather->startRain();   
        weather->updateRain(windowTranslateY);            
    }  
}

Level_1::Level_1(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level) 
{
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::garden_first_lane));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::garden_finish));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 1);
}

Level_2::Level_2(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level) 
{
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::garden_first_lane));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::garden_first_lane));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::garden_finish));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));  
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 2);
}

Level_3::Level_3(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level) 
{
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::garden_first_lane));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::garden_first_lane));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::garden_finish));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));  
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 3);
}

Level_4::Level_4(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level) 
{
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::garden_first_lane));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::garden_first_lane));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::rail)); 
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::river)); 
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::garden_finish));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));  
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 4);
}

Level_5::Level_5(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level) 
{

    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::desert_first_lane));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::desert_finish));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 5);
}

Level_6::Level_6(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level) 
{

    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::desert_first_lane));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_finish));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 6);
}

Level_7::Level_7(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level) 
{
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::snow_first_lane));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_finish));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 7);
}

Level_8::Level_8(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level) 
{

    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::snow_first_lane));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::snow_first_lane));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_finish));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));  
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 8);
}

Level_9::Level_9(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level)
{
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::snow_first_lane));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_finish));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 9);
};

Level_10::Level_10(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level)
{
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::snow_first_lane));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::snow_first_lane));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::rail)); 
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::snow_finish));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path)); 
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 10);
};

Level_11::Level_11(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level)
{
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::desert_first_lane));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road)); 
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_finish));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path)); 
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 11);
};

Level_12::Level_12(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int level) : Level(window, states, player, music, level)
{
    gameOverSound.setBuffer(gameOverBuffer);
    player->renderInGame();
    laneVector.push_back(new Lane(laneType::desert_first_lane));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::desert_road));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_rail));
    laneVector.push_back(new Lane(laneType::desert_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::rail)); 
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::grass));
    laneVector.push_back(new Lane(laneType::river));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::ice));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::rail));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_finish));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::road));
    laneVector.push_back(new Lane(laneType::snow_path)); 
    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather, 12);
};