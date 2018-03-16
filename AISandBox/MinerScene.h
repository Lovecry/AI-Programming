#pragma once

#include "IScene.h"

#include "Miner.h"
#include "Graphic.h"
#include "GraphicsMove.h"
#include "Wolf.h"
#include "Sheep.h"

using namespace SMnamespace;


class MinerScene : public IScene
{
public:

	MinerScene();
	virtual ~MinerScene();
    
	virtual void OnIdle();
	virtual void OnDraw(sf::RenderWindow& renderWindow);

private:
	Graphic m_GraphMiner;
	GraphicsMove m_Graphics;
	
	Wolf m_Wolf;

	Miner m_Miner1;
	Miner m_Miner2;
	Miner m_Miner3;

	std::vector<Agent*> m_NeighborsSheep;

	Sheep sheep1;
	Sheep sheep2;
	Sheep sheep3;
	Sheep sheep4;
	Sheep sheep5;
};

