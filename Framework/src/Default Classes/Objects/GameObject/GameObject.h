#pragma once

#include <string>
#include <vector>

#include "Default Classes/Components/Component.h"
#include "Default Classes/Objects/Object.h"
#include "Default Classes/Tickable/Tickable.h"
#include "Export.h"

class Component;

/// <summary>
/// Every object in the game will ereditate by this class
/// </summary>
class DECLSPEC GameObject : public Object, public ITickable
{
	friend class Window;
	friend class GameManager;
public:
	GameObject(const std::string name, const bool is_active = true);
	GameObject(const std::string name, const std::vector<Component*> components, const bool is_active = true);
	virtual ~GameObject() = default;

	/// <summary>
	/// add component to this game object
	/// </summary>
	/// <param name="component">the component to add</param>
	void add_component(Component* component);

	/// <summary>
	/// Get the first components of the given type from the attached components
	/// </summary>
	/// <typeparam name="T">the component to add</typeparam>
	/// <returns></returns>
	template<class T, class = Component>  T* get_component()const {

		if (components.size() == 0) return nullptr;

		for (Component* item : components)
		{
			const auto val = dynamic_cast<T*>(item);
			if (!val) continue;

			return val;
		}

		return nullptr;
	}

	
	template<class T> std::vector<T*> get_components()const
	{
		std::vector<T*> result;

		if (components.size() == 0) return result;

		for each (Component * component in this->components)
		{
			const auto val = dynamic_cast<T*>(component);
			if (!val) continue;

			result.push_back(val);
		}

		return result;
	}

protected:
	virtual void on_fixed_update(const float delta_time) override;

	virtual void on_update(const float delta_time) override;

private:
	std::vector<Component*> components;

};

