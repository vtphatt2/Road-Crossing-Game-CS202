#include "header/setting_menu.hpp"
#include <SFML/Audio.hpp>

SettingMenu::SettingMenu(sf::RenderWindow* window, std::stack <State*>* states, sf::Music* music)
    : window(window), states(states), music(music){
    initShape();
    updateButtonTextures();
}

void SettingMenu::initShape() {
    backgroundTexture.loadFromFile("../resource/Setting_Menu.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    soundTitleTexture.loadFromFile("../resource/soundOnOff.png");
    soundTitleImage.setTexture(soundTitleTexture);
    soundTitleImage.setPosition(484, 355);    
    
    soundButtonTexture.loadFromFile("../resource/music_on.png");
    soundButtonImage.setTexture(soundButtonTexture);
    soundButtonImage.setPosition(645, 445);
    soundButtonImage.setColor(sf::Color(255, 255, 255, 220));
    soundButtonRect.left = soundButtonImage.getPosition().x;  
    soundButtonRect.top = soundButtonImage.getPosition().y;  
    soundButtonRect.width = soundButtonImage.getGlobalBounds().width;
    soundButtonRect.height = soundButtonImage.getGlobalBounds().height;

    backButtonTexture.loadFromFile("../resource/Back_Button.png");
    backButtonImage.setTexture(backButtonTexture);
    backButtonImage.setPosition(27, 27);
    backButtonImage.setColor(sf::Color(255, 255, 255, 220));
    backButtonRect.left = 27;  
    backButtonRect.top = 27;   
    backButtonRect.width = 115;
    backButtonRect.height = 116;
}

void SettingMenu::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (soundButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) { 
                //0 stopped, 1 paused, 2 playing
                if (music->getStatus() == 2){
                    music->pause();
                }
                else {
                    music->play();
                }
                updateButtonTextures();            
            } 
            if (backButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->pop();
            }
        }
    }
}

void SettingMenu::updateButtonTextures() {
    if (music->getStatus() == 2) {
        soundButtonTexture.loadFromFile("../resource/music_on.png");
    } else {
        soundButtonTexture.loadFromFile("../resource/music_off.png");
    }
    soundButtonImage.setTexture(soundButtonTexture);
}

void SettingMenu::update() {
    mousePosition = sf::Mouse::getPosition(*window);
    if (soundButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        soundButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        soundButtonImage.setColor(sf::Color(255, 255, 255, 150));

    if (backButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        backButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        backButtonImage.setColor(sf::Color(255, 255, 255, 200));
}

void SettingMenu::render() {
    window->draw(backgroundImage);
    window->draw(soundTitleImage);
    window->draw(soundButtonImage);
    window->draw(backButtonImage);
}