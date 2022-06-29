#pragma once
#include <SFML/Graphics.hpp>
#include "Default Classes/Components/Component.h"




/// <summary>
///Controller is a class that you can attach to a GameObject to control it
/// </summary>
class DECLSPEC Controller : public Component
{
	friend class GameManager;
	friend class MovementComponent;
public:
	Controller();
	~Controller() override;

	[[nodiscard]] sf::Vector2f get_axis_vector()const { return { XAxis, YAxis }; }

protected:
	void on_update(const float delta_time) override;
	void on_fixed_update(const float delta_time) override;

private:
	bool forwardMovement;
	bool rightwardMovement;
	float XAxis, YAxis;
};
