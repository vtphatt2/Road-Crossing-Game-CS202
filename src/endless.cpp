#include "header/endless.hpp"

Endless::Endless(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music) : window(window), states(states), player(player), music(music) {
    initShape();
    weather = new Weather(window);
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather);
    gameOverBuffer.loadFromFile("../resource/audio/gameOver.wav");
    gameOverSound.setBuffer(gameOverBuffer);
    coinEatenBuffer.loadFromFile("../resource/audio/short-success.mp3");
    coinEaten.setBuffer(coinEatenBuffer);
    player->renderInGame();
    player->setMovementSpeed(10.0f);
}

void Endless::increaseScore(int offset) {
    this->score += offset;
}

Lane* Endless::snowLane()
{
    Lane* lane = nullptr;
    if (snow >= 10)
    {
        desert = 0;
        garden = 0;
        snow = 0;
        cont_path = 0;
        cont_road = 0;
        railed = false;
        rivered = false;
        iced = false;
        int randomNum = rand() % 2;
        lane = new Lane(laneType::road);
        if (randomNum == 0) 
        {
            cont_road++;
            garden++;
        }
        else 
        {
            cont_road++;
            snow++;
        }
    }
    else if (snow != 0 && snow < 10)
    {
        if (cont_path != 0 && cont_path < 7)
        {
            if (railed == false && iced == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::ice);
                int randomNum = rand() % 4;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == true && iced == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::ice);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == false && iced == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::road);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == true && iced == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::road);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            if (lane->type == laneType::snow_path) cont_path++;
            else if (lane->type == laneType::road) 
            {
                cont_road++;
                cont_path = 0;
            }
            else if (lane->type == laneType::rail) 
            {
                railed = true;
                cont_path = 0;
            }
            else if (lane->type == laneType::ice) 
            {
                iced = true;
                cont_path = 0;
            }
        }
        else if (cont_path == 7)
        {
            if(railed == false && iced == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::ice);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == true && iced == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::ice);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == false && iced == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::road);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == true && iced == true)
            {
                lane = new Lane(laneType::snow_path);
            }
            if (lane->type == laneType::road)
            {
                cont_road++;
                cont_path = 0;
            }
            else if (lane->type == laneType::rail)
            {
                railed = true;
                cont_path = 0;
            }
            else if (lane->type == laneType::ice)
            {
                iced = true;
                cont_path = 0;
            }
        }
        else if (cont_road != 0 && cont_road < 2)
        {
            if (railed == false && iced == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::ice);
                int randomNum = rand() % 4;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == true && iced == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::ice);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == false && iced == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::road);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == true && iced == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::road);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            if (lane->type == laneType::road) cont_road++;
            else if (lane->type == laneType::snow_path)
            {
                cont_path++;
                cont_road = 0;
            } 
            else if (lane->type == laneType::rail)
            {
                railed = true;
                cont_road = 0;
            }
            else if (lane->type == laneType::ice)
            {
                iced = true;
                cont_road = 0;
            }
        }
        else if (cont_road == 2)
        {
            if (railed == false && iced == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::ice);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == true && iced == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::ice);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == false && iced == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::snow_path);
                laneTypeVector.push_back(laneType::rail);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if (railed == true && iced == true)
            {
                lane = new Lane(laneType::snow_path);
            }
            if (lane->type == laneType::snow_path) 
            {
                cont_path++;
                cont_road = 0;
            }
            else if (lane->type == laneType::rail) 
            {
                railed = true;
                cont_road = 0;
            }
            else if (lane->type == laneType::ice) 
            {
                iced = true;
                cont_road = 0;
            }
        }    
        else if (railed == true && iced == true)
        {
            std::vector<laneType> laneTypeVector;
            laneTypeVector.push_back(laneType::snow_path);
            laneTypeVector.push_back(laneType::road);
            int randomNum = rand() % 2;
            lane = new Lane(laneTypeVector[randomNum]);
            if(lane->type == laneType::snow_path) cont_path++;
            else if(lane->type == laneType::road) cont_road++;
        }
        else if (railed == true && iced == false)
        {
            std::vector<laneType> laneTypeVector;
            laneTypeVector.push_back(laneType::snow_path);
            laneTypeVector.push_back(laneType::road);
            int randomNum = rand() % 2;
            lane = new Lane(laneTypeVector[randomNum]);
            if(lane->type == laneType::snow_path) cont_path++;
            else if(lane->type == laneType::road) cont_road++;
        }
        else if (railed == false && iced == true)
        {
            std::vector<laneType> laneTypeVector;
            laneTypeVector.push_back(laneType::snow_path);
            laneTypeVector.push_back(laneType::road);
            int randomNum = rand() % 2;
            lane = new Lane(laneTypeVector[randomNum]);
            if(lane->type == laneType::snow_path) cont_path++;
            else if(lane->type == laneType::road) cont_road++;
        }
        snow++;
    }

    return lane;
}

