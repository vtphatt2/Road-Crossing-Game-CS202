#include "header/endless.hpp"

Endless::Endless(sf::RenderWindow* window, std::stack <State*>* states, Player* player, sf::Music& music, int a) : window(window), states(states), player(player), music(music) {
    gameOverBuffer.loadFromFile("../resource/audio/gameOver.wav");
    gameOverSound.setBuffer(gameOverBuffer);
    coinEatenBuffer.loadFromFile("../resource/audio/short-success.mp3");
    coinEaten.setBuffer(coinEatenBuffer);

    weather = new Weather(window);

    loadSkinFromFile("../data/save-game.txt");
    player->renderInGame();
    player->setMovementSpeed(10.0f);

    initShape();
    setting = new Setting(window, states, music, player, stuffVector, laneVector, view, weather);
    loadPositionFromFile("../data/save-game.txt");
    loadLane("../data/save-game.txt");
}

Endless::~Endless() {
    if (save) saveToFile("../data/save-game.txt");
    coinEaten.stop();
    gameOverSound.stop();
    delete setting;
    delete weather;
    delete view;

    setting = nullptr;
    weather = nullptr;
    view = nullptr;
}

void Endless::clearDataLoadGame() {
    std::ofstream fout("../data/save-game.txt", std::ofstream::trunc);
    fout.close();
}

void Endless::saveToFile(std::string fileName) {
	std::ofstream fout(fileName, std::ofstream::trunc);
    if (!fout.is_open()) 
    {
        std::cout << "Can not open file !\n";
        fout.close();
        return ;
    }

    fout << player->getPlayerSkin() << "\n";
    fout << player->getPlayerSprite().getPosition().x << " " << player->getPlayerSprite().getPosition().y << "\n";

    fout << view->getCenter().x << " " << view->getCenter().y << "\n";
    fout << windowTranslateY << "\n";
    fout << scoreBoardImage.getPosition().x << " " << scoreBoardImage.getPosition().y << "\n";

    fout << setting->positionComponents() << "\n";

    fout << score << " " << (int)scoreText.getPosition().x << " " << (int)scoreText.getPosition().y << "\n";
    
    fout << laneVector.size() << "\n";
    for (int i = 0 ; i < laneVector.size() ; ++i)
    {
        fout << (int)laneVector[i]->type << " " << laneVector[i]->getPosition().x << " " << laneVector[i]->getPosition().y << "\n";
        fout << laneVector[i]->getStuffVector().size() << "\n";
        for (int j = 0 ; j < laneVector[i]->getStuffVector().size() ; ++j)
        {
            Stuff* stuff_ptr = laneVector[i]->getStuffVector()[j];
            if (typeid(*stuff_ptr) == typeid(UFO))
                fout << "UFO ";
            else if (typeid(*stuff_ptr) == typeid(Ant))
                fout << "Ant ";
            else if (typeid(*stuff_ptr) == typeid(Bird))
                fout << "Bird ";
            else if (typeid(*stuff_ptr) == typeid(Bat))
                fout << "Bat ";
            else if (typeid(*stuff_ptr) == typeid(Worm))
                fout << "Worm ";
            else if (typeid(*stuff_ptr) == typeid(Monster))
                fout << "Monster ";
            else if (typeid(*stuff_ptr) == typeid(Slime))
                fout << "Slime ";
            else if (typeid(*stuff_ptr) == typeid(Snail))
                fout << "Snail ";
            else if (typeid(*stuff_ptr) == typeid(Ghost))
                fout << "Ghost ";
            else if (typeid(*stuff_ptr) == typeid(Frog))
                fout << "Frog ";
            else if (typeid(*stuff_ptr) == typeid(Mouse))
                fout << "Mouse ";
            else if (typeid(*stuff_ptr) == typeid(Moon))
                fout << "Moon ";
            else if (typeid(*stuff_ptr) == typeid(SeaWheet))
                fout << "SeaWheet ";
            else if (typeid(*stuff_ptr) == typeid(Fish))
                fout << "Fish ";

            fout << laneVector[i]->getStuffVector()[j]->getColor() << " " << (int)laneVector[i]->getStuffVector()[j]->getPosition().x << " " << (int)laneVector[i]->getStuffVector()[j]->getPosition().y << " " << laneVector[i]->getStuffVector()[j]->getSpeed() << "\n";
        }
    }

    fout.close();
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

    fin >> posX >> posY;
    setting->setPositionComponents(posX, posY);

    fin >> score >> posX >> posY;
    scoreText.setPosition(posX, posY);

    fin.close();
}

