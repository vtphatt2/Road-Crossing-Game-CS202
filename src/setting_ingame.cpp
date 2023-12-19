#include "header/setting_ingame.hpp"

Setting::Setting(sf::RenderWindow* window, std::stack <State*>* states, sf::Music& music, Player* player, std::vector<Stuff*>& stuffVector, std::vector<Lane*>& laneVector, sf::View *view)
    : window(window), states(states), music(music), player(player), stuffVector(stuffVector), laneVector(laneVector), view(view)
{
    initShape();
}

void Setting::initShape() {
    FAQButtonTexture.loadFromFile("../resource/FAQ.png");
    FAQButtonImage.setTexture(FAQButtonTexture);
    FAQButtonImage.setPosition(1029, 895);
    FAQButtonRect.left = FAQButtonImage.getPosition().x;
    FAQButtonRect.top = FAQButtonImage.getPosition().y;
    FAQButtonRect.width = FAQButtonImage.getGlobalBounds().width;
    FAQButtonRect.height = FAQButtonImage.getGlobalBounds().height;

    leaderboardButtonTexture.loadFromFile("../resource/Leaderboard.png");
    leaderboardButtonImage.setTexture(leaderboardButtonTexture);
    leaderboardButtonImage.setPosition(1130, 895);
    leaderboardButtonRect.left = leaderboardButtonImage.getPosition().x;
    leaderboardButtonRect.top = leaderboardButtonImage.getPosition().y;
    leaderboardButtonRect.width = leaderboardButtonImage.getGlobalBounds().width;
    leaderboardButtonRect.height = leaderboardButtonImage.getGlobalBounds().height;

    settingButtonTexture.loadFromFile("../resource/Setting.png");
    settingButtonImage.setTexture(settingButtonTexture);
    settingButtonImage.setPosition(1231, 895);
    settingButtonRect.left = settingButtonImage.getPosition().x;
    settingButtonRect.top = settingButtonImage.getPosition().y;
    settingButtonRect.width = settingButtonImage.getGlobalBounds().width;
    settingButtonRect.height = settingButtonImage.getGlobalBounds().height;

    pauseButtonTexture.loadFromFile("../resource/Pause.png");
    pauseButtonImage.setTexture(pauseButtonTexture);
    pauseButtonImage.setPosition(1332, 895);
    pauseButtonRect.left = pauseButtonImage.getPosition().x;
    pauseButtonRect.top = pauseButtonImage.getPosition().y;
    pauseButtonRect.width = pauseButtonImage.getGlobalBounds().width;
    pauseButtonRect.height = pauseButtonImage.getGlobalBounds().height;
}

void Setting::handleEvent(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
    {
        if(FAQButtonRect.contains(mousePosition)) 
        {
            window->setView(*view);
            states->push(new Instruction(window, states));
        }
        if(leaderboardButtonRect.contains(mousePosition)) 
        {
            window->setView(*view);
            states->push(new LeaderboardIngame(window, states));
        }
        if(settingButtonRect.contains(mousePosition)) 
        {
            window->setView(*view);
            states->push(new SettingIngame(window, states));
        }
        if(pauseButtonRect.contains(mousePosition)) 
        {
            window->setView(*view);
            states->push(new Pause(window, states, music, player, stuffVector, laneVector, view));
        }
    }
}

void Setting::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if(FAQButtonRect.contains(mousePosition)) {
        FAQButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        FAQButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(leaderboardButtonRect.contains(mousePosition)) {
        leaderboardButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        leaderboardButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(settingButtonRect.contains(mousePosition)) {
        settingButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        settingButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
    if(pauseButtonRect.contains(mousePosition)) {
        pauseButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        pauseButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
}
void Setting::move(int translateY) {
    FAQButtonImage.move(0, translateY);
    leaderboardButtonImage.move(0, translateY);
    settingButtonImage.move(0, translateY);
    pauseButtonImage.move(0, translateY);
}

void Setting::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(FAQButtonImage);
    target.draw(leaderboardButtonImage);
    target.draw(settingButtonImage);
    target.draw(pauseButtonImage);

}

std::string Setting::positionComponents() {
    std::string s = std::to_string((int)FAQButtonImage.getPosition().x) + " " + std::to_string((int)FAQButtonImage.getPosition().y) + " ";
    s += std::to_string((int)leaderboardButtonImage.getPosition().x) + " " + std::to_string((int)leaderboardButtonImage.getPosition().y) + " ";
    s += std::to_string((int)settingButtonImage.getPosition().x) + " " + std::to_string((int)settingButtonImage.getPosition().y) + " ";
    s += std::to_string((int)pauseButtonImage.getPosition().x) + " " + std::to_string((int)pauseButtonImage.getPosition().y);
    return s;
}

void Setting::setPositionComponents(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    FAQButtonImage.setPosition(x1, y1);
    leaderboardButtonImage.setPosition(x2, y2);
    settingButtonImage.setPosition(x3, y3);
    pauseButtonImage.setPosition(x4, y4);
}

LeaderboardIngame::LeaderboardIngame(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();
}

void LeaderboardIngame::initShape() {

    backButtonTexture.loadFromFile("../resource/Back_Button.png");
    backButtonImage.setTexture(backButtonTexture);
    backButtonImage.setPosition(20, 20);
    backButtonRect.left = backButtonImage.getPosition().x;
    backButtonRect.top = backButtonImage.getPosition().y;
    backButtonRect.width = backButtonImage.getGlobalBounds().width;
    backButtonRect.height = backButtonImage.getGlobalBounds().height;
}

void LeaderboardIngame::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) 
        {
            window->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) 
        {
            window->close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
        {
            if(backButtonRect.contains(mousePosition)) 
            {
                states->pop();
            }
        }
    }
}

void LeaderboardIngame::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if(backButtonRect.contains(mousePosition)) {
        backButtonImage.setColor(sf::Color(255, 255, 255, 255));
    } else {
        backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    }
}

void LeaderboardIngame::render() {
    window->draw(backButtonImage);
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

FAQ::FAQ(sf::RenderWindow* window, std::stack <State*>* states) : window(window), states(states) {
    initShape();
}

void FAQ::initShape() {
    backgroundTexture.loadFromFile("../resource/Background.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);
}

void FAQ::handleEvent() {
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

void FAQ::update() {
    mousePosition = sf::Mouse::getPosition(*window);
}

void FAQ::render() {
    window->draw(backgroundImage);
}