Lane* Endless::desertLane()
{
    Lane* lane = nullptr;
    if(desert >= 10)
    {
        desert = 0;
        garden = 0;
        snow = 0;
        cont_path = 0;
        cont_road = 0;
        railed = false;
        rivered = false;
        iced = false;
        int randomNum = rand() % 2;
        if(randomNum == 0) 
        {
            lane = new Lane(laneType::road);
            cont_road++;
            garden++;
        }
        else 
        {
            lane = new Lane(laneType::desert_road);
            cont_road++;
            desert++;
        }
    }
    else if(desert != 0 && desert < 10)
    {
        if(cont_path != 0 && cont_path < 7)
        {
            if(railed == false) 
            {   
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::desert_path);
                laneTypeVector.push_back(laneType::desert_road);
                laneTypeVector.push_back(laneType::desert_rail);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::desert_path);
                laneTypeVector.push_back(laneType::desert_road);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            if(lane->type == laneType::desert_path) cont_path++;
            else if(lane->type == laneType::desert_road)
            {
                cont_road++;
                cont_path = 0;
            }
            else if(lane->type == laneType::desert_rail) 
            {
                railed = true;
                cont_path = 0;
            }
        }
        else if(cont_path == 7)
        {
            if(railed == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::desert_road);
                laneTypeVector.push_back(laneType::desert_rail);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else
            {
                lane = new Lane(laneType::desert_road);
            }
            if(lane->type == laneType::desert_road)
            {
                cont_path = 0;
                cont_road++;
            }
            else if(lane->type == laneType::desert_rail)
            {
                cont_path = 0;
                railed = true;
            
            }
        }
        else if(cont_road != 0 && cont_road < 2)
        {
            if(railed == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::desert_path);
                laneTypeVector.push_back(laneType::desert_road);
                laneTypeVector.push_back(laneType::desert_rail);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::desert_path);
                laneTypeVector.push_back(laneType::desert_road);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            if(lane->type == laneType::desert_road) cont_road++;
            else if(lane->type == laneType::desert_path) 
            {
                cont_path++;
                cont_road = 0;
            }
            else if(lane->type == laneType::desert_rail)
            {
                railed = true;
                cont_road = 0;
            }
        }
        else if(cont_road == 2)
        {
            if(railed == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::desert_path);
                laneTypeVector.push_back(laneType::desert_rail);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else
            {
                lane = new Lane(laneType::desert_path);
            }
            if(lane->type == laneType::desert_path) 
            {
                cont_path++;
                cont_road = 0;
            }
            else if(lane->type == laneType::desert_rail) 
            {
                railed = true;
                cont_road = 0;
            }
        }
        else if(railed == true)
        {
            std::vector<laneType> laneTypeVector;
            laneTypeVector.push_back(laneType::desert_path);
            laneTypeVector.push_back(laneType::desert_road);
            int randomNum = rand() % 2;
            lane = new Lane(laneTypeVector[randomNum]);
            if(lane->type == laneType::desert_path) cont_path++;
            else if(lane->type == laneType::desert_road) cont_road++;
        }
        desert++;
    }
    return lane;
}

