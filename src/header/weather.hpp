#ifndef WEATHER_HPP
#define WEATHER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Weather {
public:
    Weather(sf::RenderWindow* window);
    void initShape();
    void startRain();
    void updateRain(int windowTranslateY);
    void drawRaindrops();
    std::vector<sf::Sprite> getRaindrops();
    // void playSound();
    // void stopSound();

private:
    sf::RenderWindow* window;
    std::vector<sf::Sprite> raindrops;
    sf::Texture raindropTextures[3];
    
    bool isRaining = false;
    sf::Clock rainTimer;
    float rainDuration = 5.0f;
    sf::Clock frameClock;

    // sf::SoundBuffer rainBuffer;
    // sf::Sound rainSound;
};

#endif //WEATHER_HPP