void Endless::loadLane(std::string fileName) {
    std::ifstream fin(fileName);
    std::string empty;
    for (int i = 0 ; i < 7 ; ++i) getline(fin, empty);

    laneVector.clear();
    int n, type, posX, posY, size_stuffVector;
    fin >> n;
    for (int i = 0 ; i < n ; ++i) 
    {
        fin >> type >> posX >> posY;
        laneVector.push_back(new Lane(static_cast<laneType>(type)));
        laneVector[i]->setPosition(posX, posY);
        std::vector <Stuff*> subStuffVector;
        fin >> size_stuffVector;

        for (int j = 0 ; j < size_stuffVector ; ++j) 
        {
            std::string stuffName;
            int type;
            float speed;
            fin >> stuffName;

            if (stuffName == "UFO") {
                fin >> type;
                subStuffVector.push_back(new UFO(static_cast<UFOColor>(type)));
            }
            else if (stuffName == "Ant") {
                subStuffVector.push_back(new Ant());
            }
            else if (stuffName == "Bird") {
                subStuffVector.push_back(new Bird());
            }
            else if (stuffName == "Bat") {
                subStuffVector.push_back(new Bat());
            }
            else if (stuffName == "Worm") {
                subStuffVector.push_back(new Worm());
            }
            else if (stuffName == "Monster") {
                subStuffVector.push_back(new Monster());
            }
            else if (stuffName == "Slime") {
                subStuffVector.push_back(new Slime());
            }
            else if (stuffName == "Snail") {
                subStuffVector.push_back(new Snail());
            }
            else if (stuffName == "Ghost") {
                subStuffVector.push_back(new Ghost());
            }
            else if (stuffName == "Frog") {
                subStuffVector.push_back(new Frog());
            }
            else if (stuffName == "Mouse") {
                subStuffVector.push_back(new Mouse());
            }
            else if (stuffName == "Moon") {
                subStuffVector.push_back(new Moon());
            }
            else if (stuffName == "SeaWheet") {
                subStuffVector.push_back(new SeaWheet());
            }
            else if (stuffName == "Fish") {
                fin >> type;
                subStuffVector.push_back(new Fish(static_cast<fishColor>(type)));
            }

            fin >> posX >> posY >> speed;
            subStuffVector[j]->setPosition(sf::Vector2f(posX, posY));
            subStuffVector[j]->setSpeed(speed);
        }

        laneVector[i]->setStuffVector(subStuffVector);
    }

    fin.close();

    stuffVector.clear();
    for (int i = 0 ; i < laneVector.size() ; ++i)
    {
        for (int j = 0 ; j < laneVector[i]->getStuffVector().size(); ++j)
        {
            stuffVector.push_back(laneVector[i]->getStuffVector()[j]);
        }
    }
}


void Endless::updateHighScore(std::string fileName) {
    std::ifstream fin(fileName);
    std::priority_queue <int> scores;
    int x;
    while (fin >> x) scores.push(x);
    fin.close();
    scores.push(0);
    scores.push(0);
    scores.push(0);
    scores.push(this->score);

    std::ofstream fout(fileName);
    fout << scores.top() << "\n";
    scores.pop();
    fout << scores.top() << "\n";
    scores.pop();
    fout << scores.top() << "\n";
    fout.close();
} 