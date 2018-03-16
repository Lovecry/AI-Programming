#include "Walk.h"

Walk* Walk::m_pWInstance = nullptr;

State<Miner>& Walk::getWInstance()
{
	static Walk theInstance;
	m_pWInstance = &theInstance;
	return *m_pWInstance;
};

void Walk::Enter(Miner* miner){
	std::cout << "WALKING START" << std::endl;
	//miner->resetKlm();
	miner->setFromLocation(miner->getLocation());
	miner->setLocation(walking);
	
	//la faccio nella exit 
	/*if (miner->getFromLocation() == home)
	{
		miner->getSteeringBehavior()->SetTarget(positionMine);
	}
	else
	{
		miner->getSteeringBehavior()->SetTarget(positionHome);
	}*/
	//miner->getSteeringBehavior()->SeekOn();
	miner->getSteeringBehavior()->ArriveOn();
}

void Walk::Execute(Miner* miner){
	//miner->decreaseKlm();
	
	SMnamespace::Vector2 distToTarget = miner->getSteeringBehavior()->GetTarget() - miner->getPosition();
	float distance = distToTarget.Length();

	//std::cout
	//	<< "distance : " << distance
	//	//<< "KM : " << miner->getKlm()
	//	<< "  Pos : " << miner->getPosition().x << " , " << miner->getPosition().y
	//	<< "  Vel : " << miner->getVelocity().x << " , " << miner->getVelocity().y
	//	<< "  Acc : " << miner->getAcceleration().x << " , " << miner->getAcceleration().y
	//	<< std::endl;

	if (distance <= 1) { 
		if (miner->getFromLocation() == home)
		{
			miner->getStateMachine()->ChangeState(&Mining::getMInstance());
		}
		else
		{
			miner->getStateMachine()->ChangeState(&Idle::getIInstance());
		}
	}


		//switch (miner->getPosition())
		//{
		//case : miner->getStateMachine()->ChangeState(&Mining::getMInstance()); break;
		//case : miner->getStateMachine()->ChangeState(&Idle::getIInstance()); break;
		//default:
		//	break;
		//}
	
}

void Walk::Exit(Miner* miner){
	std::cout << "WALKING END" << std::endl;
	//miner->getSteeringBehavior()->SeekOff();
	miner->getSteeringBehavior()->ArriveOff();
}

