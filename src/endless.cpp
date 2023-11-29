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
        Lane *lane;
        if(i == 0)
        {
            lane = new Lane(randomFirstLaneType());
            if(lane->type == laneType::desert_path) 
            {
                desert++;
                cont_path++;
            }
            else if(lane->type == laneType::grass)
            {
                garden++;
                cont_path++;
            }
            else if(lane->type == laneType::snow_path)
            {
                snow++;
                cont_path++;
            }
        }
        else
        {
            if (desert != 0)
            {
                if(cont_path != 0 && cont_path < 7)
                {
                    if(railed == false) 
                    {   
                        std::vector<laneType> laneTypeVector = {laneType::desert_path, laneType::desert_road, laneType::desert_rail};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else
                    {
                        std::vector<laneType> laneTypeVector = {laneType::desert_path, laneType::desert_road};
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
                        std::vector<laneType> laneTypeVector = {laneType::desert_road, laneType::desert_rail};
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
                        std::vector<laneType> laneTypeVector = {laneType::desert_path, laneType::desert_road, laneType::desert_rail};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else
                    {
                        std::vector<laneType> laneTypeVector = {laneType::desert_path, laneType::desert_road};
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
                else if(cont_road == 3)
                {
                    if(railed == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::desert_path, laneType::desert_rail};
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
                    std::vector<laneType> laneTypeVector = {laneType::desert_path, laneType::desert_road};
                    int randomNum = rand() % 2;
                    lane = new Lane(laneTypeVector[randomNum]);
                    if(lane->type == laneType::desert_path) cont_path++;
                    else if(lane->type == laneType::desert_road) cont_road++;
                }
                desert++;
            }
            else if(garden != 0)
            {
                if(cont_path != 0 && cont_path < 3)
                {
                    if(railed == false && rivered == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::grass, laneType::road, laneType::rail, laneType::river};
                        int randomNum = rand() % 4;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && rivered == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::grass, laneType::road, laneType::river};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == false && rivered == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::grass, laneType::rail, laneType::road};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && rivered == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::grass, laneType::road};
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
                        std::vector<laneType> laneTypeVector = {laneType::road, laneType::rail, laneType::river};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && rivered == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::road, laneType::river};
                        int randomNum = rand() % 2;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == false && rivered == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::rail, laneType::road};
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
                        std::vector<laneType> laneTypeVector = {laneType::grass, laneType::road, laneType::rail, laneType::river};
                        int randomNum = rand() % 4;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && rivered == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::grass, laneType::road, laneType::river};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == false && rivered == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::grass, laneType::rail, laneType::road};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && rivered == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::grass, laneType::road};
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
                        std::vector<laneType> laneTypeVector = {laneType::grass, laneType::rail, laneType::river};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && rivered == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::grass, laneType::river};
                        int randomNum = rand() % 2;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == false && rivered == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::rail, laneType::grass};
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
                    std::vector<laneType> laneTypeVector = {laneType::grass, laneType::road};
                    int randomNum = rand() % 2;
                    lane = new Lane(laneTypeVector[randomNum]);
                    if(lane->type == laneType::grass) cont_path++;
                    else if(lane->type == laneType::road) cont_road++;
                }
                else if(railed == true && rivered == false)
                {
                    std::vector<laneType> laneTypeVector = {laneType::grass, laneType::road};
                    int randomNum = rand() % 2;
                    lane = new Lane(laneTypeVector[randomNum]);
                    if(lane->type == laneType::grass) cont_path++;
                    else if(lane->type == laneType::road) cont_road++;
                }
                else if(railed == false && rivered == true)
                {
                    std::vector<laneType> laneTypeVector = {laneType::grass, laneType::road};
                    int randomNum = rand() % 2;
                    lane = new Lane(laneTypeVector[randomNum]);
                    if(lane->type == laneType::grass) cont_path++;
                    else if(lane->type == laneType::road) cont_road++;
                }
                garden++;
            }
            else if(snow != 0)
            {
                if(cont_path != 0 && cont_path < 7)
                {
                    if(railed == false && iced == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::road, laneType::rail, laneType::ice};
                        int randomNum = rand() % 4;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && iced == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::road, laneType::ice};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == false && iced == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::rail, laneType::road};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && iced == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::road};
                        int randomNum = rand() % 2;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    if(lane->type == laneType::snow_path) cont_path++;
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
                    else if(lane->type == laneType::ice) 
                    {
                        iced = true;
                        cont_path = 0;
                    }
                }
                else if(cont_path == 7)
                {
                    if(railed == false && iced == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::road, laneType::rail, laneType::ice};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && iced == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::road, laneType::ice};
                        int randomNum = rand() % 2;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == false && iced == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::rail, laneType::road};
                        int randomNum = rand() % 2;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && iced == true)
                    {
                        lane = new Lane(laneType::snow_path);
                    }
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
                    else if(lane->type == laneType::ice)
                    {
                        iced = true;
                        cont_path = 0;
                    }
                }
                else if(cont_road != 0 && cont_road < 2)
                {
                    if(railed == false && iced == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::road, laneType::rail, laneType::ice};
                        int randomNum = rand() % 4;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && iced == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::road, laneType::ice};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == false && iced == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::rail, laneType::road};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && iced == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::road};
                        int randomNum = rand() % 2;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    if(lane->type == laneType::road) cont_road++;
                    else if(lane->type == laneType::snow_path)
                    {
                        cont_path++;
                        cont_road = 0;
                    } 
                    else if(lane->type == laneType::rail)
                    {
                        railed = true;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::ice)
                    {
                        iced = true;
                        cont_road = 0;
                    }
                }
                else if(cont_road == 2)
                {
                    if(railed == false && iced == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::rail, laneType::ice};
                        int randomNum = rand() % 3;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && iced == false)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::ice};
                        int randomNum = rand() % 2;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == false && iced == true)
                    {
                        std::vector<laneType> laneTypeVector = {laneType::rail, laneType::snow_path};
                        int randomNum = rand() % 2;
                        lane = new Lane(laneTypeVector[randomNum]);
                    }
                    else if(railed == true && iced == true)
                    {
                        lane = new Lane(laneType::snow_path);
                    }
                    if(lane->type == laneType::snow_path) 
                    {
                        cont_path++;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::rail) 
                    {
                        railed = true;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::ice) 
                    {
                        iced = true;
                        cont_road = 0;
                    }
                }    
                else if(railed == true && iced == true)
                {
                    std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::road};
                    int randomNum = rand() % 2;
                    lane = new Lane(laneTypeVector[randomNum]);
                    if(lane->type == laneType::snow_path) cont_path++;
                    else if(lane->type == laneType::road) cont_road++;
                }
                else if(railed == true && iced == false)
                {
                    std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::road};
                    int randomNum = rand() % 2;
                    lane = new Lane(laneTypeVector[randomNum]);
                    if(lane->type == laneType::snow_path) cont_path++;
                    else if(lane->type == laneType::road) cont_road++;
                }
                else if(railed == false && iced == true)
                {
                    std::vector<laneType> laneTypeVector = {laneType::snow_path, laneType::road};
                    int randomNum = rand() % 2;
                    lane = new Lane(laneTypeVector[randomNum]);
                    if(lane->type == laneType::snow_path) cont_path++;
                    else if(lane->type == laneType::road) cont_road++;
                }
                snow++;
            }
        }
        laneVector.push_back(lane);
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
        if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)) {
            int translateY = landHeight / 15;
            view->move(sf::Vector2f(0, -translateY));
            windowTranslateY -= translateY;
            setting->moveUp(-translateY);
            if (-windowTranslateY % landHeight == 0) {
                isAddNewLane = 1;
            }
        }
        if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)) {
            int translateY = landHeight / 15;
            view->move(sf::Vector2f(0, translateY));
            windowTranslateY += translateY;
            setting->moveUp(translateY);
        }
        setting->handleEvent(event);
    }
}

void Endless::update() {
    setting->update();
    if (isAddNewLane) {
        int i = laneVector.size();
        Lane *lane;
        int biome;
        if(desert == 10)
        {
            desert = 0;
            biome = rand() % 2;
            if(biome == 0)
            {
                lane = new Lane(laneType::desert_path);
                desert++;
            }
            else
            {
                lane = new Lane(laneType::grass);
                garden++;
            }
        }
        else if(garden == 10)
        {
            garden = 0;
            biome = rand() % 3;
            if(biome == 0)
            {
                lane = new Lane(laneType::desert_path);
                desert++;
            }
            else if(biome == 1)
            {
                lane = new Lane(laneType::grass);
                garden++;
            }
            else
            {
                lane = new Lane(laneType::snow_path);
                snow++;
            }
        }
        else if(snow == 10)
        {
            snow = 0;
            biome = rand() % 2;
            if(biome == 0)
            {
                lane = new Lane(laneType::grass);
                garden++;
            }
            else
            {
                lane = new Lane(laneType::snow_path);
                snow++;
            }
        }
        else lane = new Lane(randomFirstLaneType());
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