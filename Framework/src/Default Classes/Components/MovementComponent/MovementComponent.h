#pragma once

#include "Default Classes/Components/Component.h"
#include "Default Classes/Components/Rect_Transform/RectTransform.h"
#include "Default Classes/Components/ControllerComponent/Controller.h"
#include "Export.h"

/// <summary>
///MovementComponent is a class that you can attach to a GameObject to move it
/// </summary>
class DECLSPEC MovementComponent : public Component
{
public:
	MovementComponent();
	~MovementComponent() override;

	float speed;

	[[nodiscard]] sf::Vector2f get_velocity()const;
	[[nodiscard]] sf::Vector2f get_motion_vector()const;

	[[nodiscard]] bool motion_is_valid()const { return (inputController->forwardMovement || inputController->rightwardMovement); }

	Controller* inputController;
	RectTransform* transform;


	void on_update(const float delta_time) override;


};