Lane* Endless::gardenLane()
{
    Lane* lane = nullptr;
    if(garden >= 10)
    {
        desert = 0;
        garden = 0;
        snow = 0;
        cont_path = 0;
        cont_road = 0;
        railed = false;
        rivered = false;
        iced = false;
        int randomNum = rand() % 3;
        lane = new Lane(laneType::road);
        if(randomNum == 0) 
        {
            cont_road++;
            desert++;
        }
        else if(randomNum == 1)
        {
            cont_road++;
            garden++;
        }
        else
        {
            rivered = true;
            cont_road++;
            snow++;
        }
    }
    else if(garden != 0 && garden < 10)
    {
        if(cont_path != 0 && cont_path < 3)
        {
            if(railed == false && rivered == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::river);
                int randomNum = rand() % 4;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == true && rivered == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::river);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == false && rivered == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::road);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == true && rivered == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::road);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            if(lane->type == laneType::grass) cont_path++;
            else if(lane->type == laneType::road) 
            {
                cont_road++;
                cont_path = 0;
            }
            else if(lane->type == laneType::rail) 
            {
                railed = true;
                cont_path = 0;
            }
            else if(lane->type == laneType::river) 
            {
                rivered = true;
                cont_path = 0;
            }
        }
        else if(cont_path == 3)
        {
            if(railed == false && rivered == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::river);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == true && rivered == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::river);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == false && rivered == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::road);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == true && rivered == true)
            {
                lane = new Lane(laneType::grass);
            }
            cont_path = 0;
            if(lane->type == laneType::road)
            {
                cont_road++;
                cont_path = 0;
            }
            else if(lane->type == laneType::rail)
            {
                railed = true;
                cont_path = 0;
            }
            else if(lane->type == laneType::river)
            {
                rivered = true;
                cont_path = 0;
            }
        }
        else if(cont_road != 0 && cont_road < 3)
        {
            if(railed == false && rivered == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::river);
                int randomNum = rand() % 4;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == true && rivered == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::road);
                laneTypeVector.push_back(laneType::river);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == false && rivered == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::road);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == true && rivered == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::road);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            if(lane->type == laneType::road) cont_road++;
            else if(lane->type == laneType::grass)
            {
                cont_path++;
                cont_road = 0;
            } 
            else if(lane->type == laneType::rail)
            {
                railed = true;
                cont_road = 0;
            }
            else if(lane->type == laneType::river)
            {
                rivered = true;
                cont_road = 0;
            }
        }
        else if(cont_road == 3)
        {
            if(railed == false && rivered == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::rail);
                laneTypeVector.push_back(laneType::river);
                int randomNum = rand() % 3;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == true && rivered == false)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::river);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == false && rivered == true)
            {
                std::vector<laneType> laneTypeVector;
                laneTypeVector.push_back(laneType::grass);
                laneTypeVector.push_back(laneType::rail);
                int randomNum = rand() % 2;
                lane = new Lane(laneTypeVector[randomNum]);
            }
            else if(railed == true && rivered == true)
            {
                lane = new Lane(laneType::grass);
            }
            cont_road = 0;
            if(lane->type == laneType::grass) cont_path++;
            else if(lane->type == laneType::rail) railed = true;
            else if(lane->type == laneType::river) rivered = true;
        }
        else if(railed == true && rivered == true)
        {
            std::vector<laneType> laneTypeVector;
            laneTypeVector.push_back(laneType::grass);
            laneTypeVector.push_back(laneType::road);
            int randomNum = rand() % 2;
            lane = new Lane(laneTypeVector[randomNum]);
            if(lane->type == laneType::grass) cont_path++;
            else if(lane->type == laneType::road) cont_road++;
        }
        else if(railed == true && rivered == false)
        {
            std::vector<laneType> laneTypeVector;
            laneTypeVector.push_back(laneType::grass);
            laneTypeVector.push_back(laneType::road);
            int randomNum = rand() % 2;
            lane = new Lane(laneTypeVector[randomNum]);
            if(lane->type == laneType::grass) cont_path++;
            else if(lane->type == laneType::road) cont_road++;
        }
        else if(railed == false && rivered == true)
        {
            std::vector<laneType> laneTypeVector;
            laneTypeVector.push_back(laneType::grass);
            laneTypeVector.push_back(laneType::road);
            int randomNum = rand() % 2;
            lane = new Lane(laneTypeVector[randomNum]);
            if(lane->type == laneType::grass) cont_path++;
            else if(lane->type == laneType::road) cont_road++;
        }
        garden++;
    }
    return lane;
}

