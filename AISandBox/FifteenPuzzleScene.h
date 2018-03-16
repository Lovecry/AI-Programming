#pragma once

#include "IScene.h"
#include <algorithm>
#include <sstream>
#include "FontManager.h"

#include "../AIProgramming/AStar.h"
#include "Graphics.h"

class FifteenPuzzleScene : public IScene
{
    
public:

	FifteenPuzzleScene();

    virtual void OnIdle();
    virtual void OnDraw(sf::RenderWindow&);

	virtual ~FifteenPuzzleScene();

private:
	ASnamespace::AStar algorithm;
	std::vector<ASnamespace::Node> result;
	ASnamespace::Graphics graphic;
};