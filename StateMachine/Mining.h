#pragma once
#include "State.h"
#include "Miner.h"

class Miner;
class Mining : State<Miner> {

private:
	static Mining* m_pMInstance;

public:
	static State<Miner>& getMInstance();
	~Mining() {};

private:
	Mining(){};

public:
	void Enter(Miner*);
	void Execute(Miner*);
	void Exit(Miner*);
};
