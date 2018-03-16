#pragma once
#include "StateMachine.h"
#include "Sheep.h"

class Sheep;
class SheepStateMachine : StateMachine < Sheep >
{

public:
	SheepStateMachine(Sheep* agent) :
		m_pCurrentState(nullptr),
		m_pPreviousState(nullptr),
		m_pCurrentAgent(agent)
	{};

	virtual ~SheepStateMachine() {};

	void SetCurrentState(State<Sheep>* s){ m_pCurrentState = s; }
	State<Sheep>*  GetCurrentState()  const{ return m_pCurrentState; }

	void SetPreviousState(State<Sheep>* s){ m_pPreviousState = s; }
	State<Sheep>*  GetPreviousState() const{ return m_pPreviousState; }

	virtual void  Update() const override;

	virtual void  ChangeState(State<Sheep>* pNewState) override;

	void  RevertToPreviousState(){ ChangeState(m_pPreviousState); }

	bool  isInState(const State<Sheep>& st) const { return true; };

	//bool setNeightBord(const std::vector<Agent*>& neighbors);

private:
	State<Sheep>*   m_pCurrentState;
	State<Sheep>*   m_pPreviousState;
	Sheep* m_pCurrentAgent;

};



