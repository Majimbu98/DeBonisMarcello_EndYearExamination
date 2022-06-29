#pragma once

#include "Export.h"
#include <string>

/// <summary>
/// Object class is the main father class for components and GameObjects
/// </summary>
class DECLSPEC Object
{
public:
	Object(const std::string name, bool is_active = true);

	void activate();
	void deactivate();
	bool has_activity();
	std::string get_name();


protected:
	bool is_active;
	std::string name;
};

