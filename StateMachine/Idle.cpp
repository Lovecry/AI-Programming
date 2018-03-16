#include "Idle.h"

Idle* Idle::m_pIInstance = nullptr;

State<Miner>& Idle::getIInstance()
{
	static Idle theInstance;
	m_pIInstance = &theInstance;
	return *m_pIInstance;
};

void Idle::Enter(Miner* miner){
	std::cout << "Entering HOME" << std::endl;
	miner->setLocation(home);
}

void Idle::Execute(Miner* miner){
	miner->increaseStamina();
	//std::cout << "STUP : " << miner->getStamina() << std::endl;
	if (miner->getStamina() >= max_stamina) { 
		miner->getStateMachine()->ChangeState((State<Miner>*)&Walk::getWInstance());
	}
}

void Idle::Exit(Miner* miner){
	std::cout << "Leaving HOME" << std::endl;
	miner->getSteeringBehavior()->SetTarget(positionMine);

}

