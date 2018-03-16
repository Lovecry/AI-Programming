#pragma once;

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Miner.h"

class Graphic{
public:
	Graphic(){};
	~Graphic(){};

	void Initialize();
	void Draw(location_type);

private:
	sf::Font font;
	sf::Text textIdle, textWalk, textMining, textCurrentState;
	sf::CircleShape circleIdle, circleWalk, circleMining, circleCurrentState;
	sf::Color color;
	sf::RenderWindow window;
};