void Endless::initShape()
{
    view = new sf::View;
    view->setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    view->setCenter(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
    windowTranslateY = 0;
    score = 0;

    scoreBoardTexture.loadFromFile("../resource/Score.png");
    scoreBoardImage.setTexture(scoreBoardTexture);
    scoreBoardImage.setPosition(1045, 12);
    scoreBoardImage.setScale(2, 2);

    font.loadFromFile("../resource/Inter-Bold.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color(0xD6, 0xB0, 0x8D));
    scoreText.setOutlineThickness(4);
    scoreText.setOutlineColor(sf::Color(0x37, 0x00, 0x00));
    scoreText.setPosition(1075, 25);

    Time = sf::Time::Zero;
    increaseSpeedTime = sf::Time::Zero;
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        Lane* lane = nullptr;
        if (i == 0)
        {
            lane = new Lane(randomFirstLaneType());
            if (lane->type == laneType::desert_first_lane)
            {
                desert++;
                cont_path++;
            }
            else if (lane->type == laneType::garden_first_lane)
            {
                garden++;
                cont_path++;
            }
            else if (lane->type == laneType::snow_first_lane)
            {
                snow++;
                cont_path++;
            }
        }
        else
        {
            if (desert != 0)
                lane = desertLane();
            else if (garden != 0)
                lane = gardenLane();
            else if (snow != 0)
                lane = snowLane();
        }
        laneVector.push_back(lane);
        laneVector[i]->setPosition(0, 990 - landHeight * (i + 1));
        for (int j = 0; j < laneVector[i]->getStuffVector().size(); j++)
        {
            stuffVector.push_back(laneVector[i]->getStuffVector()[j]);
        }
    }
}

void Endless::handleEvent() {
    const float movementSpeed = 20.0f; 
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
        if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)) {
            player->update(static_cast<Direction>(2));
            player->updateWindowBoundsCollision(window, windowTranslateY);
        }
        if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)){
            player->update(static_cast<Direction>(3));
            player->updateWindowBoundsCollision(window, windowTranslateY);
        }
        if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)){
            player->update(static_cast<Direction>(4));
            player->updateWindowBoundsCollision(window, windowTranslateY);
        }
        else {
            player->update(static_cast<Direction>(0));
        }
        setting->handleEvent(event);
    }
}

