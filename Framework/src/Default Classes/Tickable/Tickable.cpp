#include "Tickable.h"

bool ITickable::tick_enabled()
{
	return tickable;
}

void ITickable::enable()
{
	tickable = true;
}

void ITickable::disable()
{
	tickable = false;
}
