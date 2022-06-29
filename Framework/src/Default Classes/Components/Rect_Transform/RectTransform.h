#pragma once

#include <Default Classes/Components/Component.h>
#include <SFML/Graphics.hpp>
#include "Export.h"

/// <summary>
///RectTransform is a class that rappresent a GameObject in the scene
/// </summary>
class DECLSPEC RectTransform : public Component
{

public:
	RectTransform();
	explicit RectTransform(
		sf::Vector2f position,
		float rotation,
		sf::Vector2f scale);
	~RectTransform() override;

	/**
	 * \brief set area position in world space
	 * \param x horizontal position
	 * \param y vertical position
	 */
	void set_position(float x, float y) const;

	/**
	 * \brief set area rotation in world space
	 * \param angle the rotation angle in degrees
	 */
	void set_rotation(float angle) const;

	/**
	 * \brief set size in pixel for this area in world space
	 * \param x number of pixel on X
	 * \param y number of pixel on Y
	 */
	void set_scale(float x, float y) const;

	/**
	 * \brief get the transform data
	 * \return area transform
	 */
	[[nodiscard]] sf::RectangleShape* get_transform()const;

private:
	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;

	sf::RectangleShape* transform;
};


