#include "GraphicsMove.h"

void GraphicsMove::Initialize() {

	m_VectorAgent = new std::vector<Agent*>();
	m_VectorCircle = new std::vector<sf::CircleShape *>();

	m_window.create(sf::VideoMode(800, 600), "FSM Miner at Work!");

	if (!m_texGnomo.loadFromFile("../StateMachine/Sprites/gnomo.png"))
	{
		// error...
	}
	if (!m_texCane.loadFromFile("../StateMachine/Sprites/cane.png"))
	{
		// error...
	}
	if (!m_texSheep.loadFromFile("../StateMachine/Sprites/sheep.png"))
	{
		// error...
	}
	if (!m_texBSheep.loadFromFile("../StateMachine/Sprites/black_sheep.png"))
	{
		// error...
	}
	if (!m_texMiniera.loadFromFile("../StateMachine/Sprites/miniera.png"))
	{
		// error...
	}
	if (!m_texCasa.loadFromFile("../StateMachine/Sprites/casa.png"))
	{
		// error...
	}	
	
	m_sprCasa.setTexture(m_texCasa);
	m_sprCasa.setPosition((positionHome.x-10), (positionHome.y-50));
	m_sprCasa.setScale(0.4,0.4);

	m_sprMiniera.setTexture(m_texMiniera);
	m_sprMiniera.setPosition((positionMine.x-50), (positionMine.y-50));
	m_sprMiniera.setScale(0.4, 0.4);

	m_sprGnomo.setTexture(m_texGnomo);
	m_sprGnomo.setScale(0.3, 0.3);

	m_sprCane.setTexture(m_texCane);
	m_sprCane.setScale(0.1, 0.1);

	m_sprSheep.setTexture(m_texSheep);
	m_sprSheep.setScale(0.2, 0.2);

	m_sprBSheep.setTexture(m_texBSheep);
	m_sprBSheep.setScale(0.2, 0.2);

	
	m_circleEnclosure.setRadius(radiusEnclosure);
	m_circleEnclosure.setOrigin(radiusEnclosure, radiusEnclosure);
	m_circleEnclosure.setFillColor(color.Black);
	m_circleEnclosure.setOutlineColor({139,69,19});
	m_circleEnclosure.setOutlineThickness(10);
	//circleEnclosure.setPosition(0, 0);
	m_circleEnclosure.setPosition(enclosureCenter.x , enclosureCenter.y);

	//circleLimitWolf.setRadius(LimitDistanceWolf);
	//circleLimitWolf.setOrigin(LimitDistanceWolf, LimitDistanceWolf);
	//circleLimitWolf.setFillColor(color.Cyan);
	////circleLimitWolf.setPosition(0,0);
	//circleLimitWolf.setPosition(enclosureCenter.x , enclosureCenter.y  );
}

void GraphicsMove::Draw() {

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
	}

	m_window.clear();
	m_window.draw(m_sprCasa);
	m_window.draw(m_sprMiniera);
	//window.draw(circleLimitWolf);
	m_window.draw(m_circleEnclosure);
	

	for (int i = 0; i < m_VectorCircle->size(); i++)
	{
		Agent *tmp = m_VectorAgent->at(i);
		sf::CircleShape *tmpCircle = m_VectorCircle->at(i);
					
		tmpCircle->setPosition(tmp->getPosition().x, tmp->getPosition().y);

		if (tmp->GetAgentType() == GNOME)
		{
			m_sprGnomo.setPosition(tmpCircle->getPosition().x, tmpCircle->getPosition().y);
			m_window.draw(m_sprGnomo);
		}
		else if (tmp->GetAgentType() == SHEEP)
		{
			if (((Sheep*)tmp)->isHead())
			{
				m_sprBSheep.setPosition(tmpCircle->getPosition().x, tmpCircle->getPosition().y);
				m_window.draw(m_sprBSheep);
			}
			else
			{
				m_sprSheep.setPosition(tmpCircle->getPosition().x, tmpCircle->getPosition().y);
				m_window.draw(m_sprSheep);
			}
		}
		else if (tmp->GetAgentType() == DOG)
		{
			m_sprCane.setPosition(tmpCircle->getPosition().x, tmpCircle->getPosition().y);
			m_window.draw(m_sprCane);
		}
	}

	m_window.display();
}

void GraphicsMove::addActor(Agent *agent)
{
	m_VectorAgent->push_back( agent );

	sf::CircleShape *circle = new sf::CircleShape();
	circle->setRadius(10.f);
	circle->setFillColor(color.Red);
	circle->setPosition(agent->getPosition().x, agent->getPosition().y);
	
	m_VectorCircle->push_back(circle);

}

void GraphicsMove::UpdateAgent()
{
	for (int i = 0; i < m_VectorAgent->size(); i++)
	{
		Agent *tmp = m_VectorAgent->at(i);
		tmp->Update();
		
	}
}

GraphicsMove::~GraphicsMove(){

	for (int i = 0; i < m_VectorCircle->size(); i++) 
	{
		delete m_VectorCircle->at(i);
	}

	delete m_VectorAgent;
	delete m_VectorCircle;
}
