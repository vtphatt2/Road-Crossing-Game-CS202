#include "header/game.hpp"

Game::Game() : widthWindow(1430), heightWindow(990) {
    window = new sf::RenderWindow(sf::VideoMode(widthWindow, heightWindow), "ROAD CROSSING");
    window->setFramerateLimit(60);
    states.push(new Entry(window, &states, this));
    playMusic();    
    // // debugg
    //states.push(new SettingMenu(window, &states, this));
}

Game::~Game() {
    delete window;
    while (!states.empty()) {
        delete states.top();
        states.pop();
    }
    std::cout << "Deallocated ok !\n";
}

void Game::run() {
    while (window->isOpen()) {
        handleEvent();
        update();
        render();
    }
}

void Game::handleEvent() {
    if (!states.empty()) {
        states.top()->handleEvent();
    }
    else 
        window->close();
}

void Game::update() {
    if (!states.empty()) {
        states.top()->update();
    }
    else 
        window->close();
}

void Game::render() {
    window->clear(sf::Color::White);

    if (!states.empty()) {
        states.top()->render();
    }

    window->display();
}

void Game::playMusic(){
    music.openFromFile("../resource/audio/audio1.mp3");
    musicVolume=50.0f;
    music.setVolume(musicVolume);
    music.setLoop(true);
    music.play();
}

void Game::stopMusic(){
    music.stop();
}

void Game::pauseMusic(){
    music.pause();
}

void Game::toggleMusic(){
    if (music.getStatus() == 2){
        music.pause();
    }
    else{
        music.play();
    }
}

int Game::getStatusMusic(){
    return music.getStatus();
}

void Game::setMusicVolume(float volume){
    music.setVolume(volume);
}

float Game::getMusicVolume() const {
    return musicVolume;
}

float Game::increaseVolume(){
    musicVolume = std::min(musicVolume + 10, 100.0f);
    return musicVolume;
}

float Game::decreaseVolume(){
    musicVolume = std::max(musicVolume - 10, 0.0f);
    return musicVolume;
}

