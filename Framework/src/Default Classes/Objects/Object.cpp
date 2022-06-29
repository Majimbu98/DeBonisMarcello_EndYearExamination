#include "Object.h"

Object::Object(const std::string name, bool is_active)
{
	this->name = name;
	this->is_active = is_active;
}

void Object::activate()
{
	is_active = true;
}

void Object::deactivate()
{
	is_active = false;
}

bool Object::has_activity()
{
	return is_active;
}

std::string Object::get_name()
{
	return std::string();
}
