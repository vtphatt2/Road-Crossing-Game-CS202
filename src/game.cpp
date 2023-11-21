#include "header/game.hpp"

Game::Game() : widthWindow(1430), heightWindow(990) {
    window = new sf::RenderWindow(sf::VideoMode(widthWindow, heightWindow), "ROAD CROSSING");
    window->setFramerateLimit(60);
    music = new sf::Music();
    states.push(new Entry(window, &states, music));
    playMusic();    
    // // debugg
    // states.push(new highScore(window, &states));
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
    music->openFromFile("../resource/audio/audio1.mp3");
    music->setVolume(50);
    music->setLoop(true);
    music->play();
}

void Game::stopMusic(){
    music->stop();
}

void Game::pauseMusic(){
    music->pause();
}

