#include <iostream>
#include "Application.h"
#include <SFML\Graphics.hpp>

int main(int, char const**)
{
	Application* game = Application::Istance();
	
	game->Init(false);
	
	game->Run();
	
	game->Destroy();
	
	exit(0);
}