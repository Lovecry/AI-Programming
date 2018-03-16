#include "Sheep.h"


Sheep::Sheep() {
		
	m_eAgentType = SHEEP;
		
	
	setVelocity({ 0.5f, 0.5f }); // non dovrebbe avere una base di velocità, dovrebbe essere 0

	setAcceleration({ 0.5f, 0.5f });
	setMaxVelocity(1.5f);

	setCircleRadius(8);
	setCircleDistance(6);
	setAngleChange(2);
	
	m_pSheepStateMachine = new SheepStateMachine(this);
	State<Sheep>* m_pStartState = (State<Sheep>*)&Pasture::getIInstance();
	m_pSheepStateMachine->SetCurrentState(m_pStartState);

	m_pSteeringBehaviors = new SteeringBehaviors(this);


	m_pSheepStateMachine->ChangeState(m_pStartState);

	setIsHead(false);
}

Sheep::~Sheep()
{
	/*if (m_pWolfStateMachine){
	delete m_pWolfStateMachine;
	}

	if (m_pSteeringBehaviors){
	delete m_pSteeringBehaviors;
	}*/
}

void Sheep::Update()
{
	//std::cout << "Update Cane " << std::endl;

	m_pSheepStateMachine->Update();
	m_pSteeringBehaviors->Calculate();
	setVelocity(m_pSteeringBehaviors->GetForce());
	setPosition(getPosition() + getVelocity());

	/*setVelocity( (getVelocity() + m_pSteeringBehaviors->GetForce()));
	m_vVelocity.Truncate(getMaxVelocity());
	setPosition(getPosition() + getVelocity());*/
}