void Endless::update() 
{
    if (!countedDown) {
        countedDown = true;
        window->setView(*view);
        states->push(new CountDown(window, states, laneVector, stuffVector, player, view));
        return ;
    }

    if (isGameOver) {        
        weather->stopSound();
        coinEaten.stop();
        gameOverSound.play();        
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
        clearDataLoadGame();
        updateHighScore("../data/score.txt");
        save = false;
        states->push(new Lose(window, states, music, backgroundTexture, player, 0, score));
        isGameOver = 0;
    }
    setting->update();
    for (int i = 0; i < laneVector.size(); i++) laneVector[i]->update();
    if (isAddNewLane) 
    {
        int i = laneVector.size();
        Lane* lane = nullptr;
        
        if(desert != 0) lane = desertLane();
        else if(garden != 0) lane = gardenLane();
        else if(snow != 0) lane = snowLane();

        if (lane != nullptr) laneVector.push_back(lane);
        laneVector[laneVector.size() - 1]->setPosition(0, 990 - landHeight * (i + 1));

        for (int j = 0; j < laneVector[laneVector.size() - 1]->getStuffVector().size(); j++) 
        {
            laneVector[laneVector.size() - 1]->getStuffVector()[j]->setSpeed(speedCoe * laneVector[laneVector.size() - 1]->getStuffVector()[j]->getSpeed());
            stuffVector.push_back(laneVector[laneVector.size() - 1]->getStuffVector()[j]);
        }
        isAddNewLane = 0;
    }

    ++count;
    if (count == 100)
    {
        count = 0;
        ++score;
    }

    bool gameRunning = true;
    Time = Clock.getElapsedTime();
    if (Time.asSeconds() >= 0.01) {
        view->move(0, -1);
        setting->move(-1);
        scoreText.move(0, -1);
        scoreBoardImage.move(0, -1);
        windowTranslateY += -1;
        if (-windowTranslateY % landHeight == 0) {
            isAddNewLane = 1;
        }
        player->updateWindowBoundsCollision(window, windowTranslateY);
        playerCollision(stuffVector); 
        eatCredit();
        scoreText.setString("Score : " + std::to_string(score));
        Clock.restart();
    }
    increaseSpeedTime = increaseSpeedClock.getElapsedTime();
    if (increaseSpeedTime.asSeconds() >= 15) {
        speedCoe *= 1.3;
        increaseSpeedClock.restart();
    }    
    notBridge();
    rainy();
}

void Endless::rainy() {
    if (Rain.getElapsedTime().asSeconds() == 0.0f) initialMusicStatus = music.getStatus() == sf::SoundSource::Status::Playing;
    if (Rain.getElapsedTime().asSeconds() >= 20.0f) {
        isRaining = rand() % 2;
        if (isRaining) {
            if (initialMusicStatus) music.pause();
            weather->playSound();
            player->setMovementSpeed(5.0f);
            Rain.restart();
        }
    } else if (isRaining && Rain.getElapsedTime().asSeconds() >= 8.0f) {
        isRaining = false;
        weather->stopSound();
        if (initialMusicStatus) music.play();
        player->setMovementSpeed(10.0f);
    }

    if (isRaining) {
        weather->startRain();
        weather->updateRain(windowTranslateY);
    }
}

void Endless::notBridge(){
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
                else {
                    player->updatePlayerDrown();
                    sf::Vector2f pos = player->getPlayerSprite().getPosition();
                    player->getPlayerSprite().setPosition(pos);
                    gameOver();
                }
            }
        }
    }
}

void Endless::playerCollision(std::vector<Stuff*> stuffVector) {
    for (auto& stuff : stuffVector) {
        float negativeMargin = -15.0f;
        bool isCollision = player->isCollisionWithMargin(stuff->getGlobalBounds(), negativeMargin);
        if (isCollision) {
            die = 1;
            gameOver();
        }
    } 
}

void Endless::eatCredit() {
    float negativeMargin = -15.0f;
    for (int i = 0 ; i < laneVector.size() ; ++i) 
    {
        if (laneVector[i]->getCoin()) 
        {
            Coin* coins = laneVector[i]->getCoin();
            for (int j = 0 ; j < 3 ; ++j) 
            {
                if (coins[j].isExist() && player->isCollisionWithMargin(coins[j].getGlobalBounds(), negativeMargin)) 
                {
                    coins[j].vanish();
                    coinEaten.play();
                    increaseScore(5);
                }
            }
        }
    }
}

void Endless::gameOver(){
    isGameOver = 1;
    if (die) player->updatePlayerDie();
}

void Endless::render() {
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
    window->draw(scoreBoardImage);
    window->draw(scoreText);
}