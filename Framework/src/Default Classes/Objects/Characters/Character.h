#pragma once

#include "Default Classes/Components/ControllerComponent/Controller.h"
#include "Default Classes/Objects/Sprite/Sprite.h"
#include "Default Classes/Components/MovementComponent/MovementComponent.h"

/// <summary>
/// Character class is a Sprite that you can control on the Background scene
/// </summary>
class DECLSPEC Character : public Sprite
{
public:
	Character();
	~Character() override;

protected:
	void on_fixed_update(const float delta_time) override;
	void on_update(const float delta_time) override;

public:
	Controller* controller;
	MovementComponent* movementComponent;
};

