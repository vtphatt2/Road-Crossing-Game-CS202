#include "header/endless.hpp"

Endless::Endless(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    setting = new Setting(window, states);
    
    laneTextures.resize(7);
    laneImages.resize(7);
    laneVector.resize(20);

    laneTextures[0].loadFromFile("../resource/lane/desert_path_lane.png");
    laneTextures[1].loadFromFile("../resource/lane/desert_road_lane.png");
    laneTextures[2].loadFromFile("../resource/lane/road_lane.png");
    laneTextures[3].loadFromFile("../resource/lane/grass_lane.png");
    laneTextures[4].loadFromFile("../resource/lane/river_lane.png");
    laneTextures[5].loadFromFile("../resource/lane/snow_path_lane.png");
    laneTextures[6].loadFromFile("../resource/lane/rail_lane.png");

    for (int i = 0; i < 7; ++i) laneImages[i].setTexture(laneTextures[i]);

    std::vector<int> randomVector = {0, 3, 5};
    std::vector<int> randomLaneInBiome;
    std::random_shuffle(randomVector.begin(), randomVector.end());
    int desert = 0, garden = 0, snow = 0;
    int last_rail_lane = 0;
    if(randomVector[0] == 0) 
    {
        laneVector.push_back(laneImages[0]);
        laneVector.push_back(laneImages[0]);
        laneVector.push_back(laneImages[1]);
        desert = 3;
    }
    else if(randomVector[0] == 3)
    {
        laneVector.push_back(laneImages[3]);
        laneVector.push_back(laneImages[3]);
        laneVector.push_back(laneImages[2]);
        garden = 3;
    }
    else if(randomVector[0] == 5)
    {
        laneVector.push_back(laneImages[5]);
        laneVector.push_back(laneImages[5]);
        laneVector.push_back(laneImages[2]);
        snow = 3;
    }
    if(desert != 0)
    {
        while(desert < 15)
        {
            srand(time(NULL));
            randomLaneInBiome = {0, 1, 2, 6};
            std::random_shuffle(randomLaneInBiome.begin(), randomLaneInBiome.end());
            if(randomLaneInBiome[0] == 0)
            {
                laneVector.push_back(laneImages[0]);
                desert++;
            }
            else if(randomLaneInBiome[0] == 1)
            {
                laneVector.push_back(laneImages[1]);
                desert++;
            }
            else if(randomLaneInBiome[0] == 2)
            {
                laneVector.push_back(laneImages[2]);
                desert++;
            }
            else if(randomLaneInBiome[0] == 6 && (last_rail_lane + 1 == desert))
            {
                laneVector.push_back(laneImages[6]);
                last_rail_lane = desert;
                desert++;
            }
        }
    }
    else if(garden != 0)
    {
        while(garden < 15)
        {
            srand(time(NULL));
            randomLaneInBiome = {2, 3, 4, 6};
            std::random_shuffle(randomLaneInBiome.begin(), randomLaneInBiome.end());
            if(randomLaneInBiome[0] == 2)
            {
                laneVector.push_back(laneImages[2]);
                garden++;
            }
            else if(randomLaneInBiome[0] == 3)
            {
                laneVector.push_back(laneImages[3]);
                garden++;
            }
            else if(randomLaneInBiome[0] == 4)
            {
                laneVector.push_back(laneImages[4]);
                garden++;
            }
            else if(randomLaneInBiome[0] == 6 && (last_rail_lane + 1 != garden))
            {
                laneVector.push_back(laneImages[6]);
                last_rail_lane = garden;
                garden++;
            }
        }
    }
    else if(snow != 0)
    {
        while(snow < 15)
        {
            srand(time(NULL));
            randomLaneInBiome = {2, 5, 6};
            std::random_shuffle(randomLaneInBiome.begin(), randomLaneInBiome.end());
            if(randomLaneInBiome[0] == 2)
            {
                laneVector.push_back(laneImages[2]);
                snow++;
            }
            else if(randomLaneInBiome[0] == 5)
            {
                laneVector.push_back(laneImages[5]);
                snow++;
            }
            else if(randomLaneInBiome[0] == 6 && (last_rail_lane + 1 != snow))
            {
                laneVector.push_back(laneImages[6]);
                last_rail_lane = snow;
                snow++;
            }
        }
    }

    initShape();
}

void Endless::initShape() {
    
    for (int i = 0; i < laneVector.size(); i++) {
        laneVector[i].setPosition(0, 825 - 165 * i);
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
        setting->handleEvent(event);
    }
}

void Endless::update() {
    setting->update();
}

void Endless::render() {
    for(int i = 0; i < laneVector.size(); i++)
    {
        window->draw(laneVector[i]);
    }
    window->draw(*setting);
}