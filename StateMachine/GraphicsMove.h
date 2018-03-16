#pragma once;

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Miner.h"
#include "Sheep.h"
#include "Agent.h"
#include <vector>
#include "Vector2.h"


class GraphicsMove{
public:
	GraphicsMove(){};
	~GraphicsMove();

	void Initialize();	
	void Draw();
	void addActor(Agent *agent);

	void UpdateAgent();
private:
	sf::Font m_font;
	std::vector<Agent*> *m_VectorAgent;
	std::vector<sf::CircleShape *> *m_VectorCircle;
	sf::Color color;
	sf::RenderWindow m_window;

	sf::CircleShape m_minerCircle;
	sf::CircleShape m_circleHome;
	sf::CircleShape m_circleMine;
	sf::CircleShape m_circleEnclosure;
	sf::CircleShape m_circleLimitWolf;

	sf::Texture m_texGnomo;
	sf::Texture m_texCane;
	sf::Texture m_texSheep, m_texBSheep;
	sf::Texture m_texMiniera;
	sf::Texture m_texCasa;

	sf::Sprite m_sprGnomo;
	sf::Sprite m_sprCane;
	sf::Sprite m_sprSheep, m_sprBSheep;
	sf::Sprite m_sprMiniera;
	sf::Sprite m_sprCasa;
};