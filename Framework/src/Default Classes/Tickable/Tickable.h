#pragma once
#include "Export.h"

//Interface of each tickable object/component
class DECLSPEC ITickable
{
public:
	bool tick_enabled();
	void enable();
	void disable();

protected:
	virtual void on_update(const float delta_time) = 0;
	virtual void on_fixed_update(const float delta_time) = 0;

private:
	bool tickable = true;
};