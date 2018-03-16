#include "MinerStateMachine.h"

void MinerStateMachine::Update() const
{
	if (m_pCurrentState) m_pCurrentState->Execute(m_pCurrentAgent);
}

void  MinerStateMachine::ChangeState(State<Miner>* pNewState)
{
	m_pPreviousState = m_pCurrentState;
	m_pCurrentState->Exit(m_pCurrentAgent);
	m_pCurrentState = pNewState;
	m_pCurrentState->Enter(m_pCurrentAgent);
}