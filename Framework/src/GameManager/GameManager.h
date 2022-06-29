#pragma once
#include <SFML/System.hpp>
#include "Default Classes/Objects/GameObject/GameObject.h"
#include "Export.h"

/// <summary>
/// The class that manages Gameloop and all the game
/// </summary>
class DECLSPEC GameManager
{
public:
	GameManager();
	~GameManager();
	
public:
	void update(float DeltaTime);
	std::vector<GameObject*> allEntities;
};

