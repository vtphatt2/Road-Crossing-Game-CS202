#include "header/endless.hpp"
#include<iostream>
Endless::Endless(sf::RenderWindow* window, std::stack <State*>* states, Player* player) : window(window), states(states), player(player) {
    setting = new Setting(window, states);
    initShape();
    player->renderInGame();
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
            if(garden != 0) 
            {
                if(cont_path != 0 && cont_path < 2) 
                {
                    if(railed = false) lane = new Lane(randomGardenLaneType());
                    else lane = new Lane(randomGarden_NoRail());
                    if(lane->type == laneType::river) 
                    {
                        cont_river++;
                        cont_path = 0;
                    }
                    else if(lane->type == laneType::road) 
                    {
                        cont_road++;
                        cont_path = 0;
                    }
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                        cont_path = 0;
                    }
                    else if(lane->type == laneType::grass) cont_path++;
                }
                else if(cont_path == 2) 
                {
                    if(railed = false) lane = new Lane(randomGarden_NoGrass());
                    else lane = new Lane(randomGarden_NoRailNoGrass());
                    cont_path = 0;
                    if(lane->type == laneType::river) cont_river++;
                    else if(lane->type == laneType::road) cont_road++;
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                    }
                }
                else if(cont_river != 0 && cont_river < 2) 
                {
                    if(railed = false) lane = new Lane(randomGardenLaneType());
                    else lane = new Lane(randomGarden_NoRail());
                    if(lane->type == laneType::grass) 
                    {
                        cont_path++;
                        cont_river = 0;
                    }
                    else if(lane->type == laneType::road) 
                    {
                        cont_road++;
                        cont_river = 0;
                    }
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                        cont_river = 0;
                    }
                    else if(lane->type == laneType::river) cont_river++;
                }
                else if(cont_river == 2) 
                {
                    if(railed = false) lane = new Lane(randomGarden_NoRiver());
                    else lane = new Lane(randomGarden_NoRailNoRiver());
                    cont_river = 0;
                    if(lane->type == laneType::grass) cont_path++;
                    else if(lane->type == laneType::road) cont_road++;
                    else if(lane->type == laneType::rail)
                    {
                        num_rail++; 
                        railed = true;
                    }
                }
                else if(cont_road != 0 && cont_road < 3) 
                {
                    if(railed = false) lane = new Lane(randomGardenLaneType());
                    else lane = new Lane(randomGarden_NoRail());
                    if(lane->type == laneType::grass) 
                    {
                        cont_path++;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::river) 
                    {
                        cont_river++;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::road) cont_road++;
                }
                else if(cont_road == 3)
                {
                    if(railed = false) lane = new Lane(randomGarden_NoRoad());
                    else lane = new Lane(randomGarden_NoRailNoRoad());
                    cont_road = 0;
                    if(lane->type == laneType::grass) cont_path++;
                    else if(lane->type == laneType::river) cont_river++;
                    else if(lane->type == laneType::rail) num_rail++;
                }
                else if(num_rail == 1)
                {
                    lane = new Lane(randomGarden_NoRail());
                    railed = true;
                    num_rail = 0;
                    if(lane->type == laneType::grass) cont_path++;
                    else if(lane->type == laneType::river) cont_river++;
                    else if(lane->type == laneType::road) cont_road++;
                }
                garden++;
            }
            else if(snow != 0) 
            {
                if(cont_path != 0 && cont_path < 2) 
                {
                    if(railed = false) lane = new Lane(randomSnowLaneType());
                    else lane = new Lane(randomSnow_NoRail());
                    if(lane->type == laneType::ice) 
                    {
                        cont_ice++;
                        cont_path = 0;
                    }
                    else if(lane->type == laneType::road) 
                    {
                        cont_road++;
                        cont_path = 0;
                    }
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                        cont_path = 0;
                    }
                    else if(lane->type == laneType::snow_path) cont_path++;
                }
                else if(cont_path == 2) 
                {
                    if(railed = false) lane = new Lane(randomSnow_NoSnowPath());
                    else lane = new Lane(randomSnow_NoRailNoSnowPath());
                    cont_path = 0;
                    if(lane->type == laneType::ice) cont_ice++;
                    else if(lane->type == laneType::road) cont_road++;
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                    }
                }
                else if(cont_ice != 0 && cont_ice < 2) 
                {
                    if(railed = false) lane = new Lane(randomSnowLaneType());
                    else lane = new Lane(randomSnow_NoRail());
                    if(lane->type == laneType::snow_path) 
                    {
                        cont_path++;
                        cont_ice = 0;
                    }
                    else if(lane->type == laneType::road) 
                    {
                        cont_road++;
                        cont_ice = 0;
                    }
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                        cont_ice = 0;
                    }
                    else if(lane->type == laneType::ice) cont_ice++;
                }
                else if(cont_ice == 2) 
                {
                    if(railed = false) lane = new Lane(randomSnow_NoIce());
                    else lane = new Lane(randomSnow_NoRailNoIce());
                    cont_ice = 0;
                    if(lane->type == laneType::snow_path) cont_path++;
                    else if(lane->type == laneType::road) cont_road++;
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                    }
                }
                else if(cont_road != 0 && cont_road < 3) 
                {
                    if(railed = false) lane = new Lane(randomSnowLaneType());
                    else lane = new Lane(randomSnow_NoRail());
                    if(lane->type == laneType::snow_path) 
                    {
                        cont_path++;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::ice) 
                    {
                        cont_ice++;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::road) cont_road++;
                }
                else if(cont_road == 3)
                {
                    if(railed = false) lane = new Lane(randomSnow_NoRoad());
                    else lane = new Lane(randomSnow_NoRailNoRoad());
                    cont_road = 0;
                    if(lane->type == laneType::snow_path) cont_path++;
                    else if(lane->type == laneType::ice) cont_ice++;
                    else if(lane->type == laneType::rail) num_rail++;
                }
                else if(num_rail == 1)
                {
                    lane = new Lane(randomSnow_NoRail());
                    railed = true;
                    num_rail = 0;
                    if(lane->type == laneType::snow_path) cont_path++;
                    else if(lane->type == laneType::ice) cont_ice++;
                    else if(lane->type == laneType::road) cont_road++;
                }
                snow++;
            }
            else if(desert != 0) 
            {
                if(cont_path != 0 && cont_path < 2) 
                {
                    if(railed = false) lane = new Lane(randomDesertLaneType());
                    else lane = new Lane(randomDesert_NoDesertRail());
                    if(lane->type == laneType::desert_path) 
                    {
                        cont_path++;
                        cont_river = 0;
                    }
                    else if(lane->type == laneType::desert_road) 
                    {
                        cont_road++;
                        cont_path = 0;
                    }
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                        cont_path = 0;
                    }
                    else if(lane->type == laneType::river) cont_river++;
                }
                else if(cont_path == 2) 
                {
                    if(railed = false) lane = new Lane(randomDesert_NoDesertPath());
                    else lane = new Lane(randomDesert_NoDesertRailNoDesertPath());
                    cont_path = 0;
                    if(lane->type == laneType::desert_road) cont_road++;
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++;
                        railed = true;
                    }
                }
                else if(cont_road != 0 && cont_road < 3)
                {
                    if(railed = false) lane = new Lane(randomDesertLaneType());
                    else lane = new Lane(randomDesert_NoDesertRail());
                    if(lane->type == laneType::desert_path) 
                    {
                        cont_path++;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::desert_road) 
                    {
                        cont_road++;
                        cont_river = 0;
                    }
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++; 
                        railed = true;
                        cont_road = 0;
                    }
                    else if(lane->type == laneType::river) cont_river++;
                }
                else if(cont_road == 3)
                {
                    if(railed = false) lane = new Lane(randomDesert_NoDesertRoad());
                    else lane = new Lane(randomDesert_NoDesertRailNoDesertRoad());
                    cont_road = 0;
                    if(lane->type == laneType::desert_path) cont_path++;
                    else if(lane->type == laneType::rail) 
                    {
                        num_rail++;
                        railed = true;
                    }
                }
                else if(num_rail == 1)
                {
                    lane = new Lane(randomDesert_NoDesertRail());
                    railed = true;
                    num_rail = 0;
                    if(lane->type == laneType::desert_path) cont_path++;
                    else if(lane->type == laneType::desert_road) cont_road++;
                }
                desert++;
            }
        }
        laneVector.push_back(lane);
        laneVector[i]->setPosition(0, 990 - landHeight * (i + 1));
        for (int j = 0; j < laneVector[i]->getStuffVector().size(); j++) {
            stuffVector.push_back(laneVector[i]->getStuffVector()[j]);
        }
    }
    
}

