#include "Wolf.h"

Wolf::Wolf() {

	//m_vPosition = { 50, 150 };
	//setPosition({ 0, 0 });
	//setPosition({ enclosureCenter.x + radiusEnclosure + 5, enclosureCenter.y   });
	setVelocity({ 0.5f, 0.5f }); // non dovrebbe avere una base di velocità, dovrebbe essere 0
	
	setAcceleration({ 0.5f, 0.5f });
	setMaxVelocity(1.5f);

	setCircleRadius(8);
	setCircleDistance(6);
	setAngleChange(2);
	
	m_eAgentType = DOG;

	m_pWolfStateMachine = new WolfStateMachine(this);
	State<Wolf>* m_pStartState = (State<Wolf>*)&Wander::getIInstance();
	m_pWolfStateMachine->SetCurrentState(m_pStartState);

	m_pSteeringBehaviors = new SteeringBehaviors(this);


	m_pWolfStateMachine->ChangeState(m_pStartState);
}

Wolf::~Wolf()
{
	/*if (m_pWolfStateMachine){
		delete m_pWolfStateMachine;
	}

	if (m_pSteeringBehaviors){
		delete m_pSteeringBehaviors;
	}*/
}

void Wolf::Update()
{
	//std::cout << "Update Cane " << std::endl;

	m_pWolfStateMachine->Update();
	m_pSteeringBehaviors->Calculate();
	setVelocity(m_pSteeringBehaviors->GetForce());
	setPosition(getPosition() + getVelocity());

	/*setVelocity( (getVelocity() + m_pSteeringBehaviors->GetForce()));
	m_vVelocity.Truncate(getMaxVelocity());
	setPosition(getPosition() + getVelocity());*/
}

