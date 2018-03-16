#include "FifteenPuzzleScene.h"
#include "Application.h"

FifteenPuzzleScene::FifteenPuzzleScene()
{
	
	algorithm.Setup();
	graphic.Initialize(result);
}

FifteenPuzzleScene::~FifteenPuzzleScene()
{
    
}

void FifteenPuzzleScene::OnIdle()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		Application::Istance()->SetScene(SceneEnum::Scene_MainMenu);
		
	}
}

void FifteenPuzzleScene::OnDraw(sf::RenderWindow& renderWindow)
{
	algorithm.Run(result);
	graphic.Draw(result);
}