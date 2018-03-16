#pragma once
#include "StateMachine.h"
#include "Miner.h"

class Miner;
class MinerStateMachine : StateMachine<Miner> {
private:
	State<Miner>*   m_pCurrentState;
	State<Miner>*   m_pPreviousState;
	Miner* m_pCurrentAgent;

public:
	MinerStateMachine(Miner* agent) :
		m_pCurrentState(nullptr),
		m_pPreviousState(nullptr),
		m_pCurrentAgent(agent)
	{};

	virtual ~MinerStateMachine() {};

	void SetCurrentState(State<Miner>* s){ m_pCurrentState = s; }
	State<Miner>*  GetCurrentState()  const{ return m_pCurrentState; }

	void SetPreviousState(State<Miner>* s){ m_pPreviousState = s; }
	State<Miner>*  GetPreviousState() const{ return m_pPreviousState; }

	void  Update() const;

	void  ChangeState(State<Miner>* pNewState);

	void  RevertToPreviousState(){ ChangeState(m_pPreviousState); }

	bool  isInState(const State<Miner>& st) const { return true; };
};