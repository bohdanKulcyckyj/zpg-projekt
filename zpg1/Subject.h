#pragma once

#include <vector>
#include "Observer.h"

#define PROJECTIONMATRIX 0
#define VIEWMATRIX 1
#define LIGHT 2

class Subject
{
protected:
	std::vector<Observer*> observers;
	virtual void notifyAll(int message) = 0;
public:
	void attach(Observer* o);
};

