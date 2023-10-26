#include "header/menu.hpp"
#include <iostream>
#include <fstream>

void Menu::loadGame() {
    std::ifstream fin("../../data/history");
    if (!fin.is_open()) {
        std::cout << "Could not open history.txt !\n";
    }
    else {
        fin >> level;
        fin >> highScore;
    }
}