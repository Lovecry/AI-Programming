#pragma once
#include "State.h"
#include "Miner.h"

class Miner;
class Walk : State<Miner> {

private:
	static Walk* m_pWInstance;

public:
	static State<Miner>& getWInstance();
	~Walk() {};

private :
	Walk(){};

public:
	void Enter(Miner*);
	void Execute(Miner*);
	void Exit(Miner*);
};
