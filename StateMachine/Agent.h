#pragma once

#include "State.h"
#include "Vector2.h"

enum type : int
{
	GNOME,
	DOG,
	SHEEP
};

static SMnamespace::Vector2 enclosureCenter(300.0f, 350);
static float radiusEnclosure = 100;
static float LimitDistanceWolf = 200;

class Agent 
{

public:
	virtual ~Agent() {};
	virtual void Update(){};

	SMnamespace::Vector2 getPosition() const { return m_vPosition; }
	void setPosition(SMnamespace::Vector2 val) { m_vPosition = val; }
	void setPosition(float x, float y) {
		m_vPosition.x = x;
		m_vPosition.y = y;
	}

	float getMaxVelocity() const { return m_fMaxVelocity; }
	void setMaxVelocity(float val) { m_fMaxVelocity = val; }

	SMnamespace::Vector2 getVelocity() const { return m_vVelocity; }
	void setVelocity(SMnamespace::Vector2 val) { m_vVelocity = val; }

	float getCircleDistance() const { return m_fCircleDistance; }
	void setCircleDistance(float val) { m_fCircleDistance = val; }

	float getCircleRadius() const { return m_fCircleRadius; }
	void setCircleRadius(float val) { m_fCircleRadius = val; }

	float getAngleChange() const { return m_fAngleChange; }
	void setAngleChange(float val) { m_fAngleChange = val; }

	SMnamespace::Vector2 getAcceleration() const { return m_vAcceleration; }
	void setAcceleration(SMnamespace::Vector2 val) { m_vAcceleration = val; }

	int GetAgentType() const { return m_eAgentType; };

protected:
	SMnamespace::Vector2 m_vPosition;
	SMnamespace::Vector2 m_vVelocity;
	SMnamespace::Vector2 m_vAcceleration;
	float m_fCircleDistance;
	float m_fCircleRadius;
	float m_fAngleChange;
	float m_fMaxVelocity;
	type m_eAgentType;
};