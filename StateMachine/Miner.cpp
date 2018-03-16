#include "Miner.h"

Miner::Miner() {

	m_istamina = max_stamina;
	m_eLocation = home;

	setPosition({ 20.0f, 50.0f });
	//setVelocity({ 0.5f, 0.5f }); // non dovrebbe avere una base di velocità, dovrebbe essere 0

	setAcceleration({ 0.5f, 0.5f });
	setMaxVelocity(2.0f);

	m_eAgentType = GNOME;

	m_pMinerStateMachine = new MinerStateMachine(this);
	State<Miner>* m_pStartState = (State<Miner>*)&Idle::getIInstance();
	m_pMinerStateMachine->SetCurrentState(m_pStartState);

	m_pSteeringBehaviors = new SteeringBehaviors(this);
}

void Miner::Update()
{
	m_pMinerStateMachine->Update();
	m_pSteeringBehaviors->Calculate();
	setVelocity(m_pSteeringBehaviors->GetForce());
	setPosition(getPosition()+getVelocity());

	/*setVelocity((getVelocity() + m_pSteeringBehaviors->GetForce()));
	m_vVelocity.Truncate(getMaxVelocity());
	setPosition(getPosition() + getVelocity());*/
}
