#include "header/lane.hpp"
Lane::Lane(laneType type) : type(type) {
	((!(rand() % 3) && type != laneType::river) ? light = new TraficLight() : light = nullptr);
	((!(rand() % 5) && type != laneType::river) ? coin = new Coin[3] : coin = nullptr);
	if (!(rand() % 4)) {
		stuffVector.push_back(new UFO());
	}
	if (!(rand() % 4)) {
		stuffVector.push_back(new Ghost());
	}
	
	switch (type)
	{
	case laneType::desert_path:
		texture.loadFromFile("../resource/lane/desert_path_lane.png");
		if (!(rand() % 3)) {
			stuffVector.push_back(new Moon());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Mouse());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new SeaWheet());
		}
		break;
	case laneType::desert_road:
		texture.loadFromFile("../resource/lane/desert_road_lane.png");
		if (!(rand() % 3)) {
			stuffVector.push_back(new Moon());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Mouse());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new SeaWheet());
		}
		break;
	case laneType::road:
		texture.loadFromFile("../resource/lane/road_lane.png");
		if (!(rand() % 3)) {
			stuffVector.push_back(new Ant());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Bird());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Snail());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Frog());
		}
		break;
	case laneType::grass:
		texture.loadFromFile("../resource/lane/grass_lane.png");
		if (!(rand() % 3)) {
			stuffVector.push_back(new Ant());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Bird());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Snail());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Frog());
		}
		break;
	case laneType::river:
		texture.loadFromFile("../resource/lane/river_lane.png");
		for (int i = 0; i < 3; i++) {
			if (!(rand() % 3)) {
				stuffVector.push_back(new Fish());
				isJumped1[stuffVector.size() - 1] = 0;
				isJumped2[stuffVector.size() - 1] = 0;
			}
		}
		bridge = new Bridge[2];
		break;
	case laneType::snow_path:
		texture.loadFromFile("../resource/lane/snow_path_lane.png");
		if (!(rand() % 3)) {
			stuffVector.push_back(new Monster());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Slime());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Worm());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Bat());
		}
		break;
	case laneType::rail:
		texture.loadFromFile("../resource/lane/rail_lane.png");
		for (int i = 0; i < 3; i++) {
			if (!(rand() % 3)) {
				stuffVector.push_back(new Mouse());
			}
		}
		break;
	case laneType::desert_rail:
		texture.loadFromFile("../resource/lane/desert_rail_lane.png");
		for (int i = 0; i < 3; i++) {
			if (!(rand() % 3)) {
				stuffVector.push_back(new Mouse());

			}
		}
		break;
	case laneType::ice:
		texture.loadFromFile("../resource/lane/ice_lane.png");
		if (!(rand() % 3)) {
			stuffVector.push_back(new Monster());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Slime());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Worm());
		}
		if (!(rand() % 3)) {
			stuffVector.push_back(new Bat());
		}
		break;
	case laneType::desert_first_lane:
		texture.loadFromFile("../resource/lane/desert_path_plain.png");
		break;
	case laneType::garden_first_lane:
		texture.loadFromFile("../resource/lane/grass_plain.png");
		break;
	case laneType::snow_first_lane:
		texture.loadFromFile("../resource/lane/snow_path_plain.png");
		break;
	}
	for (int i = 0; i < stuffVector.size(); i++) {
		stuffVector[i]->setSpeed(((rand() % 2) + 1) * 0.01 * 60);
	}
	sprite.setTexture(texture);
}
sf::Vector2f Lane::getPosition() {
	return sprite.getPosition();
}
void Lane::setPosition(const sf::Vector2f& position) {
	sprite.setPosition(position);
}
void Lane::setPosition(float x, float y) {
	if (light) {
		light->setPosition(x + 17, y + 23);
	}
	if (coin) {
		int randomNum = rand() % 1000;
		for (int i = 0; i < 3; i++)
		{
			coin[i].setPosition(i * 55 + randomNum, y + 25);
		}
	}
	for (int i = 0; i < stuffVector.size(); i++) {
		if (type == laneType::river) {
			stuffVector[i]->setPosition(rand() % 1500, y + 85);
		}
		else {
			stuffVector[i]->setPosition(rand() % 1500, y + 25);
		}
	}
	if (type == laneType::river) {
		bridge[0].setPosition(150, y);
		bridge[1].setPosition(1000, y);
	}
	sprite.setPosition(sf::Vector2f(x, y));
}
void Lane::update() {
	if (light) {
		light->run();
	}
	if (coin) {
		for (int i = 0; i < 3; i++) {
			coin[i].run();
		}
	}
	for (int i = 0; i < stuffVector.size(); i++)
	{	
		if (light && light->getColor() == lightColor::Red) {
			stuffVector[i]->stop();
		}
		else{
			stuffVector[i]->resume();
			stuffVector[i]->run();
			if (stuffVector[i]->getPosition().x > 2000 || stuffVector[i]->getPosition().x < -500) {
				if (type == laneType::river) {
					stuffVector[i]->setPosition((rand() % 2) * 2000 + (rand() % 500 - 500), sprite.getPosition().y + 85);
					isJumped1[i] = 0;
					isJumped2[i] = 0;
				}
				else
				{
					stuffVector[i]->setPosition((rand() % 2) * 2000 + (rand() % 500 - 500), sprite.getPosition().y + 25);
				}
			}
			if (type == laneType::river) {

				if (stuffVector[i]->getPosition().x < 1140 && !isJumped1[i]) {
					stuffVector[i]->jump();
					isJumped1[i] = 1;
				}
				if (stuffVector[i]->getPosition().x < 290 && !isJumped2[i]) {
					stuffVector[i]->jump();
					isJumped2[i] = 1;
				}
			}
		}
		
	}
}
std::vector<Stuff*> Lane::getStuffVector() {
	return stuffVector;
}
void Lane::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
	if (type == laneType::river) {
		target.draw(bridge[0]);
		target.draw(bridge[1]);

	}
	if (coin) {
		for (int i = 0; i < 3; i++) {
			target.draw(coin[i]);
		}
	}
	if (light) {
		target.draw(*light);
	}
	
}

laneType randomFirstLaneType() {
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::desert_first_lane;
		break;
	case 1:
		type = laneType::garden_first_lane;
		break;
	case 2:
		type = laneType::snow_first_lane;
		break;
	}
	return type;
}

Bridge* Lane::getBridge(){
	return bridge;
}