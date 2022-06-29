#ifndef WINDOW_H
#define WINDOW_H

#include "Export.h"
#include <SFML/Graphics.hpp>
#include "GameManager/GameManager.h"
#include "Default Classes/Objects/GameObject/GameObject.h"
#include "Default Classes/Components/Rect_Transform/RectTransform.h"

/// <summary>
/// Class that manage window of the game
/// </summary>
class DECLSPEC Window
{
public:
	Window(const float Width, const float Height, const char* WindowTitle);
	~Window();


	sf::Time getCurrentTime()const;
	float calculateElapsedTime(float currentTime, float lastTime);

	unsigned getFrameRate()const;
	void SetMaxFPS(unsigned int MaxFPS);
	void enableFPSLimit();
	void disableFPSLimit();
	void enableFixedUpdate();
	void disableFixedUpdate();
	void setMillisecondsForFixedUpdate(float milliseconds);
	void setBackgroundColor(sf::Color color);
	void run();
private:
	void draw();
	void processWindowEvents();
	void fixedUpdate();
	void update();
	void updateGameTime();

public:

	GameManager GM;

private:
	sf::RenderWindow* m_Window;
	unsigned MaxFPS;
	bool fpsLimitEnabled;
	bool fixedUpdateEnabled;

	sf::Clock clock;
	sf::Time lastTime, currentTime;
	float DeltaTime;
	float lag;

	float msForFixedUpdate;
	sf::Color BackgroundColor;

};

#endif