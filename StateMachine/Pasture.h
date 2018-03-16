#pragma once
#include "State.h"
#include "Sheep.h"
#include "Walk.h"
#include "Wolf.h"

class Sheep;
class Pasture : State < Sheep > {

private:
	static Pasture* m_pIInstance;

public:
	static State<Sheep>& getIInstance();
	~Pasture() {};

private:
	Pasture() {};

public:
	void Enter(Sheep*);
	void Execute(Sheep*);
	void Exit(Sheep*);
};
