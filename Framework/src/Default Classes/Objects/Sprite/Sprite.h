#pragma once
#include "Default Classes/Objects/Area2d/Area2d.h"
#include "Default Classes/Components/Renderer2d/renderer2d.h"

/// <summary>
/// Sprite class is a class that ereditate from Area2D 
/// </summary>
class DECLSPEC Sprite : public Area2D
{
public:

	Sprite();
	~Sprite() override;

	Renderer2D* renderer;
};
