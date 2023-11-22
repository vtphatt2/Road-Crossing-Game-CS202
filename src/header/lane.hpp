#pragma once
#include "SFML/Graphics.hpp"
const int landHeight = 165;
enum class laneType {
	desert_path, desert_road, road, grass, river, snow_path, rail
};

class Lane: public sf::Drawable
{
public:
	Lane(laneType type);
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	void setPosition(float x, float y);
	laneType type;

private:
	sf::Texture texture;
	sf::Sprite sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
};
laneType randomLaneType();
