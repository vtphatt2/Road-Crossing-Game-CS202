#include "header/setting_ingame.hpp"

Setting::Setting(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player, std::vector<Stuff*>& stuffVector, std::vector<Lane*>& laneVector, sf::View *view)
    : window(window), states(states), music(music), player(player), stuffVector(stuffVector), laneVector(laneVector), view(view)
{
    level = 0;
    initShape();
}

Setting::Setting(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player, std::vector<Stuff*>& stuffVector, std::vector<Lane*>& laneVector, sf::View *view, int currentLevel)
    : window(window), states(states), music(music), player(player), stuffVector(stuffVector), laneVector(laneVector), view(view), level(currentLevel)
{
    initShape();
}

void Setting::initShape() {
    pauseButtonTexture.loadFromFile("../resource/Pause.png");
    pauseButtonImage.setTexture(pauseButtonTexture);
    pauseButtonImage.setPosition(25, 25);
    pauseButtonRect.left = pauseButtonImage.getPosition().x;
    pauseButtonRect.top = pauseButtonImage.getPosition().y;
    pauseButtonRect.width = pauseButtonImage.getGlobalBounds().width;
    pauseButtonRect.height = pauseButtonImage.getGlobalBounds().height;
}

void Setting::handleEvent(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
    {
        if (pauseButtonRect.contains(mousePosition)) 
        {
            window->setView(*view);
            states->push(new Pause(window, states, music, player, stuffVector, laneVector, view, level));
        }
    }
}

void Setting::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if (pauseButtonRect.contains(mousePosition)) {
        pauseButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } 
    else {
        pauseButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
}
void Setting::move(int translateY) {
    pauseButtonImage.move(0, translateY);
}

void Setting::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(pauseButtonImage);

}

std::string Setting::positionComponents() {
    return std::to_string((int)pauseButtonImage.getPosition().x) + " " + std::to_string((int)pauseButtonImage.getPosition().y);
}

void Setting::setPositionComponents(int x, int y) {
    pauseButtonImage.setPosition(x, y);
}

SettingIngame::SettingIngame(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();
}

void SettingIngame::initShape() {
    backgroundTexture.loadFromFile("../resource/Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);
}

void SettingIngame::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) 
        {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) 
        {
            window->close();
        }
    }
}

void SettingIngame::update() {
    mousePosition = sf::Mouse::getPosition(*window);
}

void SettingIngame::render() {
    window->draw(backgroundImage);
}

