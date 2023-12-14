#include "header/weather.hpp"

Weather::Weather(sf::RenderWindow* window): window(window) {
    initShape();
}

void Weather::initShape(){
    for (int i = 0; i < 3; ++i) {
        if (!raindropTextures[i].loadFromFile("../resource/rain/drop" + std::to_string(i + 1) + ".png")) {
            std::cout << "Error loading raindrop" << i + 1 << ".png\n";
        }
    }
}

void Weather::startRain() { 
    for (int i = 0; i < rand() % 20; ++i) {
        int textureIndex = rand() % 3;
        sf::Sprite raindrop;
        raindrop.setTexture(raindropTextures[textureIndex]);

        sf::Vector2f translation = window->getView().getCenter() - window->getView().getSize() / 2.f;
        int randomX = rand() % static_cast<int>(window->getSize().x) + static_cast<int>(translation.x);
        int randomY = rand() % static_cast<int>(window->getSize().y) + static_cast<int>(translation.y);
        raindrop.setPosition(randomX,static_cast<int>(translation.y));
        raindrop.setScale(0.1f, 0.1f); // Adjust scale if needed
        raindrops.push_back(raindrop);
        if (raindrops.size() > 1000) raindrops.resize(1000);
    }
}

void Weather::updateRain(int windowTranslateY) { 
    for (int i=0; i<raindrops.size(); i++) {
        int randomMove = rand() % 10;
        raindrops[i].move(0, randomMove);
        if (raindrops[i].getPosition().y >= windowTranslateY + 920) raindrops.erase(raindrops.begin()+i);
    }
}

std::vector<sf::Sprite> Weather::getRaindrops(){
    return raindrops;
}

void Weather::drawRaindrops() {
    for (const auto& raindrop : raindrops) {
        window->draw(raindrop);
    }
}
