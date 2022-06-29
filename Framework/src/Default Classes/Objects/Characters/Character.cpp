#include "Character.h"

Character::Character() : Sprite()
{
	
	controller = new Controller();
	add_component(controller);

	movementComponent = new MovementComponent();
	movementComponent->inputController = controller;
	movementComponent->transform = rect_transform;
	movementComponent->speed = 120.0f;
	add_component(movementComponent);

}

Character::~Character()
{
	delete movementComponent;
	delete controller;
}

void Character::on_fixed_update(const float delta_time)
{
	Sprite::on_fixed_update(delta_time);
}

void Character::on_update(const float delta_time)
{
	Sprite::on_update(delta_time);
}
