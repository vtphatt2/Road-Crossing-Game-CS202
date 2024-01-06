#include "header/setting_menu.hpp"

SettingMenu::SettingMenu(sf::RenderWindow* window, std::stack <State*>* states, sf::Music &music)
    : window(window), states(states), music(music){
    initShape();
    updateButtonTextures();

    font.loadFromFile("../resource/Inter-Bold.ttf");
    volumeText.setFont(font);
    updateVolumeText();
}

void SettingMenu::initShape() {
    backgroundTexture.loadFromFile("../resource/Setting_Menu.png");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setPosition(0, 0);

    soundTitleTexture.loadFromFile("../resource/audio/Music.png");
    soundTitleImage.setTexture(soundTitleTexture);
    soundTitleImage.setPosition(454, 361);    

    volumeTitleTexture.loadFromFile("../resource/audio/VOLUME.png");
    volumeTitleImage.setTexture(volumeTitleTexture);
    volumeTitleImage.setPosition(435, 552);  
    
    soundButtonTexture.loadFromFile("../resource/music_on.png");
    soundButtonImage.setTexture(soundButtonTexture);
    soundButtonImage.setPosition(793, 342);
    soundButtonImage.setColor(sf::Color(255, 255, 255, 220));
    soundButtonRect.left = soundButtonImage.getPosition().x;  
    soundButtonRect.top = soundButtonImage.getPosition().y;  
    soundButtonRect.width = soundButtonImage.getGlobalBounds().width;
    soundButtonRect.height = soundButtonImage.getGlobalBounds().height;

    upButtonTexture.loadFromFile("../resource/audio/Up.png");
    upButtonImage.setTexture(upButtonTexture);
    upButtonImage.setPosition(900,700);
    upButtonImage.setColor(sf::Color(255, 255, 255, 220));
    upButtonRect.left = upButtonImage.getPosition().x;
    upButtonRect.top = upButtonImage.getPosition().y;
    upButtonRect.width = upButtonImage.getGlobalBounds().width;
    upButtonRect.height = upButtonImage.getGlobalBounds().height;

    downButtonTexture.loadFromFile("../resource/audio/Down.png");
    downButtonImage.setTexture(downButtonTexture);
    downButtonImage.setPosition(470, 700);  
    downButtonImage.setColor(sf::Color(255, 255, 255, 220));
    downButtonRect.left = downButtonImage.getPosition().x;
    downButtonRect.top = downButtonImage.getPosition().y;
    downButtonRect.width = downButtonImage.getGlobalBounds().width;
    downButtonRect.height = downButtonImage.getGlobalBounds().height;

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
            if (backButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) {
                states->pop();
            }
        }

        if ((event.type == sf::Event::MouseButtonPressed && soundButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)) {
            //0 stopped, 1 paused, 2 playing
            toggleMusic();
            updateButtonTextures();     
        }

        if ((event.type == sf::Event::MouseButtonPressed && upButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)) {
            setMusicVolume(increaseVolume()); 
            updateVolumeText();
        } else if ((event.type == sf::Event::MouseButtonPressed && downButtonRect.contains(event.mouseButton.x, event.mouseButton.y)) ||
                   (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)) {
            setMusicVolume(decreaseVolume()); 
            updateVolumeText();
        }
    }
}

void SettingMenu::updateButtonTextures() {
    if (getStatusMusic() == 2) {
        soundButtonTexture.loadFromFile("../resource/music_on.png");
    } else {
        soundButtonTexture.loadFromFile("../resource/music_off.png");
    }
    soundButtonImage.setTexture(soundButtonTexture);
}

void SettingMenu::updateVolumeText(){
    volumeText.setCharacterSize(100);
    sf::Color textColor(214, 176, 141);
    sf::Color outlineColor(174, 118, 64);
    float outlineThickness = 3.0f;
    volumeText.setFillColor(textColor);
    volumeText.setOutlineColor(outlineColor);
    volumeText.setOutlineThickness(outlineThickness);    

    int volume = static_cast<int>(getMusicVolume());
    volumeText.setString(std::to_string(volume));

    float centerX = (upButtonRect.left + downButtonRect.left + downButtonRect.width) / 2.0f;
    float centerY = (upButtonRect.top + downButtonRect.top) / 2.0f + 10;
    volumeText.setPosition(centerX - volumeText.getGlobalBounds().width / 2.0f,
                        centerY - volumeText.getGlobalBounds().height / 2.0f);
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

    if (upButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        upButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        upButtonImage.setColor(sf::Color(255, 255, 255, 200));

    if (downButtonImage.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
        downButtonImage.setColor(sf::Color(255, 255, 255, 255));
    else 
        downButtonImage.setColor(sf::Color(255, 255, 255, 200));
}

void SettingMenu::render() {
    window->draw(backgroundImage);
    window->draw(soundTitleImage);
    window->draw(soundButtonImage);
    window->draw(backButtonImage);
    window->draw(volumeTitleImage);
    window->draw(volumeText);
    window->draw(upButtonImage);
    window->draw(downButtonImage);
}

void SettingMenu::stopMusic(){
    music.stop();
}

void SettingMenu::pauseMusic(){
    music.pause();
}

void SettingMenu::toggleMusic(){
    if (music.getStatus() == 2){
        music.pause();
    }
    else{
        music.play();
    }
}

int SettingMenu::getStatusMusic(){
    return music.getStatus();
}

void SettingMenu::setMusicVolume(float volume){
    music.setVolume(volume);
}

float SettingMenu::getMusicVolume() const {
    return musicVolume;
}

float SettingMenu::increaseVolume(){
    musicVolume = std::min(musicVolume + 10, 100.0f);
    return musicVolume;
}

float SettingMenu::decreaseVolume(){
    musicVolume = std::max(musicVolume - 10, 0.0f);
    return musicVolume;
}
