#pragma once
#include "State.h"
#include "Miner.h"
#include "Walk.h"
#include "Wolf.h"

class Miner;
class Idle : State<Miner>{

private:
	static Idle* m_pIInstance;

public:
	static State<Miner>& getIInstance();
	~Idle() {};

private:
	Idle() {};

public:
	void Enter(Miner*);
	void Execute(Miner*);
	void Exit(Miner*);
};
