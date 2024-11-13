#include "Subject.h"

void Subject::attach(Observer* o)
{
	observers.push_back(o);
}

void Subject::notifyAll(int message) {
	for (auto o : observers) {
		o->update(message);
	}
}