#ifndef STEERINGBEHAVIORS_H
#define STEERINGBEHAVIORS_H

#include <vector>
#include <time.h>
#include <math.h> 
#include "Agent.h"
#include "Vector2.h"

class Agent;
class Place;
class SteeringBehaviors
{

public:
	SteeringBehaviors(Agent* bp) : m_agent(bp)	{ m_iFlags = 0; };

	~SteeringBehaviors() {};

	SMnamespace::Vector2 GetTarget()const{ return m_target; }
	
	void SetTarget(const SMnamespace::Vector2 target) { m_target = target; }
	void SetEvader(Agent* evader) { m_evader = evader; }

	void SetNeighbors(std::vector<Agent*> nNeighbors) { m_neighbors = nNeighbors; }
	void SetObstacles(std::vector<Place*> nObstacles) { m_obstacles = nObstacles; }

	SMnamespace::Vector2 GetForce()const { return m_steering; }

	void Calculate();

	inline void SeekOn()				{ m_iFlags |= seek; }
	inline void ArriveOn()				{ m_iFlags |= arrive; }

	inline void FleeOn()				{ m_iFlags |= flee; }
	inline void PursuitOn()				{ m_iFlags |= pursuit; }
	inline void EvadeOn()				{ m_iFlags |= evade; }
	inline void WanderOn()				{ m_iFlags |= wander; }

	//TO DO: not implement
	inline void ObstacleAvoidanceOn()	{ m_iFlags |= obstaclesAvoidance; }
	inline void WallAvoidanceOn()		{ m_iFlags |= wallAvoidance; }
	inline void InterposeOn()			{ m_iFlags |= interpose; }
	
	inline void SeparationOn()			{ m_iFlags |= separation; }
	inline void CohesionOn()			{ m_iFlags |= cohesion; }
	inline void AlignmentOn()			{ m_iFlags |= alignment; }

	inline void SeekOff()				{ if(SeekIsOn()) m_iFlags ^= seek; }
	inline void ArriveOff()				{ if(ArriveIsOn()) m_iFlags ^= arrive; }
	inline void FleeOff()				{ if(FleeIsOn()) m_iFlags ^= flee; }
	inline void PursuitOff()			{ if(PursuitIsOn()) m_iFlags ^= pursuit; }
	inline void EvadeOff()				{ if(EvadeIsOn()) m_iFlags ^= evade; }
	inline void WanderOff()				{ if(WanderIsOn()) m_iFlags ^= wander; }
	inline void ObstacleAvoidanceOff()	{ if(ObstacleAvoidanceIsOn()) m_iFlags ^= obstaclesAvoidance; }
	inline void WallAvoidanceOff()		{ if(WallAvoidanceIsOn()) m_iFlags ^= wallAvoidance; }
	inline void InterposeOff()			{ if(InterposeIsOn()) m_iFlags ^= interpose; }
	inline void SeparationOff()			{ if(SeparationIsOn()) m_iFlags ^= separation; }
	inline void CohesionOff()			{ if(CohesionIsOn()) m_iFlags ^= cohesion; }
	inline void AlignmentOff()			{ if(AlignmentIsOn()) m_iFlags ^= alignment; }

	inline bool SeekIsOn()				{ return On(seek); }
	inline bool ArriveIsOn()			{ return On(arrive); }
	inline bool FleeIsOn()				{ return On(flee); }
	inline bool PursuitIsOn()			{ return On(pursuit); }
	inline bool EvadeIsOn()				{ return On(evade); }
	inline bool WanderIsOn()			{ return On(wander); }
	inline bool ObstacleAvoidanceIsOn()	{ return On(obstaclesAvoidance); }
	inline bool WallAvoidanceIsOn()		{ return On(wallAvoidance); }
	inline bool InterposeIsOn()			{ return On(interpose); }
	inline bool SeparationIsOn()		{ return On(separation); }
	inline bool CohesionIsOn()			{ return On(cohesion); }
	inline bool AlignmentIsOn()			{ return On(alignment); }

private:
	
	Agent*					m_agent;
	Agent*					m_evader;

	std::vector<Agent*>		m_neighbors;
	std::vector<Place*>		m_obstacles;

	SMnamespace::Vector2	m_steering;
	SMnamespace::Vector2	m_target;

	const float distanceFromAnotherAgent = 35;

	float			m_thetaValue;

	int				m_iFlags;

	enum Behaviors
	{
		none				= 0x0000,
		seek				= 0x0001,
		arrive				= 0x0002,
		flee				= 0x0004,
		pursuit				= 0x0008,
		evade				= 0x0010,
		wander				= 0x0020,
		obstaclesAvoidance	= 0x0040,
		wallAvoidance		= 0x0080,
		interpose			= 0x0100,
		separation			= 0x0200,
		cohesion			= 0x0400,
		alignment			= 0x0800,

	};

	bool	On(Behaviors bt){return ((m_iFlags & bt) == bt);}

	void SumForces();

	SMnamespace::Vector2 Seek(const SMnamespace::Vector2& target);
	SMnamespace::Vector2 Flee(const SMnamespace::Vector2& target);
	SMnamespace::Vector2 Arrive(const SMnamespace::Vector2& target);
	SMnamespace::Vector2 Pursuit(const Agent* target);
	SMnamespace::Vector2 Evade(const Agent* target);
	SMnamespace::Vector2 Wander();	
	SMnamespace::Vector2 ObstacleAvoidance();
	SMnamespace::Vector2 WallAvoidance(const SMnamespace::Vector2& target);
	SMnamespace::Vector2 Interpose(const SMnamespace::Vector2& target);

	//group
	SMnamespace::Vector2 Separation(const std::vector<Agent*>& neighbors);
	SMnamespace::Vector2 Cohesion(const std::vector<Agent*>& neighbors);
	SMnamespace::Vector2 Alignment(const std::vector<Agent*>& neighbors);

	void setAngle(SMnamespace::Vector2 &vect, float angle);

};

#endif