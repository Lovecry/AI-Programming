#pragma once
#include "Agent.h"

template <class T>
class StateMachine {

public:

	virtual ~StateMachine() {};

	virtual void SetCurrentState(State<T>* s) = 0;
	virtual State<T>* GetCurrentState() const = 0;

	virtual void SetPreviousState(State<T>* s) = 0;
	virtual State<T>* GetPreviousState() const = 0;

	virtual void  Update() const = 0;

	virtual void  ChangeState(State<T>* pNewState) = 0;

	virtual void  RevertToPreviousState() = 0;

	virtual bool  isInState(const State<T>& st) const = 0;
};