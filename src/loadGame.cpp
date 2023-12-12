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

    stuffVector.clear();
    for (int i = 0 ; i < laneVector.size() ; ++i)
    {
        for (int j = 0 ; j < laneVector[i]->getStuffVector().size(); ++j)
        {
            stuffVector.push_back(laneVector[i]->getStuffVector()[j]);
        }
    }
}

Endless::~Endless() {
    if (!isGameOver) saveToFile("../data/save-game.txt");
    else {
        // make the file empty
        std::ofstream fout("../data/save-game.txt", std::ofstream::trunc);
        fout.close();
    }
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

    fout << desert << " " << garden << " " << snow << " ";
    fout << cont_path << " " << cont_road << " ";
    fout << points << " ";
    fout << railed << " " << rivered << " " << iced << "\n";
    
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

    fout << stuffVector.size() << "\n";
    for (Stuff* stuff : stuffVector) {
        if (typeid(*stuff) == typeid(UFO)) 
            fout << "UFO ";
        else if (typeid(*stuff) == typeid(Ant)) 
            fout << "Ant ";
        else if (typeid(*stuff) == typeid(Bird)) 
            fout << "Bird ";
        else if (typeid(*stuff) == typeid(Bat))
            fout << "Bat ";
        else if (typeid(*stuff) == typeid(Worm))
            fout << "Worm ";
        else if (typeid(*stuff) == typeid(Monster))
            fout << "Monster ";
        else if (typeid(*stuff) == typeid(Slime))
            fout << "Slime ";
        else if (typeid(*stuff) == typeid(Snail))
            fout << "Snail ";
        else if (typeid(*stuff) == typeid(Ghost))
            fout << "Ghost ";
        else if (typeid(*stuff) == typeid(Frog))
            fout << "Frog ";
        else if (typeid(*stuff) == typeid(Mouse))
            fout << "Mouse ";
        else if (typeid(*stuff) == typeid(Moon))
            fout << "Moon ";
        else if (typeid(*stuff) == typeid(SeaWheet))
            fout << "SeaWheet ";
        else if (typeid(*stuff) == typeid(Moon))
            fout << "Moon ";
        else if (typeid(*stuff) == typeid(Fish))
            fout << "Fish ";

        fout << stuff->getColor() << " " << (int)stuff->getPosition().x << " " << (int)stuff->getPosition().y << "\n";
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
    int n, type, posX, posY, size_stuffVector;
    fin >> n;
    for (int i = 0 ; i < n ; ++i) 
    {
        fin >> type >> posX >> posY;
        laneVector.push_back(new Lane(static_cast<laneType>(type)));
        laneVector[i]->setPosition(posX, posY);
        (laneVector[i]->getStuffVector()).clear();
        fin >> size_stuffVector;
        for (int j = 0 ; j < size_stuffVector ; ++j) 
        {
            std::string stuffName;
            int type;
            float speed;
            fin >> stuffName;

            if (stuffName == "UFO") {
                fin >> type;
                laneVector[i]->getStuffVector().push_back(new UFO(static_cast<UFOColor>(type)));
            }
            else if (stuffName == "Ant") {
                laneVector[i]->getStuffVector().push_back(new Ant());
            }
            else if (stuffName == "Bird") {
                laneVector[i]->getStuffVector().push_back(new Bird());
            }
            else if (stuffName == "Bat") {
                laneVector[i]->getStuffVector().push_back(new Bat());
            }
            else if (stuffName == "Worm") {
                laneVector[i]->getStuffVector().push_back(new Worm());
            }
            else if (stuffName == "Monster") {
                laneVector[i]->getStuffVector().push_back(new Monster());
            }
            else if (stuffName == "Slime") {
                laneVector[i]->getStuffVector().push_back(new Slime());
            }
            else if (stuffName == "Snail") {
                laneVector[i]->getStuffVector().push_back(new Snail());
            }
            else if (stuffName == "Ghost") {
                laneVector[i]->getStuffVector().push_back(new Ghost());
            }
            else if (stuffName == "Frog") {
                laneVector[i]->getStuffVector().push_back(new Frog());
            }
            else if (stuffName == "Mouse") {
                laneVector[i]->getStuffVector().push_back(new Mouse());
            }
            else if (stuffName == "Moon") {
                laneVector[i]->getStuffVector().push_back(new Moon());
            }
            else if (stuffName == "SeaWheet") {
                laneVector[i]->getStuffVector().push_back(new SeaWheet());
            }
            else if (stuffName == "Fish") {
                fin >> type;
                laneVector[i]->getStuffVector().push_back(new Fish(static_cast<fishColor>(type)));
            }
            fin >> posX >> posY >> speed;
            std::cout << i << " " << j << "\n";
            std::cout << posX << " " << posY << "\n";

            auto stuffVec = laneVector[i]->getStuffVector();
            stuffVec[j]->setPosition(sf::Vector2f(posX, posY));
            // laneVector[i]->getStuffVector()[j]->setSpeed(speed);
        }
    }

    // fin >> n;
    // std::string stuffName;
    // for (int i = 0 ; i < n ; ++i)
    // {
    //     fin >> stuffName;

    //     if (stuffName == "UFO") {
    //         fin >> type;
    //         stuffVector.push_back(new UFO(static_cast<UFOColor>(type)));
    //     }
    //     else if (stuffName == "Ant") {
    //         stuffVector.push_back(new Ant());
    //     }
    //     else if (stuffName == "Bird") {
    //         stuffVector.push_back(new Bird());
    //     }
    //     else if (stuffName == "Bat") {
    //         stuffVector.push_back(new Bat());
    //     }
    //     else if (stuffName == "Worm") {
    //         stuffVector.push_back(new Worm());
    //     }
    //     else if (stuffName == "Monster") {
    //         stuffVector.push_back(new Monster());
    //     }
    //     else if (stuffName == "Slime") {
    //         stuffVector.push_back(new Slime());
    //     }
    //     else if (stuffName == "Snail") {
    //         stuffVector.push_back(new Snail());
    //     }
    //     else if (stuffName == "Ghost") {
    //         stuffVector.push_back(new Ghost());
    //     }
    //     else if (stuffName == "Frog") {
    //         stuffVector.push_back(new Frog());
    //     }
    //     else if (stuffName == "Mouse") {
    //         stuffVector.push_back(new Mouse());
    //     }
    //     else if (stuffName == "Moon") {
    //         stuffVector.push_back(new Moon());
    //     }
    //     else if (stuffName == "SeaWheet") {
    //         stuffVector.push_back(new SeaWheet());
    //     }
    //     else if (stuffName == "Fish") {
    //         fin >> type;
    //         stuffVector.push_back(new Fish(static_cast<fishColor>(type)));
    //     }
    //     fin >> posX >> posY;
    //     stuffVector[i]->setPosition(posX, posY);
    // }

    fin.close();
}
