#pragma once
#include "Default Classes/Objects/Object.h"
#include "Default Classes/Tickable/Tickable.h"
#include "Default Classes/Objects/GameObject/GameObject.h"
#include "Export.h"

/// <summary>
/// Component class is a generic class you can attach to a GameObject
/// </summary>
class DECLSPEC Component : public Object, public ITickable
{
	friend class GameObject;
public:
	Component(const std::string name, const bool is_active = true) : Object(name, is_active) {}
	virtual ~Component() = default;
	[[nodiscard]] GameObject* get_owner()const { return owner; }

protected:
	virtual void on_update(const float delta_time) override;
	virtual void on_fixed_update(const float delta_time) override;

private:
	GameObject* owner = nullptr;
};

