#include "header/endless.hpp"

Endless::Endless(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int a) : window(window), states(states), player(player), music(music) {
    setting = new Setting(window, states);

    if (!gameOverBuffer.loadFromFile("../resource/audio/gameOver.wav")) {
        std::cout << "Cannot load soundfile" << std::endl;
    }
    gameOverSound.setBuffer(gameOverBuffer);

    loadSkinFromFile("../data/save-game.txt");
    player->renderInGame();
    player->setMovementSpeed(10.0f);

    initShape();
    loadPositionFromFile("../data/save-game.txt");
    loadLane("../data/save-game.txt");
}

void Endless::loadSkinFromFile(std::string fileName) {
    std::ifstream fin(fileName);

    std::string color;
    getline(fin, color);
    if (color == "GREEN") player->setPlayerSkin(PlayerSkin::GREEN);
    else if (color == "BLUE") player->setPlayerSkin(PlayerSkin::BLUE);
    else if (color == "RED") player->setPlayerSkin(PlayerSkin::RED);
    else if (color == "YELLOW") player->setPlayerSkin(PlayerSkin::YELLOW);
    else if (color == "BROWN") player->setPlayerSkin(PlayerSkin::BROWN);
    fin.close();
}

void Endless::loadPositionFromFile(std::string fileName) {
    std::ifstream fin(fileName);
    std::string empty;
    getline(fin, empty);

    int posX, posY;
    fin >> posX >> posY;
    this->player->setPosition(posX, posY);

    fin >> posX >> posY;
    view->setCenter(posX, posY);

    fin >> this->windowTranslateY;

    fin >> posX >> posY;
    scoreBoardImage.setPosition(posX, posY);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    setting->setPositionComponents(x1, y1, x2, y2, x3, y3, x4, y4);

    fin.close();
}

void Endless::loadLane(std::string fileName) {
    std::ifstream fin(fileName);
    std::string empty;
    for (int i = 0 ; i < 7 ; ++i) getline(fin, empty);

    laneVector.clear();
    int n, type, posX, posY;
    fin >> n;
    for (int i = 0 ; i < n ; ++i) 
    {
        fin >> type >> posX >> posY;
        laneVector.push_back(new Lane(static_cast<laneType>(type)));
        laneVector[i]->setPosition(posX, posY);
    }

    fin.close();
}