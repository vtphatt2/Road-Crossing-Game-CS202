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

laneType randomFirstLaneType() {
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

laneType randomDesertLaneType() {
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::desert_path;
		break;
	case 1:
		type = laneType::desert_road;
		break;
	case 2:
		type = laneType::desert_rail;
		break;
	}
	return type;
}
	
laneType randomGardenLaneType() {
	int randomNum = rand() % 4;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::grass;
		break;
	case 1:
		type = laneType::river;
		break;
	case 2:
		type = laneType::rail;
		break;
	case 3:
		type = laneType::road;
		break;
	}
	return type;
}	

laneType randomSnowLaneType() {
	int randomNum = rand() % 4;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::snow_path;
		break;
	case 1:
		type = laneType::rail;
		break;
	case 2:
		type = laneType::road;
		break;
	case 3:
		type = laneType::ice;
		break;
	}
	return type;
}

int convertBiome()
{
	int randomNum = rand() % 3;
	return randomNum;
}

laneType randomDesert_NoDesertRail()
{
	int randomNum = rand() % 2;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::desert_path;
		break;
	case 1:
		type = laneType::desert_road;
		break;
	}
	return type;
}

laneType randomDesert_NoDesertRoad()
{
	int randomNum = rand() % 2;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::desert_path;
		break;
	case 1:
		type = laneType::desert_rail;
		break;
	}
	return type;
}

laneType randomDesert_NoDesertPath()
{
	int randomNum = rand() % 2;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::desert_road;
		break;
	case 1:
		type = laneType::desert_rail;
		break;
	}
	return type;
}

laneType randomDesert_NoDesertRailNoDesertRoad()
{
	return laneType::desert_path;
}

laneType randomDesert_NoDesertRailNoDesertPath()
{
	return laneType::desert_road;
}

laneType randomGarden_NoGrass()
{
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::river;
		break;
	case 1:
		type = laneType::rail;
		break;
	case 2:
		type = laneType::road;
		break;
	}
	return type;
}

laneType randomGarden_NoRiver()
{
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::grass;
		break;
	case 1:
		type = laneType::rail;
		break;
	case 2:
		type = laneType::road;
		break;
	}
	return type;
}

laneType randomGarden_NoRoad()
{
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::grass;
		break;
	case 1:
		type = laneType::river;
		break;
	case 2:
		type = laneType::rail;
		break;
	}
	return type;
}

laneType randomGarden_NoRail()
{
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::grass;
		break;
	case 1:
		type = laneType::river;
		break;
	case 2:
		type = laneType::road;
		break;
	}
	return type;
}

laneType randomGarden_NoRailNoRiver()
{
	int randomNum = rand() % 2;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::grass;
		break;
	case 1:
		type = laneType::road;
		break;
	}
	return type;
}

laneType randomGarden_NoRailNoGrass()
{
	int randomNum = rand() % 2;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::river;
		break;
	case 1:
		type = laneType::road;
		break;
	}
	return type;
}

laneType randomGarden_NoRailNoRoad()
{
	int randomNum = rand() % 2;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::grass;
		break;
	case 1:
		type = laneType::river;
		break;
	}
	return type;
}

laneType randomSnow_NoSnowPath()
{
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::rail;
		break;
	case 1:
		type = laneType::road;
		break;
	case 2:
		type = laneType::ice;
		break;
	}
	return type;
}

laneType randomSnow_NoIce()
{
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::snow_path;
		break;
	case 1:
		type = laneType::rail;
		break;
	case 2:
		type = laneType::road;
		break;
	}
	return type;
}

laneType randomSnow_NoRoad()
{
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::snow_path;
		break;
	case 1:
		type = laneType::rail;
		break;
	case 2:
		type = laneType::ice;
		break;
	}
	return type;
}

laneType randomSnow_NoRail()
{
	int randomNum = rand() % 3;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::snow_path;
		break;
	case 1:
		type = laneType::road;
		break;
	case 2:
		type = laneType::ice;
		break;
	}
	return type;
}

laneType randomSnow_NoRailNoSnowPath()
{
	int randomNum = rand() % 2;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::road;
		break;
	case 1:
		type = laneType::ice;
		break;
	}
	return type;
}

laneType randomSnow_NoRailNoIce()
{
	int randomNum = rand() % 2;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::snow_path;
		break;
	case 1:
		type = laneType::road;
		break;
	}
	return type;
}

laneType randomSnow_NoRailNoRoad()
{
	int randomNum = rand() % 2;
	laneType type;
	switch (randomNum)
	{
	case 0:
		type = laneType::snow_path;
		break;
	case 1:
		type = laneType::ice;
		break;
	}
	return type;
}