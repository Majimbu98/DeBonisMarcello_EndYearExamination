#include "Window.h"
#include <iostream>

Window::Window(const float Width, const float Height, const char* WindowTitle)
{
	m_Window = new sf::RenderWindow(sf::VideoMode(Width, Height), WindowTitle);
	MaxFPS = 0;
	fpsLimitEnabled = false;
	BackgroundColor=sf::Color::Black;
}

Window::~Window()
{
	delete m_Window;
}

sf::Time Window::getCurrentTime() const
{
	return clock.getElapsedTime();
}

float Window::calculateElapsedTime(float currentTime, float lastTime)
{
	return currentTime - lastTime;
}

unsigned Window::getFrameRate() const
{
	return 1 / DeltaTime;
}

void Window::SetMaxFPS(unsigned int MaxFPS)
{
	this->MaxFPS = MaxFPS;
}

void Window::enableFPSLimit()
{
	fpsLimitEnabled = true;
}

void Window::disableFPSLimit()
{
	fpsLimitEnabled = false;
}

void Window::enableFixedUpdate()
{
	fixedUpdateEnabled = true;
}

void Window::disableFixedUpdate()
{
	fixedUpdateEnabled = false;
}

void Window::setMillisecondsForFixedUpdate(float milliseconds)
{
	msForFixedUpdate = milliseconds;
}

void Window::setBackgroundColor(sf::Color color)
{
	this->BackgroundColor= color;
}

void Window::run()
{
	lastTime = getCurrentTime();
	while (m_Window->isOpen())
	{
		updateGameTime();
		std::cout << "FPS: " << getFrameRate() << std::endl;
		processWindowEvents();
		if (fixedUpdateEnabled)
		{
			while (lag < msForFixedUpdate)
			{
				fixedUpdate();
				lag -= msForFixedUpdate;
			}
		}
		update();
		draw();
		if (fpsLimitEnabled)
		{
			sf::sleep(sf::seconds((1.0f / MaxFPS)));
		}
		
	}
}

void Window::draw()
{
	m_Window->clear(BackgroundColor);

	for each (auto item in GM.allEntities)
	{
		const auto renders = item->get_components<RectTransform>();

		for each (auto rend in renders)
		{
			m_Window->draw(*rend->get_transform());
		}
	}

	m_Window->display();
}

void Window::processWindowEvents()
{
	sf::Event evt{};
	while (this->m_Window->pollEvent(evt))
	{
		if (evt.type == sf::Event::EventType::Closed)
		{
			m_Window->close();
		}
	}
}

void Window::fixedUpdate()
{
	for (auto item : GM.allEntities)
	{
		if (item->is_active && item->tick_enabled()) item->on_fixed_update(DeltaTime);
	}
}

void Window::update()
{
	GM.update(this->DeltaTime);
}

void Window::updateGameTime()
{
	currentTime = getCurrentTime();
	DeltaTime = calculateElapsedTime(currentTime.asSeconds(), lastTime.asSeconds());
	lag += DeltaTime;
	lastTime = currentTime;
}
