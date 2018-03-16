#include "Wander.h"


Wander* Wander::m_pIInstance = nullptr;

State<Wolf>& Wander::getIInstance()
{
	static Wander theInstance;
	m_pIInstance = &theInstance;
	return *m_pIInstance;
};

void Wander::Enter(Wolf* wolf){
	std::cout << "Entering Wander Wolf" << std::endl;
	wolf->getSteeringBehavior()->WanderOn();

}

void Wander::Execute(Wolf* wolf){
	
	float distance = wolf->getPosition().Distance( enclosureCenter);
	
	if (distance > radiusEnclosure && distance < LimitDistanceWolf){
		wolf->getSteeringBehavior()->FleeOff();
		wolf->getSteeringBehavior()->SeekOff();
		wolf->getSteeringBehavior()->WanderOn();

	}
	else{
		wolf->getSteeringBehavior()->WanderOff();
		if (distance <= radiusEnclosure)
		{
			wolf->getSteeringBehavior()->SetTarget(enclosureCenter );
			wolf->getSteeringBehavior()->FleeOn();

		}
		else{
			wolf->getSteeringBehavior()->SetTarget(enclosureCenter);
			wolf->getSteeringBehavior()->SeekOn();
		}
		
	}

}

void Wander::Exit(Wolf* wolf){
	std::cout << "Exit Wander Wolf" << std::endl;
	wolf->getSteeringBehavior()->WanderOff();

}

