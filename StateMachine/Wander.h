#pragma once

#include "Wolf.h"

class Wolf;
class Wander : State<Wolf>
{

private:
	static Wander* m_pIInstance;

public:
	static State<Wolf>& getIInstance();
	~Wander() {};

private:
	Wander() {};

public:
	void Enter(Wolf*);
	void Execute(Wolf*);
	void Exit(Wolf*);
};
