#include "SFML/Graphics.hpp"
#include <iostream>

class Game {
    public :
        Game();
        void run();

    private :
        int level;
        int score;
        int highScore;
        const int widthWindow;
        const int heightWindow;
};