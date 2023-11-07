#include <iostream>
#include "SFML/Graphics.hpp"

enum class GameState {
    Entry,
    Menu,
};

class Game {
    public :
        Game();
        void run();

        void runEntry();
        void runMenu();

    private :
        int level;
        int score;
        int highScore;

        const int widthWindow;
        const int heightWindow;
        sf::RenderWindow window;

        GameState currentState;
};