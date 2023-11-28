#pragma once
#include "SFML/Graphics.hpp"
#include "stuff.hpp"
const int landHeight = 165;
enum class laneType {
	desert_path, desert_road, road, grass, river, snow_path, rail, desert_rail, ice
};

class Lane: public sf::Drawable
{
public:
	Lane(laneType type);
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	void update();
	laneType type;
	std::vector<Stuff*> getStuffVector();
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	TraficLight* light;
	std::vector<Stuff*> stuffVector;
	Coin* coin;
	Bridge* bridge;
	bool isJumped1[3];
	bool isJumped2[3];
};
laneType randomFirstLaneType();
laneType randomDesertLaneType();
laneType randomGardenLaneType();
laneType randomSnowLaneType();
int convertBiome();

laneType randomDesert_NoDesertRail();
laneType randomDesert_NoDesertRoad();
laneType randomDesert_NoDesertPath();
laneType randomDesert_NoDesertRailNoDesertRoad();
laneType randomDesert_NoDesertRailNoDesertPath();

laneType randomGarden_NoGrass();
laneType randomGarden_NoRiver();
laneType randomGarden_NoRoad();
laneType randomGarden_NoRail();
laneType randomGarden_NoRailNoRiver();
laneType randomGarden_NoRailNoGrass();
laneType randomGarden_NoRailNoRoad();

laneType randomSnow_NoSnowPath();
laneType randomSnow_NoIce();
laneType randomSnow_NoRoad();
laneType randomSnow_NoRail();
laneType randomSnow_NoRailNoSnowPath();
laneType randomSnow_NoRailNoIce();
laneType randomSnow_NoRailNoRoad();