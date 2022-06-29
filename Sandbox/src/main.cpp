#include "GameWindow/Window.h"
#include <string.h>
#include <iostream>
#include "Default Classes/Objects/Characters/Character.h"

int main()
{
	/// <summary>
	/// Write your Window and set his parametres
	/// </summary>
	/// <returns></returns>
	Window* mywindow = new Window(1920, 1080, "Sandbox");
	mywindow->SetMaxFPS(120);
	mywindow->disableFixedUpdate();
	mywindow->enableFPSLimit();

	/// <summary>
	/// Write a background and set his parametres.
	/// </summary>
	/// <returns></returns>
	auto background = new Sprite();
	background->renderer->set_texture_source("Textures/Sala Principale.jpg", true, true);
	background->rect_transform->set_scale(1920, 1080);
	mywindow->GM.allEntities.push_back(background);

	/// <summary>
	/// Write all of your GamesObjects and add all to allEnties
	/// </summary>
	/// <returns></returns>
	Character* Arcon = new Character();
	Arcon->renderer->set_texture_source("Textures/Arcon.png", true, false);
	Arcon->rect_transform->set_scale(64, 64);
	Arcon->rect_transform->set_position(960 - 32, 540 - 32);
	mywindow->GM.allEntities.push_back(Arcon);

	/// <summary>
	/// Execute Game
	/// </summary>
	/// <returns></returns>
	mywindow->run();
	return 0;

}