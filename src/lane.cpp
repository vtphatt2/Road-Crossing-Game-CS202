#include "header/lane.hpp"
Lane::Lane(laneType type) : type(type) {
	switch (type)
	{
	case laneType::desert_path:
		texture.loadFromFile("../resource/lane/desert_path_lane.png");
		break;
	case laneType::desert_road:
		texture.loadFromFile("../resource/lane/desert_road_lane.png");
		break;
	case laneType::road:
		texture.loadFromFile("../resource/lane/road_lane.png");
		break;
	case laneType::grass:
		texture.loadFromFile("../resource/lane/grass_lane.png");
		break;
	case laneType::river:
		texture.loadFromFile("../resource/lane/river_lane.png");
		break;
	case laneType::snow_path:
		texture.loadFromFile("../resource/lane/snow_path_lane.png");
		break;
	case laneType::rail:
		texture.loadFromFile("../resource/lane/rail_lane.png");
		break;
	case laneType::desert_rail:
		texture.loadFromFile("../resource/lane/desert_rail_lane.png");
		break;
	case laneType::ice:
		texture.loadFromFile("../resource/lane/ice_lane.png");
		break;
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
	sprite.setPosition(sf::Vector2f(x, y));
}
void Lane::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

int convertBiome()
{
	int randomNum = rand() % 3;
	return randomNum;
}

laneType randomFirstLaneType() 
{
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::desert_path;
		break;
	case 1:
		type = laneType::grass;
		break;
	case 2:
		type = laneType::snow_path;
		break;
	}
	return type;
}