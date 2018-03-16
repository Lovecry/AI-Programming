#include "WolfStateMachine.h"

void WolfStateMachine::Update() const
{

	if (m_pCurrentState) m_pCurrentState->Execute(m_pCurrentAgent);

}

void WolfStateMachine::ChangeState(State<Wolf>* pNewState)
{
	m_pPreviousState = m_pCurrentState;
	m_pCurrentState->Exit(m_pCurrentAgent);
	m_pCurrentState = pNewState;
	m_pCurrentState->Enter(m_pCurrentAgent);
}
