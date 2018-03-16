#pragma once

#include "Agent.h"
#include "WolfStateMachine.h"
#include "SteeringBehaviors.h"
#include "Wander.h"

class WolfStateMachine;

class Wolf : public Agent
{
private:
	WolfStateMachine* m_pWolfStateMachine;
	SteeringBehaviors* m_pSteeringBehaviors;
	
public:
	Wolf();
	~Wolf();

	virtual void Update() override;
	WolfStateMachine* getStateMachine() { return m_pWolfStateMachine; };
	SteeringBehaviors* getSteeringBehavior() { return m_pSteeringBehaviors; };

};


