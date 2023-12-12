#ifndef LANE_HPP
#define LANE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "stuff.hpp"

const int landHeight = 165;
enum class laneType {
	desert_path, desert_road, road, grass, river, snow_path, rail, desert_rail, ice, desert_first_lane, garden_first_lane, snow_first_lane, 
	desert_finish, garden_finish, snow_finish
};

class Lane : public sf::Drawable
{
public:
	Lane(laneType type);
	~Lane();
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	void update();
	laneType type;
	std::vector<Stuff*> getStuffVector();
	void setStuffVector(std::vector<Stuff*> &subStuffVector);
	Bridge* getBridge();
	Coin* getCoin();
private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	TraficLight* light = nullptr;
	std::vector<Stuff*> stuffVector;
	Coin* coin = nullptr;
	Bridge* bridge = nullptr;
	bool isJumped1[3];
	bool isJumped2[3];
};

laneType randomFirstLaneType();

#endif