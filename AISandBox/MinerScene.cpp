#include "MinerScene.h"
#include "Application.h"


MinerScene::MinerScene()
{
	m_GraphMiner.Initialize();
	m_Graphics.Initialize();

	m_Miner2.setPosition(60.0f, 60.0f);
	m_Miner3.setPosition(40.0f, 50.0f);
	
	m_Wolf.setPosition({ enclosureCenter.x + radiusEnclosure + 5, enclosureCenter.y });

	sheep1.setPosition(enclosureCenter.x, enclosureCenter.y);
	sheep2.setPosition(enclosureCenter.x +30, enclosureCenter.y);
	sheep3.setPosition(enclosureCenter.x + 20, enclosureCenter.y+30);
	sheep4.setPosition(enclosureCenter.x + 40, enclosureCenter.y + 30);
	sheep5.setPosition(enclosureCenter.x + 50, enclosureCenter.y + 50);
	
	sheep1.setIsHead(false);
	
	m_NeighborsSheep.push_back(&sheep1);
	m_NeighborsSheep.push_back(&sheep2);
	m_NeighborsSheep.push_back(&sheep3);
	m_NeighborsSheep.push_back(&sheep4);
	m_NeighborsSheep.push_back(&sheep5);

	sheep1.SetNeighbors(m_NeighborsSheep);
	sheep2.SetNeighbors(m_NeighborsSheep);
	sheep3.SetNeighbors(m_NeighborsSheep);
	sheep4.SetNeighbors(m_NeighborsSheep);
	sheep5.SetNeighbors(m_NeighborsSheep);

	m_Graphics.addActor(&m_Miner1);
	m_Graphics.addActor(&m_Miner2);
	m_Graphics.addActor(&m_Miner3);
	m_Graphics.addActor(&m_Wolf);
	m_Graphics.addActor(&sheep1);
	m_Graphics.addActor(&sheep2);
	m_Graphics.addActor(&sheep3);
	m_Graphics.addActor(&sheep4);
	m_Graphics.addActor(&sheep5);
}

MinerScene::~MinerScene()
{
}

void MinerScene::OnIdle()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		Application::Istance()->SetScene(SceneEnum::Scene_MainMenu);
		//alg.Finish();
	}
}

void MinerScene::OnDraw(sf::RenderWindow& renderWindow)
{
	m_GraphMiner.Draw(m_Miner3.getLocation());
	m_Graphics.UpdateAgent(); // fa lupdate di tutti gli agent presenti
	m_Graphics.Draw();
}





