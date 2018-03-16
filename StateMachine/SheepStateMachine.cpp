#include "SheepStateMachine.h"


void SheepStateMachine::Update() const
{

	if (m_pCurrentState) m_pCurrentState->Execute(m_pCurrentAgent);

}

void SheepStateMachine::ChangeState(State<Sheep>* pNewState)
{
	m_pPreviousState = m_pCurrentState;
	m_pCurrentState->Exit(m_pCurrentAgent);
	m_pCurrentState = pNewState;
	m_pCurrentState->Enter(m_pCurrentAgent);
}

//bool SheepStateMachine::setNeightBord(const std::vector<Agent*>& neighbors)
//{
//	
//}