void Endless::handleEvent() {
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
            int translateY = landHeight / 15;
            view->move(sf::Vector2f(0, -translateY));
            windowTranslateY -= translateY;
            setting->move(-translateY);
            if (-windowTranslateY % landHeight == 0) {
                isAddNewLane = 1;
            }
            player->update(1);
            player->updateWindowBoundsCollision(window);
        }
        else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)) {
            if (windowTranslateY < 0) {
                int translateY = landHeight / 15;
                view->move(sf::Vector2f(0, translateY));
                windowTranslateY += translateY;
                setting->move(translateY);
            }
            player->update(2);
            player->updateWindowBoundsCollision(window);
        }
        else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)){
            player->update(3);
            player->updateWindowBoundsCollision(window);
        }
        else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)){
            player->update(4);
            player->updateWindowBoundsCollision(window);
        }
        setting->handleEvent(event);
    }
}

void Endless::update() {
    setting->update();
    for (int i = 0; i < laneVector.size(); i++) {
        laneVector[i]->update();
        
    }
    if (isAddNewLane) {
        int i = laneVector.size();
        laneVector.push_back(new Lane(randomFirstLaneType()));
        laneVector[laneVector.size() - 1]->setPosition(0, 990 - landHeight * (i + 1));
        for (int j = 0; j < laneVector[laneVector.size() - 1]->getStuffVector().size(); j++) {
            stuffVector.push_back(laneVector[laneVector.size() - 1]->getStuffVector()[j]);
        }
        isAddNewLane = 0;
    }
 
}

void Endless::render() {
    window->setView(*view);
    for (int i = 0; i < laneVector.size(); i++) {
        window->draw(*laneVector[i]);
    }
    window->draw(player->getPlayerSprite());
    window->draw(*setting);
}