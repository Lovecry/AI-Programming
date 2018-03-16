#include "Graphic.h"

void Graphic::Initialize() {
	
	if (!font.loadFromFile("../StateMachine/Fonts/arial.ttf"))
	{
		std::cout << "ERROR: Font Not Found!";
	}
	else
	{
		textIdle.setFont(font);
		textWalk.setFont(font);
		textMining.setFont(font);
		textCurrentState.setFont(font);
	}

	textIdle.setString("Miner in Idle");
	textIdle.setCharacterSize(24);
	textIdle.setFillColor(color.White);
	textIdle.setPosition(50, 5);
	circleIdle.setRadius(20.f);
	circleIdle.setFillColor(color.Green);
	circleIdle.setPosition(0, 0);

	textWalk.setString("Miner Walking");
	textWalk.setCharacterSize(24);
	textWalk.setFillColor(color.White);
	textWalk.setPosition(50, 50);
	circleWalk.setRadius(20.f);
	circleWalk.setFillColor(color.Yellow);
	circleWalk.setPosition(0, 45);

	textMining.setString("Miner Mining");
	textMining.setCharacterSize(24);
	textMining.setFillColor(color.White);
	textMining.setPosition(50, 95);
	circleMining.setRadius(20.f);
	circleMining.setFillColor(color.Red);
	circleMining.setPosition(0, 90);

	textCurrentState.setString("Current State");
	textCurrentState.setCharacterSize(24);
	textCurrentState.setFillColor(color.White);
	textCurrentState.setPosition(80, 140);
	circleCurrentState.setRadius(130.f);
	circleCurrentState.setFillColor(color.White);
	circleCurrentState.setPosition(30, 180);

	window.create(sf::VideoMode(320, 450), "FSM Miner at Work!");
}

void Graphic::Draw(location_type location) {
	
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	switch (location){
		case home: circleCurrentState.setFillColor(color.Green); break;
		case walking: circleCurrentState.setFillColor(color.Yellow); break;
		case mine: circleCurrentState.setFillColor(color.Red); break;
		default: circleCurrentState.setFillColor(color.White); break;
	}
			
	window.clear();
	window.draw(circleIdle);
	window.draw(textIdle);
	window.draw(circleWalk);
	window.draw(textWalk);
	window.draw(circleMining);
	window.draw(textMining);
	window.draw(textCurrentState);
	window.draw(circleCurrentState);
	window.display();
	
}