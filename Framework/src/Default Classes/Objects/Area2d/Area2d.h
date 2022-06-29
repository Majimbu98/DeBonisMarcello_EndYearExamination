#pragma once
#include <Default Classes/Objects/GameObject/GameObject.h>
#include <Default Classes/Components/Rect_Transform/RectTransform.h>
#include "Export.h"

/// <summary>
/// Area2D class is a GameObject, rapresented in the screen
/// </summary>
class DECLSPEC Area2D : public GameObject
{
public:
	Area2D();
	~Area2D() override;

	RectTransform* rect_transform;
};

