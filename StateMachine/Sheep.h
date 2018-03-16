#pragma once
#include "Agent.h"
#include "SteeringBehaviors.h"
#include "SheepStateMachine.h"
#include "Pasture.h"
#include "Wolf.h"


class SheepStateMachine;

class Sheep : public Agent
{
private:
	SheepStateMachine* m_pSheepStateMachine;
	SteeringBehaviors* m_pSteeringBehaviors;
	bool Head;

public:
	Sheep();
	~Sheep();

	virtual void Update() override;
	SheepStateMachine* getStateMachine() { return m_pSheepStateMachine; };
	SteeringBehaviors* getSteeringBehavior() { return m_pSteeringBehaviors; };
	void SetNeighbors(std::vector<Agent*> nNeighbors){
		m_pSteeringBehaviors->SetNeighbors(nNeighbors);
	}
	void setIsHead(bool value = true){

		if (value){
			m_pSteeringBehaviors->WanderOn();
		}
		else{
			m_pSteeringBehaviors->WanderOff();
		}

		Head = value;
	}

	bool isHead() const{ return Head; }
	
};
