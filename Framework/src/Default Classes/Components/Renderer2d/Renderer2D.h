#pragma once
#include "Default Classes/Components/Component.h"
#include "SFML/Graphics.hpp"
#include "Default Classes/Objects/Area2d/Area2d.h"

/// <summary>
///Renderer2D is a component that rederize from a source, an image
/// </summary>
class DECLSPEC Renderer2D : public Component
{
public:
	Renderer2D();
	explicit Renderer2D(std::string source_path, bool smooth, bool repeat);
	~Renderer2D() override;

	void set_texture_source(std::string source_path, bool smooth, bool repeat);

private:
	sf::Texture* source;
};
