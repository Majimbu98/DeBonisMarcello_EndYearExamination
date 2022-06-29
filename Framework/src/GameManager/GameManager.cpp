#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::update(float DeltaTime)
{
	for (GameObject* item : allEntities)
	{
		if (item->is_active && item->tick_enabled()) item->on_update(DeltaTime);
	}
}

